/*
    Problem Link : https://leetcode.com/problems/longest-common-subsequence/
    Problem Name : 1143. Longest Common Subsequence
    Difficulty   : Medium
    
    Author : Ali Hossain
    Date : 10-05-2025


 */

#include<bits/stdc++.h>
using namespace std;
/*-------------------------------------Recursive Solution Start-------------------------------------------*/

// This code is done with just recursive hence TC = O(2^n * 2^m) and brings TLE
    // To optimize the code we apply dp here, so see the next part
    //      Time Complexity : O(2^n * 2^m) Because eikhane 2 ta string er recursion cholche
    //      Space Complexity : O(N + M) 

// Recursive sol1
class Solution {
    public:
    int LCS(string s, string t, int sn, int tn){
        if(sn < 0 || tn < 0) return 0;
        int len = 0;
        // Match on characters
        if(s[sn] == t[tn]){ 
            len += 1 + LCS(s, t, sn-1, tn-1);
        }
        // Not Match on characters
        else{
            len += 0 + max(LCS(s, t, sn-1, tn), LCS(s, t, sn, tn-1));
        }
        return len;

    }
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.length();
        int n2 = text2.length();
        return LCS(text1, text2, n1-1, n2-1);
    }
};

// Recursive sol2

/*
    this sol give TLE because here TC : O(2^N)*O(2^M) == O(2^(N + M)) and  SC : O(N) + O(M)

    That's why we need dp solution & we will in the next. Let's see TLE verdict now (-_-)
*/
class Solution {
public:
    int lenOfLCS(int t1Ind, int t2Ind, string &text1, string &text2){
        // base case
        if(t1Ind == text1.size() || t2Ind == text2.size()) return 0;
        // characters matched
        if(text1[t1Ind] == text2[t2Ind]){
            return 1 + lenOfLCS(t1Ind+1, t2Ind+1, text1, text2);
        }
        // here characters not mathced
        return 0 + max(lenOfLCS(t1Ind+1, t2Ind, text1, text2),lenOfLCS(t1Ind, t2Ind+1, text1, text2));
    }
    int longestCommonSubsequence(string text1, string text2) {
        return (lenOfLCS(0, 0, text1, text2));
    }
};


/*-------------------------------------Recursive Solution End-------------------------------------------*/



/*-------------------------------------Memoization Solution Start-------------------------------------------*/

/*
     This code is done using dp to reduce TC 
     To optimize the code we apply dp here

     dp array এর dimension নির্ভর করে হচ্ছে function কয়টা arguments এর উপর নির্ভর করছে তার উপর
    এখানে t1Ind & t2Ind এই 2 টার উপর নির্ভর করে তাই 2D DP হবে N * prevIndex অতএব dp[N][M]

          Time Complexity : O(n * m) Because eikhane 2 ta string er recursion cholche
         Space Complexity : O(n * m) + (n + m)(auxilary space at stack)


*/
// You can see any of the solution below
// sol1 in memoization
class Solution {
public:
    int lenOfLCS(int t1Ind, int t2Ind, string &text1, string &text2, vector<vector<int>> &dp){
        // base case
        if(t1Ind == text1.size() || t2Ind == text2.size()) return 0;
        if(dp[t1Ind][t2Ind] != -1) return dp[t1Ind][t2Ind];
        // characters matched
        if(text1[t1Ind] == text2[t2Ind]){
            return dp[t1Ind][t2Ind] = 1 + lenOfLCS(t1Ind+1, t2Ind+1, text1, text2, dp);
        }
        // here characters not mathced
        return dp[t1Ind][t2Ind] = 0 + max(lenOfLCS(t1Ind+1, t2Ind, text1, text2, dp),lenOfLCS(t1Ind, t2Ind+1, text1, text2, dp));

        
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return lenOfLCS(0, 0, text1, text2, dp);
    }
};
// sol2 in memoization
class Solution {
    public:
    int LCS(vector<vector<int>> &dp, string &s, string &t, int sn, int tn){
        if(sn == 0 || tn == 0) return 0;
        if(dp[sn][tn] != -1) return dp[sn][tn];
        if(s[sn - 1] == t[tn - 1]){
            return dp[sn][tn] = 1 + LCS(dp, s, t, sn - 1, tn - 1);
        } 
        else {
            return dp[sn][tn] = max(LCS(dp, s, t, sn - 1, tn), LCS(dp, s, t, sn, tn - 1));
        }
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.length();
        int n2 = text2.length();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));
        return LCS(dp, text1, text2, n1, n2);
    }
};

/*-------------------------------------Memoization Solution End-------------------------------------------*/


/*-------------------------------------Iterative Solution Start-------------------------------------------*/
// This code is done with tabulation so TC = O(n * m) and SC : O(n * m) + (n + m)(auxilary space at stack)
    // To optimize the space we apply tabulation(Bottom-up) aproach  here, so see the next part
    //      Time Complexity : O(n * m) Because eikhane 2 ta string er recursion cholche
    //      Space Complexity : O(n * m)


    // Incomplete code do not take this part
class Solution{

    
    int longestCommonSubsequence(string s, string t){
        int n = s.length() - 1;
        int m = t.length() - 1;
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        // From the base case we know if i or j == 0 then return 0
        for(int i=0; i<=n; i++){
            dp[i][0] = 0;
        }
        for(int j=0; j<=n; j++){
            dp[0][j] = 0;
        }

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        return dp[n][m];

    }
};

