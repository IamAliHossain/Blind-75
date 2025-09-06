/*
    This Problem is from 450 DSA cracker list enlisted from GFG

    Problem Link : https://www.geeksforgeeks.org/problems/steps-by-knight5927/1
    Problem Naem : Steps by Knight

    Difficulty   : Medium

    Date : 06-09-2025


--------------------------------------------------------------------------------------------------------
    Problem Statement : 

    Given a square chessboard of size (n x n), the initial position and target postion 
    of Knight are given. Find out the minimum steps a Knight will take to reach the target position.

    Note: The initial and the target position coordinates of Knight have been given according 
    to 1-base indexing.

    Examples:

    Input: n = 3, knightPos[] = [3, 3], targetPos[]= [1, 2]
    Output: 1
    Explanation:
    Knight takes 1 step to reach from 
    (3, 3) to (1 ,2).
    Input: n = 6, knightPos[] = [4, 5],targetPos[] = [1, 1]
    Output: 3
    Explanation:

    Knight takes 3 step to reach from 
    (4, 5) to (1, 1):
    (4, 5) -> (5, 3) -> (3, 2) -> (1, 1).
    Constraints:
    1 <= n<= 1000
    1 <= knightpos ≤ [x, y], targertpos[x, y] ≤  n 

    Expected Complexities
    Time Complexity: O(n^2)
    Auxiliary Space: O(n^2)


*/




// This problem's aim is to find minimum distance

#include<bits/stdc++.h>
using namespace std;

// DFS + backtracking approach
// TC : O(8 ^ (n * n))
// SC : O(n * n)
// This will lead to TLE hence we need optimal solution which can be achievev by using BFS
// goto next solution so

class Solution1 {
  public:
    
    void dfs(int startI, int startJ, int targetI, int targetJ, int n, vector<vector<bool>> &vis, int &ans, int steps){
        if(startI < 1 || startJ < 1 || startI > n || startJ > n || vis[startI][startJ]) return;
        
        if(startI == targetI && startJ == targetJ){
            ans = min(ans, steps);
            return;
        }
        vis[startI][startJ] = true;
        
        // down move
        dfs(startI + 2, startJ + 1, targetI, targetJ, n, vis, ans, steps+1);
        dfs(startI + 2, startJ - 1, targetI, targetJ, n, vis, ans, steps+1);
        
        // up move
        dfs(startI - 2, startJ + 1, targetI, targetJ, n, vis, ans, steps+1);
        dfs(startI - 2, startJ - 1, targetI, targetJ, n, vis, ans, steps+1);
        
        // left move
        dfs(startI - 1, startJ - 2, targetI, targetJ, n, vis, ans, steps+1);
        dfs(startI + 1, startJ - 2, targetI, targetJ, n, vis, ans, steps+1);
        
        // right move
        dfs(startI - 1, startJ + 2, targetI, targetJ, n, vis, ans, steps+1);
        dfs(startI + 1, startJ + 2, targetI, targetJ, n, vis, ans, steps+1);
        
        // unmark and backtrack
        vis[startI][startJ] = false;
        
    }

    int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int n) {
        int ans = INT_MAX;
        vector<vector<bool>> vis(n+1, vector<bool> (n+1, false));
       
        int startI = knightPos[0];
        int startJ = knightPos[1];
        int targetI = targetPos[0];
        int targetJ = targetPos[1];
        
        vector<vector<int>> dp(n+1, vector<int>(n, ans));
        dfs(startI, startJ, targetI, targetJ, n, vis, ans, 0);

        return ans;
    }
};


/* Optimal solution using BFS 
    TC : O(n * n)
    SC : O(n * n)
*/
class Solution2 {
  public:
  
    
    // instead of struct we may use other stl stuff in queue
    // but in interview if they said not to use STL hence this have to do to use queue
    struct cell{
        int x, y, dis;
        cell(){
            x = 0;
            y = 0;
            dis = 0;
        }
        cell(int x1, int y1, int dis1){
            x = x1;
            y = y1;
            dis = dis1;
        }  
    };
    
    bool isValid(int startI, int startJ, int n, vector<vector<bool>> &vis) {
        if(startI < 1 || startJ < 1 || startI > n || startJ > n || vis[startI][startJ]) return false;
        return true;
    }
    
    int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int n) {
        int ans = INT_MAX;
        vector<vector<bool>> vis(n+1, vector<bool> (n+1, false));
       
        int startI = knightPos[0];
        int startJ = knightPos[1];

        int dx[] = {-2, -2, -1, -1, 2, 2, 1, 1};
        int dy[] = {-1, 1, 2, -2, 1, -1, 2, -2};
        
        vector<vector<int>> dp(n+1, vector<int>(n, ans));
        queue<cell>q;
        int dis = 0;
        q.push(cell(startI, startJ, dis));
      
        while(!q.empty()){
            cell t = q.front();
            q.pop();
            if(t.x == targetPos[0] && t.y == targetPos[1]){
                return t.dis;
            }
            
            for(int i=0; i<8; i++){
                int x = t.x + dx[i];
                int y = t.y + dy[i];
                if(isValid(x, y, n, vis)){
                    vis[x][y] = true;
                    q.push(cell(x, y, t.dis+1));
                }
            }
            
        }
       
        return -1;
        
    }
};