/*
    Problem Link : https://leetcode.com/problems/surrounded-regions/description/
    Problem Name : 130. Surrounded Regions
    Difficulty   : Medium
    Time Complexity : O(N * M) + O(m * N) + O(N * M) = O(N * M)
    Space Complexity : O(N * M) for visited array

    ================================================================================================
    
    You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:

    Connect: A cell is connected to adjacent cells horizontally or vertically.
    Region: To form a region connect every 'O' cell.
    Surround: The region is surrounded with 'X' cells if you can connect the region with 'X' cells and none of the region cells are on the edge of the board.
    To capture a surrounded region, replace all 'O's with 'X's in-place within the original board. You do not need to return anything.

    

    Example 1:

    Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]

    Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]

    Explanation:


    In the above diagram, the bottom region is not captured because it is on the edge of the board and cannot be surrounded.

    Example 2:

    Input: board = [["X"]]

    Output: [["X"]]

    

    Constraints:

    m == board.length
    n == board[i].length
    1 <= m, n <= 200
    board[i][j] is 'X' or 'O'.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    void dfs(int i, int j, int n, int m, vector<vector<char>> &board, vector<vector<bool>> &visited){
        visited[i][j] = true;
        // if(i<0 || j<0 || i+1>=n || j+1 >= m) return; // eta use korle if er vitore i,j condition lagbena
        // echarao int dx[] = {-1, 0, 1, 0} and int dy [] = {0, -1, 0, 1} use koreo kora jay movement
        
        if(i> 0 && board[i-1][j] == 'O' and !visited[i-1][j]){
            dfs(i-1, j, n, m, board, visited);
        }
        if(i+1<n && board[i+1][j] == 'O' and !visited[i+1][j]){
            dfs(i+1, j, n, m, board, visited);
        }
        if(j > 0 && board[i][j-1] == 'O' and !visited[i][j-1]){
            dfs(i, j-1, n, m, board, visited);
        }
        if(j+1 < m && board[i][j+1] == 'O' and !visited[i][j+1]){
            dfs(i, j+1, n, m, board, visited);
        }
        
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        if(n == 0) return;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for(int i=0; i<n; i++){
            if(board[i][0] == 'O' && !visited[i][0]){
                dfs(i, 0, n, m, board, visited);
            }
            if(board[i][m-1] == 'O' && !visited[i][m-1]){
                dfs(i, m-1, n, m, board, visited);
            }
        }
        
        for(int j=0; j<m; j++){
            if(board[0][j] == 'O' && !visited[0][j]){
                dfs(0, j, n, m, board, visited);
            }
            if(board[n-1][j] == 'O' && !visited[n-1][j]){
                dfs(n-1, j, n, m, board, visited);
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!visited[i][j] && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
        
    }
};