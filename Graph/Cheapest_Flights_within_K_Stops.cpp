/*
    Problem Link : https://leetcode.com/problems/cheapest-flights-within-k-stops/description/
    Problem Name : Cheapest Flights within K stops
    Difficulty   : Medium


    Date : 11-09-2025
    
-------------------------------------------------------------------------------------------------------


    There are n cities connected by some number of flights. You are given an array flights where 
    flights[i] = [from_i, to_i, price_i] indicates that there is a flight from city from_i to city 
    to_i with cost price_i.

    You are also given three integers src, dst, and k, return the cheapest price from src to dst 
    with at most k stops. If there is no such route, return -1.

    

    Example 1:


    Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], 
    src = 0, dst = 3, k = 1
    Output: 700
    Explanation:
    The graph is shown above.
    The optimal path with at most 1 stop from city 0 to 3 is marked in red and has 
    cost 100 + 600 = 700.
    Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.
    Example 2:


    Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
    Output: 200
    Explanation:
    The graph is shown above.
    The optimal path with at most 1 stop from city 0 to 2 is marked in red and has 
    cost 100 + 100 = 200.
    Example 3:


    Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 0
    Output: 500
    Explanation:
    The graph is shown above.
    The optimal path with no stops from city 0 to 2 is marked in red and has cost 500.
    

    Constraints:

    1 <= n <= 100
    0 <= flights.length <= (n * (n - 1) / 2)
    flights[i].length == 3
    0 <= from_i, to_i < n
    fromi != to_i
    1 <= price_i <= 10^4
    There will not be any multiple flights between two cities.
    0 <= src, dst, k < n
    src != dst


    */

#include<bits/stdc++.h>
using namespace std;

/*
    Using BFS approach

    Time Complexity: 

    Building the graph: O(E), where E is the number of flights.
    The BFS explores each city with up to k+1 stops:O(V⋅(k+1)), where V is the number of cities.
    For each (city, stops) pair, you might check all outgoing edges: O(E⋅(k+1)).
    So, total time complexity is O((V+E)⋅(k+1)).


    Space Complexity:

    Graph storage: O(E)
    minCost array: O(V⋅(k+1))
    Queue: up to O(V⋅(k+1))
    Total: O(E+V⋅(k+1)).
    
*/




class Solution {
public:

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Both of them are ok
        unordered_map<int, vector<pair<int, int>>> graph;
        // vector<vector<pair<int, int>>> graph;
        for(auto flight : flights){
            graph[flight[0]].push_back({flight[1], flight[2]});
        }

        queue<tuple<int, int, int>>q;
        q.push({src, 0, 0});

        vector<vector<int>> minCost(n, vector<int>(k+2, INT_MAX));
        int ans = INT_MAX;

        while(!q.empty()){ 

            int sz = q.size();
            for(int i=0; i<sz; i++){ 
                auto [city, cost, stops] = q.front();
                q.pop();
                if(stops > k) continue;
                for(auto [neighbor, price] : graph[city]){
                    
                    int nextCost = cost + price;
                    if(nextCost < minCost[neighbor][stops+1]){
                        minCost[neighbor][stops+1] = nextCost;
                        q.push({neighbor, nextCost, stops+1});
                    }
                }
            }
        }
        for(int stops=0; stops<=k+1; stops++){
            ans = min(ans, minCost[dst][stops]);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};