/*
    Problem Link : https://leetcode.com/problems/jump-game/description/
    Problem Name : 55. Jump Game
    Difficulty   : Medium
   
    Author : Ali Hossain
    Date : 11-05-2025


*/

#include<bits/stdc++.h>
using namespace std;

// This is greedy solution next one is using DP(memoiation)
/*  
    Time Complexity : O(N)
    Space Complexity: O(1)

*/
class Solution {
public:
    
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxReachableInd = 0;
        for(int i=0; i<n; i++){
            if(maxReachableInd < i){
                return false;
            }
            else{
                maxReachableInd = max(maxReachableInd, i+nums[i]);
            }
        }
        return true;
    }
};

// This is the solution using DP(memoiation)
/*  
    Time Complexity : O(N)
    Space Complexity: O()

*/