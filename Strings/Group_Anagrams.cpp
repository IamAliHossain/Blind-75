/*
    Problem Link : https://leetcode.com/problems/group-anagrams/
    Problem Name : Group Anagrams
    Problem Diffi: Medium
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> res;
    unordered_map<string, vector<string> > hash;
    for(string u : strs){
        string cur = u;
        sort(cur.begin(), cur.end());
        hash[cur].push_back(u);
    }
    for(auto x : hash){
        res.push_back(x.second);
    }
    
    
    for(auto u: res){
        for(auto x : u){
            cout << x << ' ';
        }cout << endl;
    }
}