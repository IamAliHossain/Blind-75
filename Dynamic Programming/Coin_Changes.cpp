/*
    Problem Link : https://leetcode.com/problems/coin-change/description/
    Problem Name : 322. Coin Change
    Difficulty   : Medium


    Author : Ali Hossain
    Date : 10-05-2025

    You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

    Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

    You may assume that you have an infinite number of each kind of coin.

    

    Example 1:

    Input: coins = [1,2,5], amount = 11
    Output: 3
    Explanation: 11 = 5 + 5 + 1
    Example 2:

    Input: coins = [2], amount = 3
    Output: -1
    Example 3:

    Input: coins = [1], amount = 0
    Output: 0
    

    Constraints:

    1 <= coins.length <= 12
    1 <= coins[i] <= 231 - 1
    0 <= amount <= 104

*/

#include<bits/stdc++.h>
using namespace std;

/*      
    Recursive Solution :

    This recursive solution which leads to TC : O(2^N) provide TLE
    SC(more than N) for auxilary stack space 
    space complexity greater than O(N) because we are using same index infinite times as problem said
*/
class Solution {
public:
    int minNumOfCoins(int index, vector<int>& coins, int target){
        if(index == 0){
            // since I can use infinite number of use of each case so I can divide
            if(target % coins[index] == 0) return target/coins[index];
            else return 1e9; // (INT_MAX + 1 ) integer overflow kore runtime error dibe so use 1e9
        }
        
        int take = INT_MAX;
        if(target >= coins[index]){
            take = min(take, 1 + minNumOfCoins(index, coins, target-coins[index]));
        } 
        int notTake = minNumOfCoins(index-1, coins, target);
        return min(take, notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int result = minNumOfCoins(coins.size()-1, coins, amount);
        return (result == 1e9) ? -1 : result;
    }
};

/*
    Memoization Technique :

    dp array এর dimension নির্ভর করে হচ্ছে function কয়টা arguments এর উপর নির্ভর করছে তার উপর
    এখানে index & target এই 2 টার উপর নির্ভর করে তাই dimension হবে N * Target অতএব dp[N][Target]

    To avoid TLE of previous solution now I'll use memoization or DP technique
    Where TC : O(N * Target) traversing through the 'coins' array & 
    SC : O(N) auxilary stack space + O(N * target) for using dp array so overrall SC : O(N * Target)

*/
class Solution {
public:
    int minNumOfCoins(int index, vector<int>& coins, vector<vector<int>>& dp, int target){
        // base case
        if(index == 0){
            // since I can use infinite number of use of each case so I can divide
            if(target % coins[index] == 0) return target/coins[index];
            else return 1e9; // (INT_MAX + 1 ) integer overflow kore runtime error dibe so use 1e9
        }
        if(dp[index][target] != -1) return dp[index][target];
        // take case
        int take = INT_MAX;
        if(target >= coins[index]){
            take = min(take, 1 + minNumOfCoins(index, coins, dp, target-coins[index]));
        } 
        // notTake case
        int notTake = minNumOfCoins(index-1, coins, dp, target);

        // taking minimum coins
        dp[index][target] = min(take, notTake);
        return dp[index][target];

    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));
        int ans = minNumOfCoins(coins.size()-1, coins, dp, amount);
        return (ans == 1e9) ? -1 : ans;
    }
};

/*
    Iterative Technique :
    TC : O(N * Target)
    SC : O(N * Target) 
    এখানে O(Target) auxilary stack space দরকার হয় নাই যেহেতু recursion ইউজ করা লাগে নাই
*/
class Solution{
    public:
    int l(vector<int> &coins, int amount){
        
        int dp[amount+1];
        for(int i=1; i<=amount; i++){
            dp[i] = amount;
        }
        dp[0] = 0;
        for(int i=1; i<=amount; i++){
            for(auto coin : coins){
                if(i-coin < 0) continue;
                dp[i] = min(dp[i-1], 1+dp[i-coin]);
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};
