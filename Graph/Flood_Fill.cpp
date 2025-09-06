/*
      This Problem is from 450 DSA cracker list enlisted from GFG

    Problem Link : https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
    Problem Naem : Rat in a Maze Problem - I

    Difficulty   : Medium

    Date : 05-09-2025

----------------------------------------------------------------------------------------------------
    
    You are given an image represented by an m x n grid of integers image, where image[i][j] 
    represents the pixel value of the image. You are also given three integers sr, sc, and color. 
    Your task is to perform a flood fill on the image starting from the pixel image[sr][sc].

    To perform a flood fill:

    Begin with the starting pixel and change its color to color.
    Perform the same process for each pixel that is directly adjacent (pixels that share a side 
    with the original pixel, either horizontally or vertically) and shares the same color as 
    the starting pixel.

    Keep repeating this process by checking neighboring pixels of the updated pixels and modifying 
    their color if it matches the original color of the starting pixel.
    The process stops when there are no more adjacent pixels of the original color to update.
    Return the modified image after performing the flood fill.

    

    Example 1:

    Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2

    Output: [[2,2,2],[2,2,0],[2,0,1]]

    Explanation:



    From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), 
    all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) 
    are colored with the new color.

    Note the bottom corner is not colored 2, because it is not horizontally or vertically 
    connected to the starting pixel.

    Example 2:

    Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, color = 0

    Output: [[0,0,0],[0,0,0]]

    Explanation:

    The starting pixel is already colored with 0, which is the same as the target color. 
    Therefore, no changes are made to the image.

    

    Constraints:

    m == image.length
    n == image[i].length
    1 <= m, n <= 50
    0 <= image[i][j], color < 216
    0 <= sr < m
    0 <= sc < n



/*

    This DFS solution is done by on my own approach

    It seems like O(4^(n * m)) but because of using visited array it becames O(n * m) actually
    
    TC : O(n * m)
    SC : O(n * m)

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isSame(int i, int j, int x, int y, vector<vector<int>>& image){
        return image[i][j] == image[x][y];
    }
    // checking out of bounds
    bool isValid(int i, int j, int n, int m, vector<vector<bool>>& vis){
        if(i < 0 || j < 0 || i >= n || j >= m || vis[i][j]) return false;
        return true;
    }

    void dfs(int x, int y, int n, int m, int color, vector<vector<int>>& image, vector<vector<bool>>& vis){
        
        vis[x][y] = true;
        int dx[] = {-1, 0, 1, 0};
        int dy[]= {0, 1, 0, -1};
    
        // Exploring all 4 directions
        for(int i=0; i<4; i++){
            int nr = x + dx[i]; // newRow
            int nc = y + dy[i]; // newColumn
            if(isValid(nr, nc, n, m, vis) && isSame(x, y, nr, nc, image)){
                dfs(nr, nc, n, m, color, image, vis);
                image[nr][nc] = color; // changing to new color
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        dfs(sr, sc, n, m, color, image, vis);
        image[sr][sc] = color;
        return image;
    }
};