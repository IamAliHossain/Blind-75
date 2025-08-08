/* 
    This Problem is from Neetcode-150 series

    Problem Link : https://leetcode.com/problems/rotting-oranges/description/
    Problem Naem : 994. Rotting Oranges
    Difficulty   : Medium

    Date : 08-08-2025


    "This Problem made me understand where to use BFS and why?
    so very helpful problem was it though little bit tougher"



    You are given an m x n grid where each cell can have one of three values:

    0 representing an empty cell,
    1 representing a fresh orange, or
    2 representing a rotten orange.
    Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

    Return the minimum number of minutes that must elapse until no cell has a fresh 
    orange. 
    If this is impossible, return -1.

 

Example 1:


Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:

Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
Example 3:

Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 10
grid[i][j] is 0, 1, or 2.

*/


#include<bits/stdc++.h>
using namespace std;

/*
    Every minute, any fresh orange that is 4-directionally 
    adjacent to a rotten orange becomes rotten.
    অর্থাৎ যদি gri[i][j] = 2 পাওয়া যায় তাহলে সবগুলা 2 একসাথে যাবে 1 গুলাকে 2 করতে
    simultaneously korte thake ar ei karonei Need To use BFS here

    TC : O(4 * N * M) ~= O(N * M)
    SC : O(N * M)


*/


class Solution {
public:
    void bfs(queue<pair<pair<int, int>, int>> &q, int n, int m, vector<vector<int>>& grid, vector<vector<int>>& vis, int &time){
        while(q.size()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            time = max(time, t);
            q.pop();

            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, 1, 0, -1};
            for(int i=0; i<4; i++){
                int nr = r + dx[i];
                int nc = c + dy[i];
                if(nr >=0 && nr <n && nc >=0 && nc <m && vis[nr][nc] == 0 && grid[nr][nc] == 1){
                    q.push({{nr, nc}, time+1});
                    vis[nr][nc] = 2;
                }
            }
        }
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        queue<pair<pair<int, int>, int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                   q.push({{i, j}, 0});
                   vis[i][j] = 2;
                }
                else{
                    vis[i][j] = 0;
                }
            }
        }
        int time = 0;
        bfs(q, n, m, grid, vis, time);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis[i][j] != 2 && grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return time;
    }
};