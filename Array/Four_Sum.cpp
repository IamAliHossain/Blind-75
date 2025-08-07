/*
    This problem is not listed in Blind75    

    Problem Link : https://leetcode.com/problems/4sum/description/
    Problem Naem : 18. 4Sum
    Difficulty   : Medium

    Date : 6 August 2025

    Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

    0 <= a, b, c, d < n
    a, b, c, and d are distinct.
    nums[a] + nums[b] + nums[c] + nums[d] == target
    You may return the answer in any order.

    

    Example 1:

    Input: nums = [1,0,-1,0,-2,2], target = 0
    Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
    Example 2:

    Input: nums = [2,2,2,2,2], target = 8
    Output: [[2,2,2,2]]
    

    Constraints:

    1 <= nums.length <= 200
    -10^9 <= nums[i] <=  10^9
    -10^9 <= target <= 10^9



*/

#include<bits/stdc++.h>
using namespace std;

/*

 This is my own approach(Two Pointer) & solution code


    N = nums.size() = 200
    TC  : O(N * N * N * log(4))
        : O(N * N * N * 2)
        : O(2 * N ^ 3) 
        : O(2 * 200 ^ 3)
        : O(2 * 8 * 10 ^ 6)
        : O(16 * 10 ^ 6)
        : O(1.6 ^ 7) will pass by 1s
        
    SC  : O(N * N)(2D vector ans) + (N) (set se) + O(4)(vector res)
        : O(N ^ 2)

*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        set<vector<int>> se;
        int n = nums.size();

        for(int i=0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(i == j) continue;
                int left = 0, right = n - 1;
                long long need = (long long)target - (nums[i] + nums[j]) ;
                while(left < right){
                    if(i == left || j == left){
                        left++;
                    }
                    else if(i == right || j == right){
                        right--;
                    }
                    else if( need == (nums[left] + nums[right])){
                        vector<int> res = {nums[i], nums[j], nums[left], nums[right]};
                        sort(res.begin(), res.end()); // log(4) = 2
                        if(se.find(res) == se.end()){ // log(4) = 2
                            ans.push_back(res);
                            se.insert(res);
                        }
                        left++;
                        right--;
                    }
                    else if(need < nums[left] + nums[right]){
                        right--;
                    }
                    else{
                        left++;
                    }
                }
            }
        }
        return ans;
    }
};