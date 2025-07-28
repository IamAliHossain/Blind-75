/*
    Problem Link : https://leetcode.com/problems/alien-dictionary/description/
    Problem Name : 269. Alien Dictionary(Premium)
    Difficulty   : Medium
    Time Complexity : O(N * m) 
    Space Complexity : O(N * M) 

    Date : 24-05-2025
==================================================================================================

There is a new alien language that uses the English alphabet. However, the order of the letters is unknown to you.

You are given a list of strings words from the alien language's dictionary. Now it is claimed that the strings in words are sorted lexicographically by the rules of this new language.

If this claim is incorrect, and the given arrangement of string in words cannot correspond to any order of letters, return "".

Otherwise, return a string of the unique letters in the new alien language sorted in lexicographically increasing order by the new language's rules. If there are multiple solutions, return any of them.

 

Example 1:

Input: words = ["wrt","wrf","er","ett","rftt"]
Output: "wertf"
Example 2:

Input: words = ["z","x"]
Output: "zx"
Example 3:

Input: words = ["z","x","z"]
Output: ""
Explanation: The order is invalid, so return "".
 

Constraints:

1 <= words.length <= 100
1 <= words[i].length <= 100
words[i] consists of only lowercase English letters.

*/

#include<bits/stdc++.h>
using namespace std;

// This code need to be fixed
// class Solution {
// public:
//     bool dfs(int root, unordered_set<int> adj[], vector<int>& vis, vector<int>& callStack, stack<char> &st ){
//         vis[root] = 1;
//         callStack[root] = 1;
//         bool cycle = false;
//         for(auto &child : adj[root]){
//             if(child == root || (vis[child] && !callStack[child])) continue;
//             if(vis[child]) return true;
//             cycle |= dfs(child, adj, vis, callStack, st);
//         }
//         st.push(root + 'a');
//         callStack[root] = 0;
//         return cycle;
//     }
    
//     vector<int> topological(int node, unordered_set<int> adj[], vector<bool> &nodes){
//         vector<int> vis(26, 0), callStack(26);
//         stack<char> st;
//         for(int i=0; i<26; i++){
//             if(nodes[i] && !vis[i]){
//                 dfs(i, adj, vis, callStack, st);
//             }
//         }
//         vector<int> ans;
//         while(!st.empty()){
//             ans.push_back(st.top());
//             st.pop();
//         }
//         return ans;
//     }
//     string alienOrder(vector<string>& words) {

//         unordered_set<int> adj[26];
//         vector<bool> nodes(26);

//         for(int i=0; i<words.size()-1; i++){
//             string s1 = words[i];
//             string s2 = words[i+1];
//             for(auto ch : words[i]) nodes[ch - 'a'] = true;

//             bool insertion = true;
//             for(int j = 0; j<min(s1.size(), s2.size()); j++){
//                 if(s1[j] != s2[j]){
//                     adj[s1[j] - 'a'].insert(s2[j] - 'a');
//                     insertion = false;
//                     break;
//                 }
//             }
//             if(s1.size() > s2.size() && insertion) return "";
//         }

        
//         string s;
//         vector<int> ans = topological(26, adj, nodes);
//         for(auto u : ans){
//             s += u ;
//         }
//         return s ;
//     }
// };

//This is AC code

class Solution {
public:

    bool dfs(vector<int>& callStack, deque<char> &dq, vector<int>& vis, unordered_set<int> adj[], int root){
        vis[root] = 1;
        callStack[root] = 1;
        bool cycle = false;
        for(auto &child : adj[root]){
            if(child == root || (vis[child] && !callStack[child])) continue;
            if(vis[child]) return true;
            cycle |= dfs(callStack, dq , vis , adj , child);
        }
        dq.push_front(root + 'a');
        callStack[root] = 0;
        return cycle;
    }
    
    string alienOrder(vector<string>& words) {

        string order;
        unordered_set<int> adj[26];
        vector<bool> nodes(26) , inNodes(26);
        for(int i = 0;i < words.size() ; i++){
            for(auto ch : words[i]) nodes[ch - 'a'] = true;

            for(int j = i + 1;j < words.size();  j++){
                int k = 0 , pref = 1;
                while(k < min(words[i].size() , words[j].size())){
                    if(words[i][k] != words[j][k]){ 
                        adj[words[i][k] - 'a'].insert(words[j][k] - 'a');
                        pref = 0; break;
                    }
                    k++;
                }

                if(pref && words[i].size() > k) return order;
            }
        }

        deque<char> dq;
        vector<int> vis(26, 0) , callStack(26);
        for(int i = 0; i < 27; i++){
            if(nodes[i] && !vis[i]){
                if(dfs(callStack, dq , vis , adj , i)) return order;
            }
        }
        
        for(auto &it : dq) order.push_back(it);
        return order;
    }
};