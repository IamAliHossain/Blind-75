/*
    Problem : https://leetcode.com/problems/word-search/
    Problem name : Word Search
    Difficulty : Medium

    Time Complexity : O(N * M * 4^ word length)
    Space Complexity: O(word length)

*/
#include<bits/stdc++.h>
using namespace std;

/* 
    Solvin using Backtracing 
    Approach:  We are going to solve this by using backtracking(using DFS), in this approach first we will 
               send the 1st index of the word string, and we will start backtracking in all 
               four directions to find the rest of the letters of the given string.

*/
class Solution {
    public:
        
        bool exist(vector<vector<char>>& board, string word) {
            int n = board.size();
            int m = board[0].size();
            int wordId = 0;
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    if(dfs(board, word, i, j, n, m, wordId))return true;
                }
            }
            return false;
        }
           
        bool dfs(vector<vector<char>>& board, string &word, int i, int j, int n, int m, int wordId){
            if(i >= n || i < 0 || j >=  m || j< 0) return false;
            if(board[i][j] != word[wordId] || board[i][j] == '*') return false;
            if(wordId == word.size()-1) return true;
            
            // this is to prevent reusing of the same character
            char mark = board[i][j];
            board[i][j] = '*';
    
            bool top = dfs(board, word, i+1, j, n, m, wordId+1);
            bool bottom = dfs(board, word, i-1, j,  n, m, wordId+1);
            bool left = dfs(board, word, i, j+1,  n, m, wordId+1);
            bool right = dfs(board, word, i, j-1,  n, m, wordId+1);
            // undo changes again by putting original value
            board[i][j] = mark;
            return top || bottom || left || right;
        }
    };