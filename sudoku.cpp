#include<bits/stdc++.h>
using namespace std;

#define n 9

bool findEmpty(int **input , int& row , int& col) {
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++){
            if(input[i][j] == 0) {
                row = i;
                col = j;
                return true;
            }
        }
    }
    return false;
}

bool isSafeInCol(int **input , int col , int num) {
    for(int i = 0 ; i < n ;i++) {
        if(input[i][col] == num) {
            return false;
        }
    }
    return true;
}

bool isSafeInRow(int **input , int row , int num) {
    for (int i = 0 ; i < n ; i++) {
        if(input[row][i] == num) {
            return false;
        }
    }
    return true;
}

bool isSafeInBox(int **input, int row , int col , int num) {
    int x = row - (row % 3);
    int y = col - (col % 3);
    
    for(int i = 0 ; i < 3 ; i++) {
        for(int j = 0 ; j < 3 ; j++) {
            if(input[i + x][j + y] == num) {
                return false;
            }
        }
    }
    return true;
}

bool isSafe(int ** input, int row , int col , int num) {
    return isSafeInCol(input , col , num) && isSafeInRow(input , row , num) && isSafeInBox(input , row , col , num);
}

bool solveSudoku(int **input ) {
    int row , col;
    if(!findEmpty(input , row , col)) {
        return true;
    }
    for(int i = 1 ; i <= 9 ; i++) {
        if(isSafe(input , row , col , i)){
            input[row][col] = i;
            if(solveSudoku(input)) 
                return true;
            input[row][col] = 0;
        }
    }
    return false;
}
int main() {
    int** input = new int*[n];
    for (int i =0 ; i < n ; i++) {
        input[i] = new int[n];
    }
    for(int i = 0 ; i < n ; i++) {
        string s;
        cin >> s;
        for (int j = 0 ; j < s.size() ; j++) {
            input[i][j] = s[j] - '0';
        }
    }
    if(solveSudoku(input)) {
        cout << "true" ;
    }
    else cout << "false";
    return 0;
}