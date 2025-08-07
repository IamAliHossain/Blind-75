/*  
    This Problem is not Listed In Blind75 it's from NeetCode-150 graph

    Problem Link : https://leetcode.com/problems/max-area-of-island/description/
    Problem Name : 695. Max Area of Island
    Difficulty   : Medium
    Time Complexity : 
    Space Complexity :
    
    Date : 7 August 2025
    ================================================================================================



    You are given an m x n binary matrix grid. An island is a group of 1's (representing land) 
    connected 4-directionally (horizontal or vertical.) You may assume all four edges of the 
    grid are surrounded by water.

    The area of an island is the number of cells with a value 1 in the island.

    Return the maximum area of an island in grid. If there is no island, return 0.

    

    Example 1:


    Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
    Output: 6
    Explanation: The answer is not 11, because the island must be connected 4-directionally.
    Example 2:

    Input: grid = [[0,0,0,0,0,0,0,0]]
    Output: 0
    

    Constraints:

    m == grid.length
    n == grid[i].length
    1 <= m, n <= 50
    grid[i][j] is either 0 or 1.


*/

#include<bits/stdc++.h>
using namespace std;

    // Solution 1 to memory optimization see Solution 2 below
/*
    Soluiton is my own
    N = num of rows
    M = num of cols
    
    TC : O(N * M)
    SC : O(N * M) for using visited array

    SC : O(1) is possible so see the next code
*/

class Solution {
public:

    void dfs(int i, int j, int n, int m, vector<vector<int>>& grid, vector<vector<int>>& vis, int &area){
        
        if(i < 0 || j < 0 || i >= n || j >= m || vis[i][j]  || grid[i][j] == 0)  return ;
        vis[i][j] = true;
        area++;
        dfs(i+1, j, n, m, grid, vis, area);
        dfs(i-1, j, n, m, grid, vis, area);
        dfs(i, j+1, n, m, grid, vis, area);
        dfs(i, j-1, n, m, grid, vis, area);  
            
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, false));

        int mxArea = 0;
        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    int area = 0;
                    dfs(i, j, n, m, grid, vis, area);
                    mxArea = max(mxArea, area);
                }  
            }
        }
        return mxArea;

    }
};

    // Solution 2

/*  
    Soluiton is my own
    N = num of rows
    M = num of cols
    
    TC : O(N * M)
    SC : O(1) since I don't need grid value more than once we can put grid[i][j] = 0 where grid[i][j] = 1 after calculation

    hence Space Complexity is reduced O(N * M) to O(1)
*/

class Solution {
public:

    void dfs(int i, int j, int n, int m, vector<vector<int>>& grid, int &area){
        
        if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0)  return ;
        grid[i][j] = 0;
        area++;
        dfs(i+1, j, n, m, grid, area);
        dfs(i-1, j, n, m, grid, area);
        dfs(i, j+1, n, m, grid, area);
        dfs(i, j-1, n, m, grid, area);  
            
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int mxArea = 0;
        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    int area = 0;
                    dfs(i, j, n, m, grid, area);
                    mxArea = max(mxArea, area);
                }  
            }
        }
        return mxArea;

    }
};