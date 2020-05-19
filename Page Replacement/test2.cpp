#include <iostream>
using namespace std;

int main (){
    int pages[] = {3, 2, 4, 1, 0, 2, 0, 1, 3, 5, 4, 2, 3};
    int n = sizeof(pages)/sizeof(pages[0]);
    int capacity = 3;
    int rf_bit[6] = {0, 1, 0, 1, 0, 0};

    int page_faults = 0;
    int frames[capacity];
    int position = 0;
    bool flag = true;
    // int count = 0;

    for (int i = 0; i < capacity; i++){
        frames[i] = -1;
    }

    for (int i = 0; i < n; i++){
        cout << pages[i] << "          ";
        flag = true;

        for(int j = 0; j < capacity; j++){
            if(frames[j] == pages[i]){
                flag = false;
                break;
            }
        }
        
        if(flag){
            page_faults++;
            if(position < capacity){
                frames[position] = pages[i];
                position++;
                // break; 
            }
            else {
                position = position % capacity;
                if(rf_bit[frames[position]] == 0)
                    frames[position] = pages[i];
                else {
                    while(rf_bit[frames[position]] == 1){
                        rf_bit[frames[position]] = 0;
                        position = (position + 1) % capacity;
                    }
                    frames[position] = pages[i];
                }
                position = (position + 1) % capacity;
                
            }
            for (int j = 0; j < capacity; j++){
                if(frames[j] != -1)
                    cout << frames[j] << "   ";
            }
            cout << position;
        }
        cout << "\n";
    }
    cout << "The no of page faults is: " << page_faults << "\n";
    return 0;
}