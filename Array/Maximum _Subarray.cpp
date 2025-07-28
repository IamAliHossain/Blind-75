/*
    Problem Link: https://leetcode.com/problems/maximum-subarray/description/
    Problem Name: Maximum Subarray
    Difficulty  : Medium
    Time Complexity : O(N)
    Space Complexity: O(1)
*/

#include<bits/stdc++.h>
using namespace std;
/* 
    There added two same solution using kadan's algorithm 
    one is my own second one is other's 

    TC : O(N)
    SC : O(1)
*/
// solution 1 : my Own 
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
            maxSum = max(maxSum, sum);
            if(sum < 0){ 
                sum = 0;
            }
        }
        return maxSum;
    }
};
// solution 2
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> pref, suff;
        int n = nums.size();
        int sum = nums[0], mxSum = nums[0], l = 0, r = 0 ;
        for(int i=1; i<n; i++){
            sum = max(sum + nums[i], nums[i]);
            mxSum = max(mxSum, sum);
        }
        return mxSum;
    }
};