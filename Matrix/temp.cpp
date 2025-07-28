#include<bits/stdc++.h>
using namespace std;

int main(){ 

    int n = 4;
    vector<vector<int>> matrix(n, vector<int> (n, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> matrix[i][j];
        }
    }
    vector<vector<int>> ans(n, vector<int> (n, 0));
    int k = n-1;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            ans[k][n-1-j] = matrix[i][j];; // ith row is stored at (n-i)th row, means 1st row jabe last row e and so on
        }
        k--;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            matrix[i][j] = ans[i][j];
        }
    }
    cout << endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }
}
