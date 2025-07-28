/*
    Problem Link    : https://leetcode.com/problems/invert-binary-tree/description/
    Problem Name    : 226. Invert Binary Tree
    Difficulty      : Easy
    Time Complexity : O(N)
    Space Complexity: O(N) for call stack memory use

    Author : Ali Hossain
    Date : 16-05-2025

==============================================================================================

    Given the root of a binary tree, invert the tree, and return its root.

    

    Example 1:


    Input: root = [4,2,7,1,3,6,9]
    Output: [4,7,2,9,6,3,1]
    Example 2:


    Input: root = [2,1,3]
    Output: [2,3,1]
    Example 3:

    Input: root = []
    Output: []
    

    Constraints:

    The number of nodes in the tree is in the range [0, 100].
    -100 <= Node.val <= 100

*/

#include<bits/stdc++.h>
using namespace std;


//Definition for a binary tree node.
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
    DFS traversal takes O(N) time complexity and for recursion call there used a auxilary memory space
    call stack O(N) for all nodes, space Complexity is O(N) too. 
*/
class Solution {
public:
    void solve(TreeNode* root){
        if(root == NULL){
            return ;
        }
        swap(root->left, root->right);
        solve(root->left) ;
        solve(root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        solve(root);
        return root;
    }
};


/* BFS solution */

class Solution {
public:
    TreeNode* bfs(TreeNode* root){
        if(root == NULL){
            return NULL;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()){
            TreeNode* curr = q.front();
            q.pop();
            
            TreeNode* temp = curr->left;
            curr->left = curr->right;
            curr->right = temp;

            if(curr->left != NULL) q.push(curr->left);
            if(curr->right != NULL) q.push(curr->right);
        }

        return root;
    }
    TreeNode* invertTree(TreeNode* root) {
        return bfs(root);
    }
};