/*
    Sliding Window or Two pointers technique
    TC : O(n) , this trevers the string of |s|
    SC : O(n) , int the worst case we store all characters of the string
*/

#include<bits/stdc++.h>
using namespace std;

int maxLen(string s){
    int n = s.size() ;
    unordered_map<char, int> hash;
    int left = 0, right = 0 , longestLen = 0, cnt = 0 ;
    while(right < n){
        hash[s[right]]++;
        while(right - left > hash.size()){
            hash[s[left]]--;
            left++;
        }
        longestLen = max(longestLen, right + 1 - left);
        right++;
    }
    return longestLen;
}

int main(){
    // string s = "pwwkew";
    // // string s = "abcabcbb";
    string s = "auuu";
    // string s = "tmmzuxt";
    // // cout << s[0] << endl;
    
    unordered_map<char, int > hash;
    int left = 0, right = 0;
    vector<int> res;
    
    while(right < s.length()){
        // cout << "righchar : " << s[right] << ' ';
        hash[s[right]]++;
        // cout << " count: " << hash[s[right]] << ' ';
        while(hash[s[right]] > 1){
            // cout << "achire bhai achi : " << endl;
            hash[s[left]]--;
            left++;            
        }
        res.push_back((right - left + 1));
        right++;
    }
    
    sort(res.rbegin(), res.rend());
    cout << res[0] << endl;
}