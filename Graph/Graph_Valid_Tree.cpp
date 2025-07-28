/*
    Problem Link : https://leetcode.com/problems/graph-valid-tree/description/
    Problem Name : 261. Graph Valid Tree (premium)
    Difficulty   : Medium
    Time Complexity : O(N + M) 
    Space Complexity : O(N + M) 

==================================================================================================

You have a graph of n nodes labeled from 0 to n - 1. You are given an integer n and a list of edges where edges[i] = [ai, bi] indicates that there is an undirected edge between nodes ai and bi in the graph.

Return true if the edges of the given graph make up a valid tree, and false otherwise.

 

Example 1:


Input: n = 5, edges = [[0,1],[0,2],[0,3],[1,4]]
Output: true
Example 2:


Input: n = 5, edges = [[0,1],[1,2],[2,3],[1,3],[1,4]]
Output: false
 

Constraints:

1 <= n <= 2000
0 <= edges.length <= 5000
edges[i].length == 2
0 <= ai, bi < n
ai != bi
There are no self-loops or repeated edges.

*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(int vertex, int par, vector<vector<int>>& g, vector<bool> &vis){
        if(vis[vertex]) return false;
        vis[vertex] = true;
        for(auto child : g[vertex]){
            if(child != par && !dfs(child, vertex, g, vis)) return false;
        }
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<bool> vis(n, false);
        vector<vector<int>>g(n);
        for(auto edge : edges){
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }

        if(!dfs(0, -1, g, vis)){
            return false;
        }
        for(bool u : vis){
            if(!u)return false;
        }
        return true;
        
    }
};