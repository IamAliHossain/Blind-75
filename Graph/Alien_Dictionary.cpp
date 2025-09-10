/*
    Problem Link : https://leetcode.com/problems/alien-dictionary/description/
    Problem Name : 269. Alien Dictionary(Premium)
    Difficulty   : Hard
    Time Complexity : O(N * m) 
    Space Complexity : O(N * M) 

    Date : 24-05-2025
==================================================================================================

    There is a new alien language that uses the English alphabet. However, the order of the letters 
    is unknown to you.

    You are given a list of strings words from the alien language's dictionary. Now it is claimed 
    that the strings in words are sorted lexicographically by the rules of this new language.

    If this claim is incorrect, and the given arrangement of string in words cannot correspond to 
    any order of letters, return "".

    Otherwise, return a string of the unique letters in the new alien language sorted in 
    lexicographically increasing order by the new language's rules. If there are multiple 
    solutions, return any of them.


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
//This is using BFS + Topological solution technique

/*
    N = words.size
    L = words[i].size

    TC : O(N * L) + O(26) + O(26 * 26 * 25) + O(26) 
        : O(N * L)
    SC : O(26 * 26) ~= O(1)

*/
class Solution {
  public:
    string findOrder(vector<string> &words) {
        
        vector<vector<int>> graph(26);
        vector<int> indegree(26, 0);
        vector<bool> present(26, false);
        
        //Marking all letters present in the current words
        for(auto word : words){
            for(auto ch : word){
                present[ch - 'a'] = true;
            }
        }
        
        // Building directed graph
        for(int i=0; i<words.size()-1; i++){ // O(N)
            
            string s1 = words[i];
            string s2 = words[i+1];
            int k = 0;
            bool found = false;
            
            while(k < min(s1.size(), s2.size())){ // O(L)
                if(s1[k] != s2[k]){ 
                    graph[s1[k] - 'a'].push_back(s2[k]-'a');
                    indegree[s2[k] - 'a']++;
                    found = true;
                    break;
                }
                k++;
            }
            // invalid case like : abc ab, it's violate the condition
            if(!found && s1.size() > s2.size()) return ""; 
        }
        
        // Doing Topological sort
        queue<int> q;
        for(int i=0; i<26; i++){ // O(26)
            if(present[i] && indegree[i] == 0){
                q.push(i);
            }
        }
        
        string ans = "";
        while(!q.empty()){ // O(26)
            int curr = q.front();
            q.pop();
            ans += (curr + 'a');
            for(auto neighbor : graph[curr]){ // O(26 * 25)
                indegree[neighbor]--;
                if(indegree[neighbor] == 0){
                    q.push(neighbor);
                }
            }
        }
        int letter_cnt = 0;
        for(int i=0; i<26; i++){ // O(26)
            if(present[i]){
                letter_cnt++;
            }
        }
        // jotogula letter ache tar sob jodi ans string a na pawa jay taile cycle pawa geche
        // r cycle pawa geche mane dictionary thik kore neya possible na
        if(ans.size() < letter_cnt) return "";
        
        return ans;
    }
};


//This is using DFS solution technique

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