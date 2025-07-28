/*
    Problem : https://leetcode.com/problems/rotate-image/
    Problem name : Rotate Image
    Difficulty : Medium

    Time Complexity : O(N * N)
    Space Complexity: O(N * N) since ans vector is used

*/

#include<bits/stdc++.h>
using namespace std;

// Solution for 90 degree rotate a Matrix

class Solution {
    public:
    /*
        Rotate the image 90 degree

        Origianl Matrix :
         1   2   3   4  
         5   6   7   8  
         9  10  11  12  
        13  14  15  16


        After 90 degre rotation : 
        13   9   5   1  
        14  10   6   2  
        15  11   7   3  
        16  12   8   4

    */
    void rotate_90(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> ans(n, vector<int> (n, 0));
        int k = n-1;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                ans[j][k] = matrix[i][j]; // ith row is stored at (n-i)th col, means 1st row jabe last col e and so on
            }
            k--;
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                matrix[i][j] = ans[i][j];
            }
        }
    }

    /*
        Rotate the image 180 degree

        Original Matrix :
         1   2   3   4  
         5   6   7   8  
         9  10  11  12  
        13  14  15  16


        After 180 degre rotation :
        16 15 14 13 
        12 11 10 9 
        8 7 6 5    
        4 3 2 1 
    
    */
    void rotate_180(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> ans(n, vector<int> (n, 0));
        int k = n-1;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                ans[k][n-1-j] = matrix[i][j]; // ith row is stored at (n-i)th row in the reverse order, means 1st row jabe last row e and so on
            }
            k--;
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                matrix[i][j] = ans[i][j];
            }
        }
    }


    /*
        Rotate the image 270 degree
    
        Original Matrix : 
         1   2   3   4  
         5   6   7   8  
         9  10  11  12  
        13  14  15  16


        After 270 degre rotation :
        4 8 12 16 
        3 7 11 15 
        2 6 10 14 
        1 5 9 13 
    */
    void rotate_270(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> ans(n, vector<int> (n, 0));
        int k = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                ans[n-1-j][k] = matrix[i][j]; // ith row is stored at (n-i)th col in the reverse order, means 1st row jabe last col e and so on
            }
            k++;
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                matrix[i][j] = ans[i][j];
            }
        }
    }
};