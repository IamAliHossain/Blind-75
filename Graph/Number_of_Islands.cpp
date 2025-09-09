/*
    Problem Link : https://leetcode.com/problems/number-of-islands/description/
    Problem Name : 200. Number of Islands
    Difficulty   : Medium


==================================================================================================

    Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

    An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

    

    Example 1:

    Input: grid = [
    ["1","1","1","1","0"],
    ["1","1","0","1","0"],
    ["1","1","0","0","0"],
    ["0","0","0","0","0"]
    ]
    Output: 1
    Example 2:

    Input: grid = [
    ["1","1","0","0","0"],
    ["1","1","0","0","0"],
    ["0","0","1","0","0"],
    ["0","0","0","1","1"]
    ]
    Output: 3
    

    Constraints:

    m == grid.length
    n == grid[i].length
    1 <= m, n <= 300
    grid[i][j] is '0' or '1'.

*/

/* Most optimal Solution is at the end */

#include<bits/stdc++.h>
using namespace std;

// This graph problem is solved using dfs traverse technique
// TC : O(n * m)
// SC : O(n * m)

class Solution {
public:
    void dfs(int i, int j, int n, int m, vector<vector<char>>& grid, vector<vector<bool>>& vis){
        if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == '0' || vis[i][j]) return;
        vis[i][j] = true;
        dfs(i+1, j, n, m, grid, vis); // down
        dfs(i-1, j, n, m, grid, vis); // up
        dfs(i, j+1, n, m, grid, vis); // right
        dfs(i, j-1, n, m, grid, vis); // left
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1' and !vis[i][j]){
                    dfs(i, j, n, m, grid, vis);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

/*

    TC : O(N * M)
    SC : O(N * M) for using extra visited vector

    it could be optimized to (1) we'll do in the next code

*/

class Solution {
public:
    bool isValid(int i, int j, int n, int m, int dx[], int dy[], vector<vector<char>>& grid, vector<vector<bool>>&visited){
        if(i >= n || i < 0 || j >= m || j < 0 || grid[i][j] != '1' || visited[i][j]) return false;
        return true;
    }
    void dfs(int i, int j, int n, int m, vector<vector<char>>& grid, vector<vector<bool>>&visited){
        
        visited[i][j] = true;
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};
        for(int k=0; k<4; k++){
            int ni = i + dx[k];
            int nj = j + dy[k];
            if(isValid(ni, nj, n, m, dx, dy, grid, visited)){
                dfs(ni, nj, n, m, grid, visited);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int cnt = 0 ;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(visited[i][j] || grid[i][j] != '1')continue;
                dfs(i, j, n, m, grid, visited);
                cnt++;
            }
        }
        return cnt;
    }
};


/*

    TC : O(N * M)
    SC : O(1) for excluding visited vector


*/

class Solution {
public:
    bool isValid(int i, int j, int n, int m, int dx[], int dy[], vector<vector<char>>& grid, vector<vector<bool>>&visited){
        if(i >= n || i < 0 || j >= m || j < 0 || grid[i][j] != '1' || visited[i][j]) return false;
        return true;
    }
    void dfs(int i, int j, int n, int m, vector<vector<char>>& grid, vector<vector<bool>>&visited){
        
        visited[i][j] = true;
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};
        for(int k=0; k<4; k++){
            int ni = i + dx[k];
            int nj = j + dy[k];
            if(isValid(ni, nj, n, m, dx, dy, grid, visited)){
                dfs(ni, nj, n, m, grid, visited);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int cnt = 0 ;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(visited[i][j] || grid[i][j] != '1')continue;
                dfs(i, j, n, m, grid, visited);
                cnt++;
            }
        }
        return cnt;
    }
};


/*--------------solution 3 the most optimal---------------------------------*/

/*

    TC : O(N * M)
    SC : O(N * M) for using extra visited vector

    it could be optimized to (1) we'll do in the next code

*/

class Solution {
public:
    bool isValid(int i, int j, int n, int m, int dx[], int dy[], vector<vector<char>>& grid){
        if(i >= n || i < 0 || j >= m || j < 0 || grid[i][j] != '1' ) return false;
        return true;
    }
    void dfs(int i, int j, int n, int m, vector<vector<char>>& grid){
        
        grid[i][j] = '0';
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};
        for(int k=0; k<4; k++){
            int ni = i + dx[k];
            int nj = j + dy[k];
            if(isValid(ni, nj, n, m, dx, dy, grid)){
                dfs(ni, nj, n, m, grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int cnt = 0 ;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] != '1')continue;
                dfs(i, j, n, m, grid);
                cnt++;
            }
        }
        return cnt;
    }
};