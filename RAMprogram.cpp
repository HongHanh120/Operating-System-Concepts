#include<iostream>
using namespace std;
int main (){
    int number_of_row = 128;
    int number_of_col = 128;
    int data[number_of_row][number_of_col];
    int counter1 = 0; // count number of page faults in program 1
    int counter2 = 0; // count number of page faults in program 2

    // program 1
    for(int j = 0; j < number_of_col; j++){
        for(int i = 0; i < number_of_row; i++){
            data[i][j] = 0;
            counter1++;
        }
    }

    // program2
    for(int i= 0; i < number_of_col; i++){
        counter2++;
        for(int j = 0; j < number_of_row; j++){
            data[i][j] = 0;
        }
    }

    cout << "The number of page faults in program 1 is: " << counter1 << "\n";
    cout << "The number of page faults in program 2 is: " << counter2 << "\n";
    return 0;
}

