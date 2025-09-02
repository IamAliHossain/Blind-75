/*
            This problem is not from blind75, 450 DSA cracker enlisted it from GFG

    Problem Link : https://www.naukri.com/code360/problems/is-graph-tree_1115787?topList=love-babbar-dsa-sheet-problems&utm_source=website&utm_medium=affiliate&utm_campaign=450dsatracker&leftPanelTabValue=PROBLEM

    Problem Name :  Is Graph Tree?
    Difficulty   : Medium
    
    Author : Ali Hossain
    Date : 02-09-2025
==============================================================================================

    Problem statement

    Ben Tennyson recently joined Coding Ninjas to become better at competitive programming.

    To check whether Ben is seriously studying in Coding Ninjas or not, Gwen challenged Ben 
    to solve a problem and Ben accepts the challenge of Gwen.

    Gwen gives Ben an undirected graph of ‘N’ nodes numbered from 0 to ‘N - 1’ having ‘M’ edges. 
    The task of Ben is to check whether the graph given by Gwen is a tree or not.

    As Ben is busy fighting with Evil doers so he asked you to solve this problem.

    Note :
    There are no parallel edges and self-loops in the graph given by Gwen.

    A tree is a connected graph having no cycles.
    Detailed explanation ( Input/output format, Notes, Images )
    Constraints :
    1 <= T <= 5
    1 <= N <= 5000
    1 <= M <= min(5000, N*(N-1)/2)
    1 <= U, V<= N - 1
    Sample Input 1:
    2
    7 6
    0 1
    0 4
    1 2
    1 3
    4 5
    4 6
    3 3
    0 1
    0 2
    1 2
    Sample Output 1:
    1 
    0

    Explanation For Sample Input 1:
    Test Case 1 :  
    The given graph is shown below. 

    The above graph is a connected graph with no cycles. Hence this graph is a tree. 
    So we need to print 1.

    Test Case 2 : 
    The given graph is shown below.

    Above graph is a connected graph but it contains a cycle : 0 -> 1 -> 2 .Hence this graph 
    is not a tree. So we need to print 0.

    Sample Input 2:
    2
    4 3
    0 1
    0 2
    3 2
    5 5
    0 1
    0 3
    2 1
    2 3
    1 4
    Sample Output 2:
    1
    0



*/

#include <bits/stdc++.h> 
using namespace std;

/*
    DFS solution 

    To validate a graph as tree, we must need to check cycle, connected component number

    A valid tree does not have any cycle and contain only one connected component that means
    it has exactly n-1 edges total

    TC : O(N)
    SC : O(N)


*/


bool dfs(bool &isCycleExist, int vertex, int par, vector<vector<int>> &graph, vector<bool> &visited){
	
	visited[vertex] = true;

	for(auto child : graph[vertex]){
		if(visited[child] && child == par){
			continue;
		}
		if(visited[child]){
			isCycleExist = true;
			return true;
		}
		dfs(isCycleExist, child, vertex, graph, visited);
	}

	return isCycleExist;
}

bool isGraphTree(int n, vector<vector<int>> &edgeList)
{	
	if(edgeList.size() != n-1){
		return false;
	}

	vector<vector<int>> graph(n);
	vector<bool> visited(n, false);
	
	for(auto edge : edgeList){
		int x = edge[0];
		int y = edge[1];
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	bool isCycleExist = false;
	for(int i=0; i<n; i++){
		if(visited[i])continue;
		if(dfs(isCycleExist, i, -1, graph, visited)){
			return false;
		}
	}
	// This checking for more than one connected component
	// because if any vertex is missing to visited that
	// means there must more than one connect components

	for (bool v : visited){
		if (!v) return false;
	} 
	return true;
}