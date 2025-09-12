/*
    This problem is enlisted at DSA 450 cracker from GFG
    
    Problem Link : https://leetcode.com/problems/network-delay-time/description/
    Problem Name : 743. Network Delay Time
    Difficulty   : Medium

    Date : 12-09-2025
-----------------------------------------------------------------------------------------------------------
    
    You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of 
    travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is 
    the target node, and wi is the time it takes for a signal to travel from source to target.

    We will send a signal from a given node k. Return the minimum time it takes for all the 
    n nodes to receive the signal. If it is impossible for all the n nodes to receive the 
    signal, return -1.

    

    Example 1:


    Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
    Output: 2
    Example 2:

    Input: times = [[1,2,1]], n = 2, k = 1
    Output: 1
    Example 3:

    Input: times = [[1,2,1]], n = 2, k = 2
    Output: -1
    

    Constraints:

    1 <= k <= n <= 100
    1 <= times.length <= 6000
    times[i].length == 3
    1 <= ui, vi <= n
    ui != vi
    0 <= wi <= 100
    All the pairs (ui, vi) are unique. (i.e., no multiple edges.)

*/

#include<bits/stdc++.h>
using namespace std;

/*
    This problem is the practice problem for Dijkstra Algorithm practice

    V  = number of total vertices
    E = number of edges

    for building directed graph time and space complexity : O(E)
    for minTime array time and space complexity : O(V)
    for Priority queue time and space complexity up to O(E) elements

    Time-Complexity : O(E) + O(V) + O(E * log(V))
    over-all TC : O((V + E) * log(V))

    Space Complexity : O(E) + O(V)
        SC : O(V + E)


*/

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<pair<int, int>>> graph(n+1);
        // building the directed graph
        for(auto edge : times){
            int u = edge[0];
            int v = edge[1];
            int time = edge[2];
            graph[u].push_back({v, time});
        }
        vector<int> minTime(n+1, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
        pq.push({k, 0});
        minTime[k] = 0;
        
        while(!pq.empty()){ // O(E)
            auto [node, time] = pq.top();
            pq.pop();
            for(auto [neighbor, edgeTime] : graph[node]){
                int nextEdgeTime = time + edgeTime;
                if(nextEdgeTime < minTime[neighbor]){
                    minTime[neighbor] = nextEdgeTime;
                    pq.push({neighbor, nextEdgeTime}); // O(logV)
                }
            }
        }
        int delay = 0;
        for(int i=1; i<=n; i++){
            delay = max(delay, minTime[i]);
        }
        return delay == INT_MAX ? -1 : delay ;
    }
};