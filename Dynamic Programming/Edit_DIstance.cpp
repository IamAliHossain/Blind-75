// This problem is not from Blind 75 series

/*
    Problem Link : 
    Problem Name : 72. Edit Distance
    Difficulty   : Medium
    Time Complexity : 
    Space Complexity: 
    Author : Ali Hossain
    Date : 02-08-2025


    Given two strings word1 and word2, return the minimum number of operations 
    required to convert word1 to word2.

    You have the following three operations permitted on a word:

    Insert a character
    Delete a character
    Replace a character
    

    Example 1:

    Input: word1 = "horse", word2 = "ros"
    Output: 3
    Explanation: 
    horse -> rorse (replace 'h' with 'r')
    rorse -> rose (remove 'r')
    rose -> ros (remove 'e')
    Example 2:

    Input: word1 = "intention", word2 = "execution"
    Output: 5
    Explanation: 
    intention -> inention (remove 't')
    inention -> enention (replace 'i' with 'e')
    enention -> exention (replace 'n' with 'x')
    exention -> exection (replace 'n' with 'c')
    exection -> execution (insert 'u')
    

    Constraints:

    0 <= word1.length, word2.length <= 500
    word1 and word2 consist of lowercase English letters.


*/

#include<bits/stdc++.h>
using namespace std;

// Memoization(DP) solution
/* 
    Now  TC : O(3^N)*O(3^M) == O(3^(N + M) turns into O(N * M)) and  SC : O(N*M)
    minOperation depends on both ind1 and ind2, this 2 parameters are responsible therefore dp array will be 2D

    dp array এর dimension নির্ভর করে হচ্ছে function কয়টা arguments এর উপর নির্ভর করছে তার উপর
    এখানে ind1 & ind2 এই 2 টার উপর নির্ভর করে তাই 2D DP হবে N * M অতএব dp[N][M]


    TC : O((n * m))
    SC : O(n * m) + O(n + m) for stack memory

*/

class Solution {
public:
    int minOperation(int n, int m, string &s, string &t, vector<vector<int>> &dp){
        // base case
        if(n < 0) return m+1; // still number of (m+1) characters to be added to word2 means word1 <= word2
        if(m < 0) return n+1; // still number of (n+1) characters to be removed from word1 means word1 >= word2
        if(dp[n][m] != -1) return dp[n][m];
        // if matching
        if(s[n] == t[m]){
            return dp[n][m] =  0  + minOperation(n-1, m-1, s, t, dp);
        }
        // if character not matches 
        return dp[n][m] =  1 + min({
                minOperation(n,  m-1, s, t, dp), // insert at word1 hence last char are made equal
                minOperation(n-1,  m, s, t, dp), // removed characters form word1
                minOperation(n-1, m-1, s, t, dp) // replace last char at word1 with last char of word2
            });
        
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n, vector<int> (m, -1));

        return minOperation(n-1, m-1, word1, word2, dp);
        
    }
};