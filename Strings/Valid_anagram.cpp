#include<bits/stdc++.h>
using namespace std;


// solution using sliding window
int main(){
    string s ="ANAGRAM", t = "MARGANA";

    unordered_map<char, int> hash;
    for(char c : s){
        hash[c]++;
    }
    int left = 0, right = 0;
    int required = t.size();
    bool isAnagram = false;
    while(right < t.size()){
        hash[t[right]]--;
        if(hash[t[right]] >= 0){
            required--;
        }
        right++;
        while(required == 0){
            if(right - left == t.size()){
                isAnagram = true;
            }
            hash[t[left]]++;
            if(hash[t[left]] > 0){
                required++;
            }
            left++;
        }
    }
    cout << isAnagram << endl;
}


// solution 2
/*
TC : O(N) + O(N) : O(N)
SC : O(N) + O(N) : O(N)
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(t.size() != s.size()) return false;
        unordered_map<char, int> hashS, hashT;
        for(int i=0; i<s.size(); i++){
            hashS[s[i]]++;
        }
        for(int i=0; i<t.size(); i++){
            hashT[t[i]]++;
        }
        for(int i=0; i<t.size(); i++){
            if(hashS[t[i]] != hashT[t[i]]) return false;
        }
        return true;
    }
};

// solution 3
/*
    TC : O(nlogn)
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if(s == t)return true;
        return false;
    }
};