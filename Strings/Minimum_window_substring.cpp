#include<bits/stdc++.h>
using namespace std;
/*  
    Leetcode String(Sliding Window Technique Problem) : 
    
    Problem Link : https://leetcode.com/problems/minimum-window-substring/
    Dificulty : Hard
    
    Given two strings s and t of lengths m and n respectively, return the minimum window substring
    of s such that every character in t (including duplicates) is included in the window. 
    If there is no such substring, return the empty string "".

    The testcases will be generated such that the answer is unique.

    

    Example 1:

    Input: s = "ADOBECODEBANC", t = "ABC"
    Output: "BANC"
    Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
    Example 2:

    Input: s = "a", t = "a"
    Output: "a"
    Explanation: The entire string s is the minimum window.
    Example 3:

    Input: s = "a", t = "aa"
    Output: ""
    Explanation: Both 'a's from t must be included in the window.
    Since the largest window of s only has one 'a', return empty string.
    

    Constraints:

    m == s.length
    n == t.length
    1 <= m, n <= 105
    s and t consist of uppercase and lowercase English letters.
    

    Follow up: Could you find an algorithm that runs in O(m + n) time?
*/

/*  
    N = s.size()
    M = t.size();
    TC : O(M) + O(N) + O(N) : O(M + N)
    SC : O(26) for hash table of T string  : O(1)
*/

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> hashT;
        for(int i=0; i<t.size(); i++){ // O(M)
            hashT[t[i]]++;
        }

        int left = 0, right = 0, n = s.size(), lenT = t.size(), bestLeftInd = -1, minWindow = INT_MAX;
        // for this sliding window O(N)
        while(right < n){
            hashT[s[right]]--;
            if(hashT[s[right]] >= 0){
                lenT--;
            }
            right++;
            while(lenT == 0){
                if((right - left ) < minWindow){
                    minWindow = right - left;
                    bestLeftInd = left ;
                } 
                hashT[s[left]]++;
                // after taking s[left] into the hash table now length of T 
                // will be increased if hashT[s[left]]>0 so, lentT got ++
                if(hashT[s[left]] > 0){
                    lenT++;
                }
                left++;
            }
        }
        // minWindow stores the length of the best window found so far so find substr using minWindow
        return ((bestLeftInd == -1) ? "" : s.substr(bestLeftInd, minWindow)); // O(N)
    }
};


// sol2
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> hash(128, 0);
        for(char ch : t){
            hash[ch]++;
        }
        int counter = t.size();
        int left = 0, right = 0;
        int minLength = INT_MAX;
        int bestLeft = -1;
        while(right < s.size()){
            char endChar = s[right];
            hash[endChar]--;
            if(hash[endChar] >= 0){
                counter--;
            }
            right++;

            while(counter == 0){

                if(right - left + 1 < minLength){
                    minLength = right - left + 1;
                    bestLeft = left;
                }
                char startChar = s[left];
                hash[startChar]++;
                if(hash[startChar] > 0){
                    counter++;
                }
                left++;
            }
        }
        return (bestLeft == -1 ? "" : s.substr(bestLeft, minLength));
    }
};

