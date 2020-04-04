#include<iostream>
using namespace std;

const int P = 5; //Number of processes
const int R = 3; //Number of resources

bool isSafe(int processes[], int allocation[][R], int request[][R], int available[]){
    int work[R];
    for(int i = 0; i < R; i++)
        work[i] = available[i];

    bool finish[P];
    for(int i = 0; i < P; i++){
        int count = 0;
        for(int j = 0; j < R; j++){
            if(allocation[i][j] == 0)
                count++;
        }
        if(count == R)
            finish[i] = true;
        finish[i] = false;
    }

    int safeSequence[P];

    int count = 0;
    while(count < P){
        bool found = false;
        for(int p = 0; p < P; p++){
            if(finish[p] == false){
                int j;
                for(j = 0; j < R; j++){
                    if(request[p][j] > work[j])
                        break;
                }
                if(j == R){
                    for(int k = 0; k < R; k++){
                        work[k] += allocation[p][k];
                    }
                    safeSequence[count] = p;
                    count++;
                    finish[p] = true;
                    found = true;
                }
            }
        }
        if(found == false){
            cout << "System is not in safe state.\n";
            for(int t = 0; t < P; t++){
                if(finish[t] == false){
                    cout << "Process " << t << " is deadlock!\n";
                }
            }
            return false;
        }
    }
    cout << "System is in safe state.\nSafe sequence is: ";
    for(int i = 0; i < P; i++)
        cout << safeSequence[i] << " ";
        cout << "\n";
    return true;
}

int main(){
    int processes[] = {0, 1, 2, 3, 4};
    int available[] = {0, 0, 0};

    int request[][R] = {{0, 0, 0},
                        {2, 0, 2},
                        {0, 0, 0},
                        {1, 0, 0},
                        {0, 0, 2}};

    int allocation[][R] = {{0, 1, 0},
                            {2, 0, 0},
                            {3, 0, 3},
                            {2, 1, 1},
                            {0, 0, 2}};
    
    isSafe(processes, allocation, request, available);
    return 0;
}