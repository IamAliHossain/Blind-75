/*
    Problem Link    : https://leetcode.com/problems/binary-tree-level-order-traversal/description/
    Problem Name    : 102. Binary Tree Level Order Traversal
    Difficulty      : Medium
    Time Complexity : 
    Space Complexity: O() for call stack memory use

    Author : Ali Hossain
    Date : 16-05-2025

========================================================================================================
    
    Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

 

    Example 1:


    Input: root = [3,9,20,null,null,15,7]
    Output: [[3],[9,20],[15,7]]
    Example 2:

    Input: root = [1]
    Output: [[1]]
    Example 3:

    Input: root = []
    Output: []
    

    Constraints:

    The number of nodes in the tree is in the range [0, 2000].
    -1000 <= Node.val <= 1000

*/

/*


*/


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};



#include<bits/stdc++.h>
using namespace std;

/*

Complexity of a single inner loop execution (at one level): 𝑂(number of nodes at that level)
O(number of nodes at that level) 
Total complexity across all inner loops (entire traversal): O(n)
​Total Space Complexity : O(n)

*/
class Solution {
public:
    vector<vector<int>> bfs(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            vector<int> level;
            for(int i=0; i<sz; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left != NULL)q.push(node->left);
                if(node->right != NULL)q.push(node->right);
                level.push_back(node->val);
            }
            ans.push_back(level);
        }
        
        return ans;
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        return bfs(root);
    }
};