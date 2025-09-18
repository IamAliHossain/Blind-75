/*

    This problem is enlisted at DSA 450 cracker from GFG
    
    Problem Link : https://www.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1
    Problem Name : M-Coloring Problem
    Difficulty   : Medium

    Date : 18-09-2025
-----------------------------------------------------------------------------------------------------------
    
    You are given an undirected graph consisting of V vertices and E edges represented 
    by a list edges[][], along with an integer m. Your task is to determine whether it 
    is possible to color the graph using at most m different colors such that no two 
    adjacent vertices share the same color. Return true if the graph can be colored 
    with at most m colors, otherwise return false.

    Note: The graph is indexed with 0-based indexing.

    Examples:

    Input: V = 4, edges[][] = [[0, 1], [1, 3], [2, 3], [3, 0], [0, 2]], m = 3
    Output: true
    Explanation: It is possible to color the given graph using 3 colors, for example,
     
    one of the possible ways vertices can be colored as follows:

    Vertex 0: Color 1
    Vertex 1: Color 2
    Vertex 2: Color 2
    Vertex 3: Color 3
    Input: V = 3, edges[][] = [[0, 1], [1, 2], [0, 2]], m = 2
    Output: false
    Explanation: It is not possible to color the given graph using only 2 colors 
    because vertices 0, 1, and 2 form a triangle.

    Constraints:
    1 ≤ V ≤ 10
    1 ≤ E = edges.size() ≤ (V*(V-1))/2
    0 ≤ edges[i][j] ≤ V-1
    1 ≤ m ≤ V

    Expected Complexities
    Time Complexity: O(V * m ^ V)
    Auxiliary Space: O(V + E)

    Company Tags:
    Amazon

*/

#include<bits/stdc++.h>
using namespace std;

/*
    


    Time Complexity : 

    Then calls backtracking: O(m^V · V).
    So, total =
    O(V+E+mV⋅V)≈O(mV⋅V)
    (for large V, exponential dominates).


    Space Complexity:

    Graph construction: O(V + E)
    Color array = O(V).
    Recursion depth = O(V).
    So total space = O(V+E)


    ✅ Final Complexity:

        Time = O(m^V · V)
        Space = O(V + E)
*/


class Solution {
  public:
    
    bool isSafe(int vertex, vector<vector<int>> &graph, int clor, vector<int> &color){
        for(auto edge : graph[vertex]){
            if(color[edge] == clor){
                return false;
            }
        }
        return true;
    }
    
    // O(V * M ^ V)
    bool colorTheGraph(int vertex, int V, vector<vector<int>> &graph, int m, vector<int> &color){
        if(vertex == V) return true;
        
        for(int clor = 1; clor <= m; clor++){
            if(isSafe(vertex, graph, clor, color)){ // checking that is it possible to use clor at this vertex
                color[vertex] = clor;
                if(colorTheGraph(vertex+1, V, graph, m, color)){
                    return true;
                }
                // If assigning color c doesn't lead to a solution then remove it 
                color[vertex] = 0;
            }
        }
        return false;
    }
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
    
        // building graph
        
        vector<vector<int>> graph(v); // O(V + Edge)
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        // coloring all vertices 0 first
        vector<int> color(v+1, 0); // O(V)
        
        return colorTheGraph(0, v, graph, m, color);
        
    }
};