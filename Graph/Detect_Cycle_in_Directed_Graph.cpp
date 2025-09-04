/*
      This Problem is from 450 DSA cracker list enlisted from coding ninja platform

    Problem Link : https://www.naukri.com/code360/problems/detect-cycle-in-a-directed-graph_920545?topList=love-babbar-dsa-sheet-problems&utm_source=website&utm_medium=affiliate&utm_campaign=450dsatracker&leftPanelTabValue=PROBLEM
    Problem Naem : Detect Cycle in a Directed Graph
    Difficulty   : Medium

    Date : 04-09-2025

----------------------------------------------------------------------------------------------------

Problem statement
    Given a directed graph, check whether the graph contains a cycle or not. 
    Your function should return true if the given graph contains at least one cycle, 
    else return false.

    Detailed explanation ( Input/output format, Notes, Images )
    Constraints:
    1 <= T <= 10
    1 <= V <= 10^3
    0 <= E <= 10^3
    0 <= A, B < V

    Time Limit: 1 sec
    Sample Input 1:.
    2
    4 4
    0 1
    1 2
    2 3
    3 0
    3 3
    1 0
    1 2
    0 2
    Sample Output 1:
    true
    false
    Explanation for Sample Input 1:
    In the first case,
    From node 0 we can reach 0 again by following this sequence of nodes in the 
    path: 0,1,2,3,0. As we can see in the image below.

    In the second case,
    There is no cycle in the given graph. As we can see in the image below.

    Sample Input 2:
    2
    3 2
    0 1
    0 2
    3 3
    1 1
    0 2
    1 2
    Sample Output 2:
    false
    true


*/


#include<bits/stdc++.h>
using namespace std;

/*
    N = number of nodes
    E = number of edges

    TC : O(N + E)
    SC : O(N) for creating queue and array indegree.
*/

bool isCyclic(vector<vector<int>>& edges, int v, int e)
{	
	
	vector<vector<int>> graph(v);
	vector<int> indegree(v, 0);
	for(auto edge : edges){
		int x = edge[0];
		int y = edge[1];
		graph[x].push_back(y);
		indegree[y]++;
	}
	queue<int> q;
	// jader kono dependency nai(means indegree tar zero) tader ke q te nibo age
	for(int i=0; i<v; i++){
		if(indegree[i] == 0){
			q.push(i);
		}
	}
	int visited = 0;
	while(!q.empty()){
		int curr = q.front();
		q.pop();
		visited++;
		for(auto u : graph[curr]){
			indegree[u]--;
			if(indegree[u] == 0){
				q.push(u);
			}
		}
	}
	return visited != v;
}
