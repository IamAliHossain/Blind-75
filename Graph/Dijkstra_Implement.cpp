/*
    This problem is enlisted at DSA 450 cracker from GFG
    
    Problem Link : https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
    Problem Name : Dijkstra Algorithm
    Difficulty   : Medium

    Date : 12-09-2025
-----------------------------------------------------------------------------------------------------------
    Given an undirected, weighted graph with V vertices numbered from 0 to V-1 and E edges, represented by 2d array edges[][], where edges[i]=[u, v, w] represents the edge between the nodes u and v having w edge weight.
    You have to find the shortest distance of all the vertices from the source vertex src, and return an array of integers where the ith element denotes the shortest distance between ith node and source vertex src.

    Note: The Graph is connected and doesn't contain any negative weight edge.

    Examples:

    Input: V = 3, edges[][] = [[0, 1, 1], [1, 2, 3], [0, 2, 6]], src = 2
    Output: [4, 3, 0]
    Explanation:

    Shortest Paths:
    For 2 to 0 minimum distance will be 4. By following path 2 -> 1 -> 0
    For 2 to 1 minimum distance will be 3. By following path 2 -> 1
    For 2 to 2 minimum distance will be 0. By following path 2 -> 2
    Input: V = 5, edges[][] = [[0, 1, 4], [0, 2, 8], [1, 4, 6], [2, 3, 2], [3, 4, 10]], src = 0
    Output: [0, 4, 8, 10, 10]
    Explanation: 

    Shortest Paths: 
    For 0 to 1 minimum distance will be 4. By following path 0 -> 1
    For 0 to 2 minimum distance will be 8. By following path 0 -> 2
    For 0 to 3 minimum distance will be 10. By following path 0 -> 2 -> 3 
    For 0 to 4 minimum distance will be 10. By following path 0 -> 1 -> 4
    Constraints:
    1 ≤ V ≤ 105
    1 ≤ E = edges.size() ≤ 105
    0 ≤ edges[i][j] ≤ 104
    0 ≤ src < V
    Expected Complexities
    Time Complexity: O((V + E) log V)
    Auxiliary Space: O(V)


*/

#include<bits/stdc++.h>
using namespace std;

/*  
    V = number of vertices
    E = number of total edges
    
    🔹 Total Time Complexity
        Graph build: O(E)
        Initialization: O(V)
        PQ operations:
        Push: O(E log V)
        Pop: O(E log V)

        ✅ Total Time Complexity = O((V + E) log V)

    🔹 Space Complexity
        dist[]: O(V)
        Graph adjacency list: O(V + E)
        Priority queue: up to O(E) elements
        ✅ Total = O(V + E)

*/
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<int> dist(V, 1e9);
        vector<vector<pair<int,int>>> graph(V);
        
        // building the undirected graph 
        for(auto edge : edges){
            graph[edge[0]].push_back({edge[1], edge[2]});
            graph[edge[1]].push_back({edge[0], edge[2]});
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
        //pushing src node and edgeWeight
        pq.push({src, 0});
        dist[src] = 0 ;
        
        while(!pq.empty()){ // O(E)
            auto [node, weight] = pq.top();
            pq.pop(); 
            for(auto [neighbor, edgeWeight] : graph[node]){
                int nextEdgeWeight =weight + edgeWeight;
                if(nextEdgeWeight < dist[neighbor]){
                    dist[neighbor] = nextEdgeWeight;
                    pq.push({neighbor, nextEdgeWeight}); // logV
                }
            }
        }
        return dist;
    }
};