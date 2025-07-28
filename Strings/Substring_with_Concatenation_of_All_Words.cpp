#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int > hash, hashTemp;
        for(auto u : words){
            hash[u]++;
        }
        int word_size = words[0].size();
        int window_size = word_size * words.size();
        int left = 0, right = 0;
        int required = words.size();
        vector<int> ans;
        if(s.size() < window_size)return ans;
        for(right = 0; right<=(s.size()-window_size); right++){
            left = right;
            for(int len=1; len<= required; len++){
                string curString = s.substr(left, word_size);
                hashTemp[curString]++;
                left += word_size;
            }
            if(hash == hashTemp)ans.push_back(right);
            hashTemp.clear();
        }
        return ans;
    }
};

int main(){
    
}