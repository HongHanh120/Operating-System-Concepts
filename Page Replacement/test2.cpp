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
    int timestamp[capacity];
    bool found = false;
    // int count = 0;

    for (int i = 0; i < capacity; i++){
        frames[i] = -1;
        timestamp[i] = 0;
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
            found = false;
            page_faults++;
            if(position < capacity){
                frames[position] = pages[i];
                timestamp[position] = 0;
                position++;
                // break; 
            }
            else {
                int temp;
                for (int j = 0; j < capacity; j++){
                    // cout << timestamp[j] << "  ";
                    if (timestamp[j] > capacity){
                        found = true;
                        temp = j;
                        // break;
                    }
                }
                if(found){
                    frames[temp] = pages[i];
                    timestamp[temp] = 0;
                }
                else {
                    position = position % capacity;
                    if(rf_bit[frames[position]] == 0){
                        frames[position] = pages[i];
                        timestamp[position] = 0;
                    }
                    else {
                        while(rf_bit[frames[position]] == 1){
                            rf_bit[frames[position]] = 0;
                            position = (position + 1) % capacity;
                        }
                        frames[position] = pages[i];
                        timestamp[position] = 0;
                    }
                    position = (position + 1) % capacity;
                }
                
            }
            for (int j = 0; j < capacity; j++){
                if(frames[j] != -1)
                    cout << frames[j] << "   ";
            }
            
            // cout << position;
        }
        // for (int j = 0; j < capacity; j++){
        //         if(frames[j] != -1)
        //             cout << rf_bit[frames[j]] << "   ";
        //     }
        for (int j = 0; j < capacity; j++){
            if(rf_bit[frames[j]] != 1 && frames[j] != -1)
                timestamp[j]++;
            // cout << timestamp[j] << "   ";
        }
        cout << "\n";
    }
    cout << "The no of page faults is: " << page_faults << "\n";
    return 0;
}