/*
    Problem Link : https://leetcode.com/problems/longest-repeating-character-replacement/submissions/1703027228/
    Problem Name : 424. Longest Repeating Character Replacement
    Difficulty   : Medium
    Time Complexity: O(L) --> L is the total length of the strings
    Space Complexity: O(1)

    Date : 25-05-2025


===================================================================================================


    You are given a string s and an integer k. You can choose any character of the string and change 
    it to any other uppercase English character. You can perform this operation at most k times.

    Return the length of the longest substring containing the same letter you can get after 
    performing the above operations.

    

    Example 1:

    Input: s = "ABAB", k = 2
    Output: 4
    Explanation: Replace the two 'A's with two 'B's or vice versa.
    Example 2:

    Input: s = "AABABBA", k = 1
    Output: 4
    Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
    The substring "BBBB" has the longest repeating letters, which is 4.
    There may exists other ways to achieve this answer too.
    

    Constraints:

    1 <= s.length <= 10^5
    s consists of only uppercase English letters.
    0 <= k <= s.length

*/


#include<bits/stdc++.h>
using namespace std;


/*

    Time Complexity:
    The function finds the longest repeating character replacement using the sliding window technique.

    Each character is added once and removed once from the unordered_map named hash.
    The inner while loop runs only when duplicates are found, and l only moves forward.

    So in total, both pointers (l, r) traverse the string once, giving:

    ✅ Time Complexity: O(n) where n = s.size()
    ✅ Space: O(26) for 26 atmost characters so O(1) eventually

*/

class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> hash;
        int left = 0, right = 0, n = s.size();
        int diffChar = 0, window = 0, longestLen = 0, mxCharCnt = 0;
        while(right < n){
            hash[s[right]]++;       // O(1)
            mxCharCnt = max(mxCharCnt, hash[s[right]]);
            window = right - left + 1;
            diffChar = window - mxCharCnt ; // if in window have let a & b then diffChar = 1
            
            //when diffChar <= k window is valid so take maximum length
            if(diffChar <= k){
                longestLen = max(longestLen, window);
            }
            //when diffChar > k window is invalid so make it valid by removing from left
            while(diffChar > k){
                hash[s[left]]--;
                diffChar--;
                left++;
            }
            right++;
        }
        return longestLen;
    }
};