/*
    This Problem is from 450 DSA cracker list enlisted from LeetCode

    Problem Link : https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/
    Problem Naem : 1319. Number of Operations to Make Network Connected

    Difficulty   : Medium

    Date : 07-09-2025

-----------------------------------------------------------------------------------------------------

    There are n computers numbered from 0 to n - 1 connected by ethernet cables connections 
    forming a network where connections[i] = [ai, bi] represents a connection between 
    computers ai and bi. Any computer can reach any other computer directly or indirectly 
    through the network.

    You are given an initial computer network connections. You can extract certain cables 
    between two directly connected computers, and place them between any pair of 
    disconnected computers to make them directly connected.

    Return the minimum number of times you need to do this in order to make all the computers 
    connected. If it is not possible, return -1.

    

    Example 1:
    Input: n = 4, connections = [[0,1],[0,2],[1,2]]
    Output: 1

    Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3.
    
    Example 2:
    Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
    Output: 2

    Example 3:
    Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2]]
    Output: -1
    Explanation: There are not enough cables.
    

    Constraints:

    1 <= n <= 10^5
    1 <= connections.length <= min(n * (n - 1) / 2, 10^5)
    connections[i].length == 2
    0 <= ai, bi < n
    ai != bi
    There are no repeated connections.
    No two computers are connected by more than one cable.

*/



#include<bits/stdc++.h>
using namespace std;


/*

    1st of all I am checking total number of wires where
    number of wires = connections.size()

    if numberOfWires < connections.size()-1 : then connection is impossible

    TC : O(vertex + edges)
    SC : O(vertex)
*/

class Solution {
public:
    void dfs(int vertex, vector<vector<int>>& graph, vector<bool> &vis){
        vis[vertex] = true;
        for(auto child : graph[vertex]){
            if(vis[child])continue;
            dfs(child, graph, vis);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1) return -1;

        vector<bool> vis(n, false);
        vector<vector<int>>graph(n);
        for(auto edge : connections){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        int connected = 0;
        for(int i=0; i<n; i++){
            if(vis[i])continue;
            dfs(i, graph, vis);
            connected++;
        }
        return connected-1;
    }
};