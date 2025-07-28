/*
    Problem : https://leetcode.com/problems/spiral-matrix/description/
    Problem name : Spiral Matrix
    Difficulty : Medium

    Time Complexity : O(N * M)
    Space Complexity: O(1)

*/

/* Bruteforce Solution Technique */
#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> spiralOrder(vector<vector<int>>& matrix) {
            int n = matrix.size();
            int m = matrix[0].size();
            vector<int> res;
            int top = 0, right = m-1, bottom = n-1, left = 0 ;
    
            while(top <= bottom &&  left <= right){
                //Moving left to right
                for(int j=top; j<=right; j++){
                    res.push_back(matrix[top][j]);
                }
                top++;
                //Moving top to bottom
                for(int i=top; i<=bottom; i++){
                    res.push_back(matrix[i][right]);
                }
                right--;
                //Moving right to left
                if(top <= bottom){ 
                    for(int j=right; j>=left; j--){
                        res.push_back(matrix[bottom][j]);
                    }
                    bottom--;
                }
                //Moving bottom to top
                if(left <= right){ 
                    for(int i=bottom; i>=top; i--){
                        res.push_back(matrix[i][left]);
                    }
                    left++;
                }
            }
            return res;
        }
    };