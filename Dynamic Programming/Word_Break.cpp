/*
    Problem Link : https://leetcode.com/problems/word-break/description/
    Problem Name : 139. Word Break
    Difficulty   : Medium
    Time Complexity : 
    Space Complexity: 
    Author : Ali Hossain
    Date : 11-05-2025


*/


#include<bits/stdc++.h>
using namespace std;

// Recursive solution 
/*
    N = s.length(), M = wordtDict.size() = k * m ; where k = wordDict[i].size() & m = wordDict.size();
    TC : O(M) + O(2 ^ N)
    SC : O(M) + O(N) for auxilary call stack space

    this exponential time complexity leads to TLE verdict

    so we need to apply memoization technique(DP) see next code
*/

class Solution {
public:
    bool isFound(int start, int end, string &s, unordered_set<string> &se){
        //base case
        if(end == s.size()-1){ 
            if(se.find(s.substr(start, end - start+1)) != se.end()){
                return true;
            }
            return false;
        }
        // if substring found in set se
        if(se.find(s.substr(start, end - start+1)) != se.end()){
            if(isFound(end+1, end+1, s, se))return true;
        }
        // if substring is not found in set se
        return isFound(start, end+1, s, se);

    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> se;
        for(int i=0; i<wordDict.size(); i++){
            se.insert(wordDict[i]);
        }
        return isFound(0, 0, s, se);
    }
};


/*---------------------------------------Memoiazation Technique---------------------------------------*/

/*
    dp array এর dimension নির্ভর করে হচ্ছে function কয়টা arguments এর উপর নির্ভর করছে তার উপর
    এখানে start & end এই 2 টার উপর নির্ভর করে তাই 2D DP হবে। start ও end length is max N তাই 
    N * N। 
    অতএব dp[N][N]
    
*/

// Memoization solution 
/*
    N = s.length(), M = wordtDict.size() = k * m ; where k = wordDict[i].size() & m = wordDict.size();

    dp array এর dimension নির্ভর করে হচ্ছে function কয়টা arguments এর উপর নির্ভর করছে তার উপর
    এখানে start & end এই 2 টার উপর নির্ভর করে তাই 2D DP হবে। start ও end length is max N তাই 
    N * N। 
    অতএব dp[N][N]

    M = 1000
    N = 300
    TC : O(M) + O(N) for creating substring * O(N * N * N) : O(N^3)
    SC : O(M) + O(N * N) + (N) for auxilary call stack space

    this exponential time complexity leads to TLE verdict

    so we need to apply memoization technique(DP)
*/

// solution 1(best to understand)
class Solution {
public:
    bool isFound(int start, int end, string &s, unordered_set<string> &se, vector<vector<int>> &dp){
        //base case
        if(end == s.size()-1){ 
            if(se.find(s.substr(start, end - start+1)) != se.end()){
                return true;
            }
            return false;
        }

        if(dp[start][end] != -1) return dp[start][end];
        // if substring found in set se
        if(se.find(s.substr(start, end - start+1)) != se.end()){
            if(isFound(end+1, end+1, s, se, dp)){
                return dp[start][end] = true;
                // return true;
            }
        }
        // if substring is not found in set se
        return dp[start][end] = isFound(start, end+1, s, se, dp);

    }
    bool wordBreak(string s, vector<string>& wordDict) {
        
        unordered_set<string> se;
        for(int i=0; i<wordDict.size(); i++){
            se.insert(wordDict[i]);
        }
        int n = s.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return isFound(0, 0, s, se, dp);
    }
};

// solution 2
/*  
    Time Complexity analysis : 
    O(n^2) pairs (start, end) and O(n) time to create substrings
    → O(n^2 * n) = O(n^3)

    🧠 Space Complexity
        dp array: O(n^2) space.
        Recursion call stack: maximum depth = O(n) (if each recursive call goes to end+1 only).
        Dictionary se: size = O(k * m), where k is number of words and m is average length of words.
*/

class Solution {
public:
    bool solve(int start, int end, string &s, unordered_set<string> &se, vector<vector<int>> &dp){
        
        if(dp[start][end] != -1) return dp[start][end];
        // Note : contains() only available on compiler c++23 version : se.contains(s.substr(start, end-start+1))
        if(end == s.length()-1){
            if(se.find(s.substr(start, end-start+1)) != se.end()){
                return true;
            }
            return false;
        }
        //  If the current substring (s[start...end]) is in the dictionary:
        // Recursively check if the rest of the string (s[end+1... ]) can also be segmented.
        // If that recursive call returns true, return true.
        if(se.find(s.substr(start, end-start+1)) != se.end()){
            if(solve(end+1, end+1, s, se, dp)){
                dp[start][end] = true;
                return true;
            }
        }
        dp[start][end] = solve(start, end+1, s, se, dp);
        return dp[start][end];
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> se;
        for(int i=0; i<wordDict.size(); i++){
            se.insert(wordDict[i]);
        }
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(0, 0, s, se, dp);

    }
};