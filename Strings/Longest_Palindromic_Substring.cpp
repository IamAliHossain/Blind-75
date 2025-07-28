/*  
    Problem Link: https://leetcode.com/problems/longest-palindromic-substring/description/
    Problem Title: 5.Longest Palindromic Substring
    Problem Difficulty: Medium
    Given a string s, return the longest palindromic substring in s.

    Example 1:

    Input: s = "babad"
    Output: "bab"
    Explanation: "aba" is also a valid answer.
    Example 2:

    Input: s = "cbbd"
    Output: "bb"
    

    Constraints:

    1 <= s.length <= 1000
    s consist of only digits and English letters.

*/

// Time complexity : O(n * n) + O(n * logn) : O(n ^ 2)
// Space Complexity: O(n) + O(n) : O(2n)
// There is also DP solution go below

class Solution {
public:
    string palindrom(string s, int left, int right){
        string t ="";
        while(left >= 0 and right < s.size() && s[left] == s[right]){
            left--;
            right++;
        }
        // Taking palindrome string from this range
        for(int i=left+1; i< right; i++){
            t+= s[i];
        }
        return t;
    }
    string longestPalindrome(string s) {
        vector<pair<int, string>> vp;
        string odd, even;
        int n = s.size() ;
        for(int i=0; i<n; i++){
            odd = palindrom(s, i, i); // odd length palindrom
            even = palindrom(s, i, i+1); // even length palindrome
            vp.push_back({odd.size(), odd});
            vp.push_back({even.size(), even});
        }
        sort(vp.rbegin(), vp.rend());
        return vp[0].second ;
    }
};

#include<bits/stdc++.h>
using namespace std;

// string s="babad";
// string s = "cbbcddddc";
// string s = "a";
string s = "aacabdkacaa";
bool dp[1010][1010];

string longestSubstr(string s, int i, int j, int start, int maxLength){
    if(i<0 and j>=s.size()) return "";
    if(dp[i][j] != false) return s.substr(start, maxLength);
    string l = longestSubstr(s, i-1, j, start, maxLength);
    string r = longestSubstr(s, i, j+1, start, maxLength);

}

int main(){

    int start = 0, maxLength = 1;
    string longestSubstr = s.substr(start, maxLength);
    for(int i=0; i<s.size(); i++){
        dp[i][i] = true;
    }
    for(int i=0; i<s.size()-1; i++){
        if(s[i] == s[i+1]){
            maxLength = 2;
            start = i;
            longestSubstr = s.substr(start, maxLength);
            dp[i][i+1] = true;
        }
    }
    for(int len = 3; len<= s.size(); len++){
        for(int i=0; i<s.size()-len+1; i++){
            int j=i+len-1;
            if(s[i] == s[j] and dp[i+1][j-1] == true){ 
                dp[i][j] = true;
                start = i;
                maxLength = len;
                longestSubstr = s.substr(start, maxLength);
            }
        }
    }
    cout  << "longestSubstr " << longestSubstr << endl;
}