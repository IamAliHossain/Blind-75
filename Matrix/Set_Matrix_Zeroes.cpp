/*
    Problem Link : https://leetcode.com/problems/set-matrix-zeroes/
    Difficulty   : Medium
    Problem Name : Set Matrix Zeroes
*/


#include<bits/stdc++.h>
using namespace std;

/*  
    Better Solution
    Time Complexity : O(N*M * log (N + M))
    Space Complexity: O(N + M)

    but if we use unordered set instead of set 
    then Time Complexity will turns to (N * M) because set takes O(logn) time 
    for find function whereas unordered_set takes O(1) time.

    So better use vector kono pera nai ar!
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        set<int> rowSe, colSe;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == 0){
                    rowSe.insert(i);
                    colSe.insert(j);
                }
            }
        }
        for(int i=0; i<n; i++){
            if(rowSe.find(i) != rowSe.end()){ // logn
                for(int col=0; col<m; col++){
                    matrix[i][col] = 0;
                }
            }
        }
        for(int j=0; j<m; j++){ 
            if(colSe.find(j) != colSe.end()){ // logm
                for(int row=0; row<n; row++){
                    matrix[row][j] = 0;
                }
            }
        }
        
    }
};

/*  
    Optimal Solution
    Time Complexity : O(N*M)
    Space Complexity: O(1)
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int col0 = 1;
        //Marking only 1st row and 1st col to reduce extra set(data structure) to store rows and cols from previous code,
        //Here each row and col value will be marked according to it's corresponding rows and cols, we will focus on matrix[0][0] seperately using col0 =1/0
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0 ;
                    if(j == 0){
                        col0 = 0;
                    }
                    else{
                        matrix[0][j] = 0;
                    }
                }
            }
        }
        // Setting 0's according to corresponding rows and cols values which I have marked before
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if(matrix[i][j] != 0){
                    if(matrix[i][0] == 0 || matrix[0][j] == 0){
                        matrix[i][j] = 0;
                    }
                }
            }
        }
        //Now be aware of 1st row at 1st, if I do mark 1st col value at 1st it may hamper the 1st row values
        if(matrix[0][0] == 0){
            for(int j=1; j<m; j++){
                if(matrix[0][j] != 0){
                    matrix[0][j] = 0;
                }
            }
        }
        // Now marking the 1st col values if col0 = 0 other values of 1st col are marked before during 1st step
        if(col0 == 0){
            for(int i=0; i<n; i++){
                if(matrix[i][0] != 0){
                    matrix[i][0] = 0;
                }
            }
        }
    }
};