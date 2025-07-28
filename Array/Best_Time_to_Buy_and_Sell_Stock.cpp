/*
    Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
    Problem Name: Best Time To Buy and Sell Stock
    Difficulty  : Easy
    Time Complexity : O(N)
    Space Complexity: O(1)

    Approach : Keeping track on minimum prices from 1st day to (i-1)th day
            where profit would be maximum profit = max(profit, prices[i]- mini)
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn = prices[0], profit = 0;
        for(int i=1; i<prices.size(); i++){
            mn = min(mn, prices[i]); // taking minimum from 1st day to ith day
            profit = max(profit, prices[i]-mn); // here remembering the past so it is DP
        }
        return profit;
    }
};