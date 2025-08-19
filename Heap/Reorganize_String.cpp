/*
    This problem is form LeetCode Platform, listed on 450 DSA cracker

    Problem Link: https://leetcode.com/problems/reorganize-string/description/
    Problem Name: Reorganize String

    Date : 19-08-2025


    -------------------------------------------------------------------------------------------------------------------

    Problem statement

    
    Given a string s, rearrange the characters of s so that any two adjacent characters are not the 
    same.

    Return any possible rearrangement of s or return "" if not possible.

    

    Example 1:

    Input: s = "aab"
    Output: "aba"
    Example 2:

    Input: s = "aaab"
    Output: ""
    

    Constraints:

    1 <= s.length <= 500
    s consists of lowercase English letters.

*/





#include <bits/stdc++.h> 
using namespace std;


/*
    Enhanced Breakdown
    Initialization:

    Count the frequency of each character in the string.
    Populate the max heap with these frequencies.
    Processing Each Character:

    Pop the top two characters from the max heap (i.e., the ones with the highest frequency).
    Append these two characters to the result string.
    Decrement their frequencies and re-insert them back into the max heap.
    If only one character remains in the heap, make sure it doesn't exceed half of the 
    string length, otherwise, return an empty string.
    Wrap-up:

    If there's a single remaining character with a frequency of 1, append it to the result.
    Join all the characters to return the final reorganized string.
    Example:
    Given the input "aab":

    Max heap after initialization: [(-2, 'a'), (-1, 'b')]
    Result after first iteration: "ab"
    Wrap-up: Result is "aba"


    TC : O(N * logN)
    SC : O(N)


*/


class Solution {
public:
    string reorganizeString(string s) {

        priority_queue<pair<int, char>> maxHeap;
        unordered_map<char, int> hashMap;

        for(int i=0; i<s.size(); i++){
            hashMap[s[i]]++;
        }
        for(auto [ch, freq] : hashMap){
            maxHeap.push({freq, ch});
        }
        
        string res;
        while(maxHeap.size() >= 2){
            auto [freq1, ch1] = maxHeap.top();
            maxHeap.pop();

            auto [freq2, ch2] = maxHeap.top();
            maxHeap.pop();

            res += ch1;
            res += ch2;

            freq1--;
            freq2--;

            if(freq1 > 0) maxHeap.push({freq1, ch1});
            if(freq2 > 0) maxHeap.push({freq2, ch2});
        }

        if(maxHeap.size()){
            auto[freq, ch] = maxHeap.top();
            maxHeap.pop();

            if(freq > 1) return "";
            res += ch;
        }
        return res;

    }
};