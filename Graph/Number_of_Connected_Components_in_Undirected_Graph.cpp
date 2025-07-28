/*
    Problem Link : https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/description/
    Problem Name : 323. Number of Connected Components in an Undirected Graph (premium)
    Difficulty   : Medium
    Time Complexity : O(N + M) 
    Space Complexity : O(N + M) 

==================================================================================================

You have a graph of n nodes. You are given an integer n and an array edges where edges[i] = [ai, bi] indicates that there is an edge between ai and bi in the graph.

Return the number of connected components in the graph.

 

Example 1:


Input: n = 5, edges = [[0,1],[1,2],[3,4]]
Output: 2
Example 2:


Input: n = 5, edges = [[0,1],[1,2],[2,3],[3,4]]
Output: 1
 

Constraints:

1 <= n <= 2000
1 <= edges.length <= 5000
edges[i].length == 2
0 <= ai <= bi < n
ai != bi
There are no repeated edges.

*/

#include<bits/stdc++.h>
using namespace std;

/*

    Time Complexity : O(vertex + edges) = O(n + n-1) = O(2n)
    Space Complexity: O(vertex + edges) + O(n) for visited array : O(vertex + edges)

*/
class Solution {
public:
    void dfs(int vertex, vector<vector<int>>& g, vector<bool>& vis){
        vis[vertex] = true;
        for(auto child : g[vertex]){
            if(vis[child])continue;
            dfs(child, g, vis);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {  
        vector<vector<int>> g(n);
        vector<bool> vis(n, false);
        for(auto u : edges){
            g[u[0]].push_back(u[1]);
            g[u[1]].push_back(u[0]);
        }
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfs(i, g, vis);
                cnt++;
            }
        }
        return cnt;
    }
};