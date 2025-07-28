/*
    Problem Link : https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
    Problem Name : 104. Maximum Depth of Binary Tree
    Difficulty   : Easy
    
    Author : Ali Hossain
    Date : 16-05-2025
==============================================================================================

    Given the root of a binary tree, return its maximum depth.

    A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

    

    Example 1:


    Input: root = [3,9,20,null,null,15,7]
    Output: 3
    Example 2:

    Input: root = [1,null,2]
    Output: 2
    

    Constraints:

    The number of nodes in the tree is in the range [0, 104].
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


// 
// DFS solution takes Time Complexity : O(n)
// Space Complexity : O(1) + O(hight) during recursion call stack use this memory space so space complexity : O(height)
class Solution {
public:
    int solve(TreeNode* root){
        if(root == NULL) return 0;
        int leftDepth = solve(root->left);
        int rightDepth = solve(root->right);
        return (1+ max(leftDepth, rightDepth));

    }
    int maxDepth(TreeNode* root) {
        return solve(root);
    }
};