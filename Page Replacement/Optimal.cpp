#include<iostream>
using namespace std;

int main(){
    int pages[] = {3, 2, 4, 1, 0, 2, 0, 1, 3, 5, 4, 2, 3};
    int n = sizeof(pages)/sizeof(pages[0]);
    int capacity = 3;

    int interval[n];
    int page_faults = 0;
    int frames[capacity];
    int position, maximum_interval, previous_frame = -1;
    bool flag = true;
    bool found;

    for (int i = 0; i < capacity; i++){
        frames[i] = -1;
    }

    for (int i = 0; i < n; i++){
        cout << pages[i] << "          ";
        flag = false;
        for (int j = 0; j < capacity; j++){
            if(frames[j] == pages[i]){
                flag = true;
                break;
            }
        }

        if(!flag){
            if (previous_frame == capacity - 1){
                for (int j = 0; j < capacity; j++){
                    for (int k = i + 1; k < n; k++){
                        interval[j] = 0;
                        if (frames[j] == pages[k]){
                            interval[j] = k - i;
                            break;
                        }
                    }
                }
                found = false;
                for (int j = 0; j < capacity; j++){
                    if(interval[j] == 0){
                        position = j;
                        found = true;
                        break;
                    }
                }
            }
            else {
                position = ++previous_frame;
                found = true;
            }
            if(!found){
                maximum_interval = interval[0];
                position = 0;
                for(int j = 1; j < capacity; j++){
                    if(maximum_interval < interval[j]){
                        maximum_interval = interval[j];
                        position = j;
                    }
                }
            }
            frames[position] = pages[i];
            page_faults++;
            
            for (int j = 0; j < capacity; j++){
            if(frames[j] != -1)
                cout << frames[j] << "      ";
        }
        }
        cout << "\n";
    }
    cout << "The no of page faults is: " << page_faults;
    return 0;
}