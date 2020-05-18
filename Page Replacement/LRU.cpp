#include<iostream>
using namespace std;

int main (){
    int pages[] = {3, 2, 4, 1, 0, 2, 0, 1, 3, 5, 4, 2, 3};
    int n = sizeof(pages)/sizeof(pages[0]);
    int capacity = 3;

    int long_appearance[capacity];
    int buffer[capacity];

    int page_faults = 0;
    int frames[capacity];
    int position = 0;
    frames[position] = pages[position];
    cout << pages[position] << "          ";
    cout << frames[position];
    page_faults++;
    position++;
 
    for(int i = 0; i < n; i++){
        if(i != 0)
            cout << pages[i] << "          ";
        int check_page_faults = 0;
        for(int j = 0; j < capacity; j++){
            if(pages[i] != frames[j])
            check_page_faults++;
        }

        if(check_page_faults == capacity){
            page_faults++;
            if(position < capacity){
                frames[position] = pages[i];
                position++;
                for(int j = 0; j < position; j++)
                    cout << frames[j] << "   ";
            }

            else {
                for (int k = 0; k < capacity; k++){
                    long_appearance[k] = 0;
                    for (int j = i - 1; j < n; j--){
                        if (frames[k] != pages[j])
                            long_appearance[k]++;
                        else 
                            break;
                    }
                }

                for (int k = 0; k < capacity; k++){
                    buffer[k] = long_appearance[k];
                }

                for (int k = 0; k < capacity; k++){
                    for (int j = k; j < capacity; j++){
                        if (buffer[k] < buffer[j]){
                            int temp = buffer[k];
                            buffer[k] = buffer[j];
                            buffer[j] = temp;
                        }
                    }
                }

                for (int k = 0; k < capacity; k++){
                    if(long_appearance[k] == buffer[0])
                        frames[k] = pages[i];
                    cout << frames[k] << "   ";
                }
            }
        }
        cout << "\n";
    }
    cout << "The no of page faults is: " << page_faults;
    return 0;
}