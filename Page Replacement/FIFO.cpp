#include<iostream>
using namespace std;

int main (){
    int pages[] = {3, 2, 4, 1, 0, 2, 0, 1, 3, 5, 4, 2, 3};
    int n = sizeof(pages)/sizeof(pages[0]);
    int capacity = 3;

    int available = 0;
    int counter = 0;

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
        available = 0;

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

            else{
                for (int k = 0; k < capacity; k++){
                    if (frames[k] == pages[i])
                        available = 1;
                }
                if(available == 0){
                    frames[counter] = pages[i];
                    counter = (counter + 1) % capacity;
                    for (int k = 0; k < capacity; k++)
                        cout << frames[k] << "   ";
                }
            }
        }
        cout << "\n";
    }
    cout << "The no of page faults is: " << page_faults;
    return 0;
}