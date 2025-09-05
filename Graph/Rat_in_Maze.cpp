/*
      This Problem is from 450 DSA cracker list enlisted from GFG

    Problem Link : https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
    Problem Naem : Rat in a Maze Problem - I

    Difficulty   : Medium

    Date : 05-09-2025

----------------------------------------------------------------------------------------------------

    Consider a rat placed at position (0, 0) in an n x n square matrix mat[][]. The rat's goal is to reach the destination at position (n-1, n-1). The rat can move in four possible directions: 'U'(up), 'D'(down), 'L' (left), 'R' (right).

    The matrix contains only two possible values:

    0: A blocked cell through which the rat cannot travel.
    1: A free cell that the rat can pass through.
    Your task is to find all possible paths the rat can take to reach the destination, starting from (0, 0) and ending at (n-1, n-1), under the condition that the rat cannot revisit any cell along the same path. Furthermore, the rat can only move to adjacent cells that are within the bounds of the matrix and not blocked.
    If no path exists, return an empty list.

    Note: Return the final result vector in lexicographically smallest order.

    Examples:

    Input: mat[][] = [[1, 0, 0, 0], [1, 1, 0, 1], [1, 1, 0, 0], [0, 1, 1, 1]]
    Output: ["DDRDRR", "DRDDRR"]
    Explanation: The rat can reach the destination at (3, 3) from (0, 0) by two paths - DRDDRR and DDRDRR, when printed in sorted order we get DDRDRR DRDDRR.
    Input: mat[][] = [[1, 0], [1, 0]]
    Output: []
    Explanation: No path exists as the destination cell is blocked.
    Input: mat = [[1, 1, 1], [1, 0, 1], [1, 1, 1]]
    Output: ["DDRR", "RRDD"]
    Explanation: The rat has two possible paths to reach the destination: 1. "DDRR" 2. "RRDD", These are returned in lexicographically sorted order.
    Constraints:
    2 ≤ mat.size() ≤ 5
    0 ≤ mat[i][j] ≤ 1

    Expected Complexities
    Time Complexity: O(4 ^ (n * n))
    Auxiliary Space: O(n * n)

*/

#include<bits/stdc++.h>
using namespace std;

/*
    TC : O(4^(n * n)) for exploring all possible path 
        + O(nlogn) for sorting ans
    overral TC : O(4^(n * n))

    SC : O(n * n)

*/

class Solution {
  public:
    void dfs(int i, int j, int n, int m, vector<vector<int>>& grid, vector<vector<bool>>& vis, vector<string>& ans, string res ){
        
        if(i > n-1 || j > m-1 || i<0 || j<0 || grid[i][j] == 0 || vis[i][j]) return;
        
        if(i == n-1 && j == m-1){
            ans.push_back(res);
            return;

        }
        vis[i][j] = true;
        dfs(i+1, j, n, m, grid, vis, ans, res+"D");
        dfs(i-1, j, n, m, grid, vis, ans, res+"U");
        dfs(i, j+1, n, m, grid, vis, ans, res+"R");
        dfs(i, j-1, n, m, grid, vis, ans, res+"L");
        
        vis[i][j]=false;

    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        int n = maze.size();
        int m = maze[0].size();
        vector<vector<bool>>vis(n, vector<bool> (m, false));
        vector<string> ans;
        
        dfs(0, 0, n, m, maze, vis, ans, "");
        sort(ans.begin(), ans.end());
        return ans;
        
    }
};


/* 
    For better understanding the move see dry run of dfst trace table followed by

    maze =[
            [1, 0, 0, 0],
            [1, 1, 0, 1],
            [1, 1, 0, 0],
            [0, 1, 1, 1]
        ]
    Target: (3,3).
    
    DFS Trace Table Format
    Step	i,j	    PathSoFar(res)	    Move Called	    Action/Comment
    1	    0,0	    ""	                D	            Move down to (1,0)
    2	    1,0	    "D"	                D	            Move down to (2,0)
    3	    2,0	    "DD"	            D	            (3,0) blocked → return
    4	    2,0	    "DD"	            U	            (1,0) visited → return
    5	    2,0	    "DD"	            R	            Move right to (2,1)
    6	    2,1	    "DDR"	            D	            Move down to (3,1)
    7	    3,1	    "DDRD"	            D	            (4,1) out of bounds → return
    8	    3,1	    "DDRD"	            U	            (2,1) visited → return
    9	    3,1	    "DDRD"	            R	            Move right to (3,2)
    10	    3,2	    "DDRDR"	            D	            (4,2) out of bounds → return
    11	    3,2	    "DDRDR"	            U	            (2,2) blocked → return
    12	    3,2	    "DDRDR"	            R	            Move right to (3,3) → target reached → add "DDRDRR"
    13	    3,3	    "DDRDRR"	        -	            Path complete, backtrack to (3,2)
    14	    3,2	    "DDRDR"	            L	            (3,1) visited → return
    15	    3,1	    "DDRD"	            L	            (3,0) blocked → return
    16	    2,1	    "DDR"	            L	            (2,0) visited → return
    17	    2,0	    "DD"	            L	            (2,-1) invalid → return, backtrack to (1,0)
    18	    1,0	    "D"	                U	            (0,0) visited → return
    19	    1,0	    "D"	                R	            Move right to (1,1)
    20	    1,1	    "DR"	            D	            Move down to (2,1)
    21	    2,1	    "DRD"	            D	            Move down to (3,1)
    22	    3,1	    "DRDD"	            R	            Move right to (3,2)
    23	    3,2	    "DRDDR"	            R	            Move right to (3,3) → target reached → add "DRDDRR"
    24	    3,3	    "DRDDRR"	        -	            Path complete, backtrack



*/