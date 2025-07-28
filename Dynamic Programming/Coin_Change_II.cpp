/*
    Problem Link : https://leetcode.com/problems/coin-change-ii/description/
    Problem Name : 518. Coin Change II
    Difficulty   : Medium
    Time Complexity: O(n)
    Space Complexity : O(n) + call stack space O(n)
    Author : Ali Hossain
    Date : 12-05-2025

   You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

    Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

    You may assume that you have an infinite number of each kind of coin.

    The answer is guaranteed to fit into a signed 32-bit integer.

    

    Example 1:

    Input: amount = 5, coins = [1,2,5]
    Output: 4
    Explanation: there are four ways to make up the amount:
    5=5
    5=2+2+1
    5=2+1+1+1
    5=1+1+1+1+1
    Example 2:

    Input: amount = 3, coins = [2]
    Output: 0
    Explanation: the amount of 3 cannot be made up just with coins of 2.
    Example 3:

    Input: amount = 10, coins = [10]
    Output: 1
    

    Constraints:

    1 <= coins.length <= 300
    1 <= coins[i] <= 5000
    All the values of coins are unique.
    0 <= amount <= 5000 

*/

/*
    This problem is quite similar with problem named Combination Sum IV, ei problem e bola hoyeche
    like 5 = 2 + 2 + 1 and 5 = 1 + 2 + 2 are two diffrent ways

    But in this Coin change II problem e 
    bola hoyeche 5 = 2 + 2 + 1 and 5 = 1 + 2 + 2 are not two diffrent ways this is count as only
    1 valid way

    so etake 2 different way count korar jonno recursion er vitore 
    for loop diye solve kora hoyeche(https://github.com/IamAliHossain/Blind-150-75/blob/main/Dynamic%20Programming/Combination_Sum_IV.cpp)
    and 1D dp diye solve able chilo since only one parameter was changing there

    But ei problem e 2 ta way kei only 1 ta way dhora hoyeche so index and target
    both parameters are changing hence this is 2D dp problem and inside the recursive 
    function no for loop is available. See the below code

*/

#include<bits/stdc++.h>
using namespace std;

// Here 2 parameters(index and target) are changing that's why we need a 2D dp
// dp[ind][target] = k ---> from 0 to ind there are total k possibilitis to make target

class Solution {
public:
    int ways(int ind, int target, vector<int>& coins, vector<vector<int>>& dp){

        if(ind == coins.size()-1){
            if(target % coins[ind] == 0) return 1;
            else return 0;
        }
        if(dp[ind][target] != -1) return dp[ind][target];
        
        int notTake = ways(ind+1, target, coins, dp);
        int take = 0;
        if(coins[ind] <= target){
            // ind is not changed cause I can take the value of the same index as many times I wish
            take = ways(ind, target-coins[ind], coins, dp);
        }
        
        dp[ind][target] = notTake + take;
        return dp[ind][target];
    }
    int change(int amount, vector<int>& coins) {
        if(amount == 0) return 1;
        vector<vector<int>> dp(amount, vector<int>(amount+1, -1));
        return ways(0, amount, coins, dp);
    }
};