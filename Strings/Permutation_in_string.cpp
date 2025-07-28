#include<bits/stdc++.h>
using namespace std;

int main(){
    string s1 = "ab", s2 = "eidbaooo";
    int left = 0, right = 0;
    unordered_map<char, int> hash;
    for(int i=0; i<s1.size(); i++){
        hash[s1[i]]++;
    }
    int required = s1.size();
    bool ache = false;
    while(right < s2.size()){
        hash[s2[right]]--;
        if(hash[s2[right]] >= 0){
            required--;
        }
        right++;
        while(required == 0){
            if(right - left == s1.size()){
                ache = true;
            }
            hash[s2[left]]++;
            if(hash[s2[left]] > 0){
                required++;
            }
            left++;
        }
    }
    cout << ache;
}