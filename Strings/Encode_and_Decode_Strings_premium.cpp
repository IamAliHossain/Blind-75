/*
    Problem Link : https://leetcode.com/problems/encode-and-decode-strings/description/
    Problem Name : 271. Encode and Decode Strings
    Difficulty   : Medium
    Time Complexity: O(L) --> L is the total length of the strings
    Space Complexity: O(L)

    Date : 25-05-2025


===================================================================================================


Design an algorithm to encode a list of strings to a string. The encoded string is then sent over the network and is decoded back to the original list of strings.

Machine 1 (sender) has the function:

string encode(vector<string> strs) {
  // ... your code
  return encoded_string;
}
Machine 2 (receiver) has the function:
vector<string> decode(string s) {
  //... your code
  return strs;
}
So Machine 1 does:

string encoded_string = encode(strs);
and Machine 2 does:

vector<string> strs2 = decode(encoded_string);
strs2 in Machine 2 should be the same as strs in Machine 1.

Implement the encode and decode methods.

You are not allowed to solve the problem using any serialize methods (such as eval).

 

Example 1:

Input: dummy_input = ["Hello","World"]
Output: ["Hello","World"]
Explanation:
Machine 1:
Codec encoder = new Codec();
String msg = encoder.encode(strs);
Machine 1 ---msg---> Machine 2

Machine 2:
Codec decoder = new Codec();
String[] strs = decoder.decode(msg);
Example 2:

Input: dummy_input = [""]
Output: [""]
 

Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] contains any possible characters out of 256 valid ASCII characters.
 

Follow up: Could you write a generalized algorithm to work on any possible set of characters?


*/


#include<bits/stdc++.h>
using namespace std;

class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string s;
        for(int i=0; i<strs.size(); i++){

            s += to_string(strs[i].size()) + '#' + strs[i];
        }
        return s;
    }

    // Decodes a single string to a list of strings.
    //like 3#abc
    vector<string> decode(string s) {
        vector<string> ans;
        for(int i = 0; i < s.size();){
            int j = i;
            while(isdigit(s[j])) j++;
            int len = stoi(s.substr(i, j - i));
            ans.push_back(s.substr(j + 1, len));
            i = j + len + 1;
        }
        return ans;
    }

};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));

