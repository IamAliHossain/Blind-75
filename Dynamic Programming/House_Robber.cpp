/*
    Problem Link : https://leetcode.com/problems/house-robber/description/
    Problem Name : House Robber
    Difficulty   : Medium
   
    Author : Ali Hossain
    Date : 11-05-2025


    Problem Statemnt:
    You are a professional robber planning to rob houses along a street. Each house has a certain 
    amount of money stashed, the only constraint stopping you from robbing each of them is that 
    adjacent houses have security systems connected and it will automatically contact the police 
    if two adjacent houses were broken into on the same night.

    Given an integer array nums representing the amount of money of each house, 
    return the maximum amount of money you can rob tonight without alerting the police.

    

    Example 1:

    Input: nums = [1,2,3,1]
    Output: 4
    Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
    Total amount you can rob = 1 + 3 = 4.
    Example 2:

    Input: nums = [2,7,9,3,1]
    Output: 12
    Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
    Total amount you can rob = 2 + 9 + 1 = 12.
    

    Constraints:

    1 <= nums.length <= 100
    0 <= nums[i] <= 400

*/



#include<bits/stdc++.h>
using namespace std;

/*----------------------------------Recursion Technique Starts-----------------------------------------*/

/*
    যেহেতু পাশাপাশি(adjacent) ২ টা বাড়ীতে ডাকাতি করা যাবে না তাই যদি কোন index pick  করি 
    তাহলে তার পরের index-2 হবে, আর যদি notPick করি তাইলে very next index-1 নিব
    মাইনাস করছি কারন অ্যারের শেষ থেকে ট্রাভার্স করছি|
    
    N = nums.size();
    TC : O(2^N)
    SC : O(N) for recursion call stack
    This recursive code will return TLE verdict to optimize we need to apply Memoization(dp) Technique

*/
class Solution {
public:
    int maxVal(int index, vector<int>& nums){
        if(index < 0) return 0;
        int take = nums[index] + maxVal(index-2, nums);
        int notTake = 0 + maxVal(index-1, nums);
        return max(take, notTake);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return maxVal(nums.size()-1, nums);
    }
};

/*----------------------------------Recursion Technique Ends-----------------------------------------*/


/*----------------------------------Memoization Technique -----------------------------------------*/

/*
    যেহেতু পাশাপাশি(adjacent) ২ টা বাড়ীতে ডাকাতি করা যাবে না তাই যদি কোন index pick  করি 
    তাহলে তার পরের index-2 হবে, আর যদি notPick করি তাইলে very next index-1 নিব
    মাইনাস করছি কারন অ্যারের শেষ থেকে ট্রাভার্স করছি|
    
    N = nums.size();
    TC : O(N)
    SC : O(N) for recursion call stack

    The above recursive code will return TLE verdict to optimize we need to apply Memoization(dp) Technique

    dp array এর dimension নির্ভর করে হচ্ছে function কয়টা arguments এর উপর নির্ভর করছে তার উপর
    এখানে only index এই 1 টার উপর নির্ভর করে তাই 1D DP হবে। index can be N | 
    অতএব dp[N]

*/
class Solution {
public:
    int maxVal(int index, vector<int>& nums, vector<int> &dp){
        if(index < 0) return 0;
        if(dp[index] != -1) return dp[index];
        int take = nums[index] + maxVal(index-2, nums, dp);
        int notTake = 0 + maxVal(index-1, nums, dp);
        return dp[index] = max(take, notTake);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return maxVal(nums.size()-1, nums, dp);
    }
};
/*----------------------------------Memoization Technique Ends-----------------------------------------*/

