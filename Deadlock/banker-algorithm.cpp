#include<iostream>
using namespace std;

const int P = 5; //Number of processes
const int R = 3; //Number of resources

void calculateNeed(int need[P][R], int maximum[P][R], int allocation[P][R]){
    for(int i = 0; i < P; i++){
        for(int j = 0; j < R; j++){
            need[i][j] = maximum[i][j] - allocation[i][j];
        }
    }
}

bool isSafe(int processes[], int available[], int maxm[][R], int allot[][R]){
    int need[P][R];
    calculateNeed(need, maxm, allot);
    bool finish[P] = {0};

    int safeSequence[P];

    int work[R];
    for(int i = 0; i < R; i++)
        work[i] = available[i];

    int count = 0;
    while (count < P){
        bool found = false;
        for(int p = 0; p < P; p++){
            if(finish[p] == 0){
                int j;
                for(j = 0; j < R; j++){
                    if(need[p][j] > work[j])
                        break;
                }
                if(j == R){
                    for(int k = 0; k < R; k++){
                        work[k] += allot[p][k];
                    }
                    // cout << count + "\n";
                    safeSequence[count] = p;
                    count++;
                    cout << count + "\n";
                    finish[p] = 1;
                    found = true;
                }
            }
        }
        if(found == false){
            cout << "System is not in safe state.\n";
            return false;
        }
    }
    cout << "System is in safe state.\nSafe sequence is: ";
    for(int i = 0; i < P; i++){
        cout << safeSequence[i] << " ";
    }
    return true;
}

int main(){
    int processes[] = {0, 1, 2, 3, 4};
    int available[] = {3, 3, 2};

    int maximum[][R] = {{7, 5, 3},
                        {3, 2, 2},
                        {9, 0, 2},
                        {2, 2, 2},
                        {4, 3, 3}};

    int allocation[][R] = {{0, 1, 0},
                            {2, 0, 0},
                            {3, 0, 2},
                            {2, 1, 1},
                            {0, 0, 2}};
    
    isSafe(processes, available, maximum, allocation);
    return 0;
}