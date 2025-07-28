/*
    Problem Link    : https://leetcode.com/problems/validate-binary-search-tree/description/
    Problem Name    : 98. Validate Binary Search Tree
    Difficulty      : Medium
    Time Complexity : O(N)
    Space Complexity: O(N) for call stack auxiliary memory use

    Author : Ali Hossain
    Date : 18-05-2025

========================================================================================================
    
    Given the root of a binary tree, determine if it is a valid binary search tree (BST).

    A valid BST is defined as follows:

    The left subtree of a node contains only nodes with keys less than the node's key.
    The right subtree of a node contains only nodes with keys greater than the node's key.
    Both the left and right subtrees must also be binary search trees.
    

    Example 1:


    Input: root = [2,1,3]
    Output: true
    Example 2:


    Input: root = [5,1,4,null,null,3,6]
    Output: false
    Explanation: The root node's value is 5 but its right child's value is 4.
    

    Constraints:

    The number of nodes in the tree is in the range [1, 104].
    -231 <= Node.val <= 231 - 1

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
    Time Complexity : O(n) for traversing all nodes once
    Space Complexity : O(1) + O(n) for call stack memory since recursive solution it is

    here could be another approach using inorder traversal idea
*/


class Solution {
public:
    bool checkValid(TreeNode* root, long long minVal, long long maxVal){
        if(root == NULL) return true; // root == null hoile max depth e geche without condition break so it will return true 
        if(root->val <= minVal || root->val >= maxVal) return false;

        bool leftSubtree = checkValid(root->left, minVal, root->val);
        bool rightSubtree = checkValid(root->right, root->val, maxVal);

        if(leftSubtree && rightSubtree) return true;
        else return false;
    }

    bool isValidBST(TreeNode* root) {
        return checkValid(root, LLONG_MIN, LLONG_MAX); // long long min max nite hobe
    }
};