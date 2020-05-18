#include<iostream>
using namespace std;

int main (){
    int pages[] = {3, 2, 4, 1, 0, 2, 0, 1, 3, 5, 4, 2, 3};
    int n = sizeof(pages)/sizeof(pages[0]);
    int capacity = 3;

    int freq[capacity];
    int counter[10];
    int min = 0;
    int count = 0;
    int temp = 0;
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
    }
 
    for(int i = 0; i < n; i++){
        cout << pages[i] << "          ";
        counter[pages[i]]++;
        freq[pages[i]] = i;
        flag = true;
        frame = frames[0];

        for(int j = 0; j < capacity; j++){
            if(frames[j] == pages[i]){
                flag = false;
                counter[pages[i]]++;
                break;
            }

            if(counter[frame] > counter[frames[j]])
                frame = frames[j];
        }

        if(flag){
            page_faults++;
            min = 20;
            for (int j = 0; j < capacity; j++){
                if(counter[frames[j]] == counter[frame] && freq[frames[j]] < min){
                    temp = j;
                    min = freq[frames[j]];
                }
            }
            counter[frames[temp]] = 0;
            frames[temp] = pages[i];
            for (int j = 0; j < capacity; j++)
                if(frames[j] != -1)
                    cout << frames[j] << "   ";
        }
        cout << "\n";
    }
    cout << "The no of page faults is: " << page_faults;
    return 0;
}