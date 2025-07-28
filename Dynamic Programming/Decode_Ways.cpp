/*
    Problem Link : https://leetcode.com/problems/decode-ways/description/
    Problem Name : 91. Decode Ways
    Difficulty   : Medium
    Time Complexity: O(n)
    Space Complexity : O(n) + call stack space O(n)
    Author : Ali Hossain
    Date : 12-05-2025

*/

#include<bits/stdc++.h>
using namespace std;

 /*     
    Memoization Technique
    
    N = s.size();
    TC : O(N)
    SC : O(N) for dp array


    dp array এর dimension নির্ভর করে হচ্ছে function কয়টা arguments এর উপর নির্ভর করছে তার উপর
    এখানে only index এই 1 টার উপর নির্ভর করে তাই 1D DP হবে। index can be N | 
    অতএব dp[N]
    
*/

class Solution{ 
    public:    
    int ways(int ind, string &s, vector<int> &dp) {

        if(ind == s.size()) return 1;
        if(dp[ind] != -1) return dp[ind];
        if(s[ind]=='0') return 0;

        int singleDig = ways(ind+1,s,dp);
        int doubleDig = 0;
        if(ind < s.size()-1 && (s[ind]=='1'||s[ind]=='2' && s[ind+1]<='6')){
            doubleDig =ways(ind+2,s,dp);
        }
        return dp[ind] = singleDig + doubleDig;
    }
    int numDecodings(string s) {
        int n = s.size();
        if(n == 0) return 0;
        vector<int> dp(n+1,-1);
        return ways(0,s,dp);   
    }
};
    