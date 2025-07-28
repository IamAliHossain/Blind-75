/*
    Problem Link : https://leetcode.com/problems/course-schedule/
    Problem Name : 207. Course Schedule
    Difficulty   : Medium
    Time Complexity : 
    Space Complexity :
    ================================================================================================

    There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

    For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
    Return true if you can finish all courses. Otherwise, return false.


    Example 1:

    Input: numCourses = 2, prerequisites = [[1,0]]
    Output: true
    Explanation: There are a total of 2 courses to take. 
    To take course 1 you should have finished course 0. So it is possible.
    Example 2:

    Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
    Output: false
    Explanation: There are a total of 2 courses to take. 
    To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
    

    Constraints:

    1 <= numCourses <= 2000
    0 <= prerequisites.length <= 5000
    prerequisites[i].length == 2
    0 <= ai, bi < numCourses
    All the pairs prerequisites[i] are unique.

*/

// solution 1

/*
    This problem indicates finding cycles in a directed graph since we need to take
    course and that course has a prerequisite course also, so need to check that if 
    there is cycle or not, if not then we can finish all the courses, other wise because of
    cycle we can't finish all the courses

    1->2 2->3 3->1 : this will make a directed graph which has a cycle, so in this case 
    we can't finish all the courses

    N = nodes(numCourse)
    E = edges(prerequisite.size())
    TC : O(N + E)
    SC : O(N) for visited + O(N) for pathVisited + O(N + E) for adj list
    so SC : O(N + E)
    

*/

class Solution {
public:
    // dfs technique to detect cycle have or not in a directed graph
    bool isCycle(int vertex, vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &pathVisited){
        visited[vertex] = true;
        pathVisited[vertex] = true;

        for(auto child : adj[vertex]){
            if(!visited[child]){
                bool cycleFound = isCycle(child, adj, visited, pathVisited);
                if(cycleFound)return true;
            }
            else{
                if(pathVisited[child])return true;
            }
            
        }
        pathVisited[vertex] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;

        vector<vector<int>> adj(n);
        // since there is prerequisite so this is a directed graph
        for(auto it : prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        vector<bool> visited(n, false), pathVisited(n, false);
        for(int i=0; i<numCourses; i++){
            if(!visited[i]){
                bool cycleFound = isCycle(i, adj, visited, pathVisited);
                // when cycle is found we can't finish all the courses so return false
                if(cycleFound){
                    return false;
                }
            }
        }
        return true;

    }
};

// solution 2
/*

    Solution Technique BFS using topological sort idea:
    Breaking down the intuition step by step:

    We construct a directed graph where each node is a course, and edges represent prerequisites (a directed edge from course b to course a means b is a prerequisite for a).
    We count incoming edges (indegrees) for each node. If a node/course has no incoming edges, it means there are no prerequisites, and it can be taken immediately.
    We repeatedly pick and remove nodes with no incoming edges (representing courses with all prerequisites completed or no prerequisites at all) and remove all edges from these nodes to other nodes (simulating taking the course and fulfilling those prerequisites).
    If we manage to remove all nodes (take all courses), then it's possible to finish all courses.

*/

#include<bits/stdc++.h>
using namespace std;

/*
    N = nodes(numCourse)
    E = edges(prerequisite.size())
    TC : O(N + E)
    SC : O(N) for visited + O(N) for pathVisited + O(N + E) for adj list
    so SC : O(N + E)
*/

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses);

        for(auto &courses : prerequisites){
            graph[courses[1]].push_back(courses[0]);
            indegree[courses[0]]++;  // Increment indegree of the courseToTake
        }
        queue<int> noPrereqCourses;
        for(int i=0; i<numCourses; i++){
            if(indegree[i] == 0){
                noPrereqCourses.push(i);
            }
        }
        int courseTaken = 0;
        while(!noPrereqCourses.empty()){
            int current = noPrereqCourses.front();
            noPrereqCourses.pop();
            courseTaken++;

            for(auto child : graph[current]){
                indegree[child]--;
                if(indegree[child] == 0){
                    noPrereqCourses.push(child);
                }
            }
        }
        return courseTaken == numCourses;
    }
};