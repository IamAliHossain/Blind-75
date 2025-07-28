/*
    Problem Link : https://leetcode.com/problems/house-robber-ii/description/
    Problem Name : 213. House Robber II
    Difficulty   : Medium
   
    Author : Ali Hossain
    Date : 11-05-2025

*/

#include<bits/stdc++.h>
using namespace std;

/*
        Time Complexity : O(n) 
        Space Complexity: O(n) + O(n) + call stack(n)
        The code is in memoiation technique
*/

/*  
    Memoization solution

    
    যেহেতু পাশাপাশি(adjacent) ২ টা বাড়ীতে ডাকাতি করা যাবে না এবং circular shape এ 1st index 
    and last index adjacent হয়, তাই You can’t rob both the first and the last houses because
    they’re circularly adjacent| এখন যদি কোন index pick করি তাহলে তার পরের index+2 হবে, 
    আর যদি notPick করি তাইলে very next index+1 নিব
    
    So you split the problem:
    Rob from index 0 to n-2
    Rob from index 1 to n-1

    dp array এর dimension নির্ভর করে হচ্ছে function কয়টা arguments এর উপর নির্ভর করছে তার উপর
    এখানে only index এই 1 টার উপর নির্ভর করে তাই 1D DP হবে। index can be N | 
    অতএব dp[N]

    TC : O(N)
    SC : O(N) for dp1 + O(N) for dp2 : so finally SC : O(N)
*/

class Solution {
public:
    int robbingMoney(int index, int endInd, vector<int>& nums, vector<int> &dp){
        if(index > endInd){
            return 0;
        }
        if(index == endInd){
            return nums[index];
        }
        if(dp[index] != -1) return dp[index];
        int take = nums[index] + robbingMoney(index+2, endInd, nums, dp);
        int notTake = 0 + robbingMoney(index+1, endInd, nums, dp);
        return dp[index] = max(take, notTake);
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> dp1(n, -1), dp2(n, -1);
        // need to skip 1st and last skip to avoid circular shape
        int skips_last_index = robbingMoney(0, n-2, nums, dp1);
        int skips_1st_index = robbingMoney(1, n-1, nums, dp2);
        return max(skips_last_index, skips_1st_index);
    }
};

// same solution as above just variable naming is different
class Solution {
public:
    // Making array linear by skiping once 1st index and once last index to avoid neigboring state
    int money(int ind, int lastInd, vector<int>& nums, vector<int>& dp){
        if(ind > lastInd) return 0;
        if(ind == lastInd) return nums[ind];
        if(dp[ind] != -1) return dp[ind];
        int pick = nums[ind] + money(ind+2, lastInd, nums, dp);
        int notPick = 0 + money(ind+1, lastInd, nums, dp);
        dp[ind] = max(pick, notPick);
        return dp[ind];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> dp1(nums.size(), -1), dp2(nums.size(), -1);
        // To make it easier made it linear by skipping one index
        int skip_1st_index = money(1, n-1, nums, dp1);
        int skip_last_index = money(0, n-2, nums, dp2);

        return max(skip_1st_index , skip_last_index);
        
    }
};