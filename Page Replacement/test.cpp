#include<iostream>
using namespace std;

int main (){
    int pages[] = {3, 2, 4, 1, 0, 2, 0, 1, 3, 5, 4, 2, 3};
    int n = sizeof(pages)/sizeof(pages[0]);
    int capacity = 3;

    int freq[capacity];
    int counter[10];
    int appear[10];
    int max = -1;
    int count = 0;
    int temp;
    int frame;

    int page_faults = 0;
    int frames[capacity];
    int position = 0;
    bool flag = true;

    for(int i = 0; i < capacity; i++){
        // freq[i] = -1;
        frames[i] = -1;
    }

    for(int i = 0; i < 10; i++){
        counter[i] = 0;
        freq[i] = 0;
        appear[i] = 0;
    }
 
    for(int i = 0; i < n; i++){
        cout << pages[i] << "          ";
        counter[pages[i]]++;
        appear[pages[i]]++;
        // freq[pages[i]] = i;
        flag = true;
        // frame = frames[0];

        for(int j = 0; j < capacity; j++){
            if(frames[j] == pages[i]){
                flag = false;
                break;
            }

            // if(counter[frame] > counter[frames[j]])
            //     frame = frames[j];
        }

        if(flag){
            page_faults++;
            if (i < capacity)
                frames[i] = pages[i];
            else {
                for (int j = 0; j < capacity; j++){
                    freq[j] = counter[frames[j]];                  // cout << frames[j] << "  ";
                }

                max = freq[0];
                frame = frames[0];
                int max_appear = appear[0];
                for (int j = 0; j < capacity; j++){
                    if(freq[j] > max && appear[frames[j]] > appear[frame]){
                        max = freq[j];
                        frame = frames[j];
                    }
                }
                for (int j = 0; j < capacity; j++){
                    if(freq[j] == max && appear[frames[j]] == appear[frame]){
                        count++;
                    }
                }    
                // cout << count<< "  ";
                if(count == capacity || count == 0){
                   
                        // for (int k = j; k < capacity; k++){
                        //     if (appear[frames[j]] > appear[frames[k]]){
                        //         frames[j] = pages[i];
                        //         counter[frames[j]] = 0;
                        //         break;
                        //     }
                        // }
                  temp = frames[position];
                  counter[temp] = 0;
                  frames[position] = pages[i];
                  position = (position + 1) % capacity;
                }
                else if (count < capacity && count > 1){
                    for (int j = 0; j < capacity; j++){
                        if (freq[j] == max){
                            if (j > position){
                              while(position < j){
                                position++;
                              }
                              temp = frames[position];
                              counter[temp] = 0;
                              frames[position] = pages[i];
                              position = (position + 1) % capacity;
                              break;
                            }
                        }
                    }
                }
                else {
                    for (int j = 0; j < capacity; j++){
                        if(freq[j] == max){
                            temp = frames[j];
                            frames[j] = pages[i];
                            counter[temp] = 0;
                            // counter[pages[i]] = 1;
                            break;
                        }
                    }
                }
            }
            count = 0;
            
            
        }
        for (int j = 0; j < capacity; j++){
                if(frames[j] != -1){
                    cout << frames[j] << "   ";
                }
            }
        for (int j = 0; j < capacity; j++){
                if(frames[j] != -1){
                    cout << "   " << appear[frames[j]] << " ";
                }
            }
        
        for (int j = 0; j < capacity; j++){
                if(frames[j] != -1){
                    cout << "   " << freq[frames[j]] << " ";
                }
            }
        cout << "\n";
    }
    cout << "The no of page faults is: " << page_faults << "\n";
    return 0;
}