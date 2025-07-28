/*
    Problem Link    : https://leetcode.com/problems/subtree-of-another-tree/description/
    Problem Name    : 572. Subtree of Another Tree
    Difficulty      : Easy
    Time Complexity : O(n * m)
    Space Complexity: O(n + m) for call stack memory use

    Author : Ali Hossain
    Date : 18-05-2025

========================================================================================================
    
    Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.

    A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. The tree tree could also be considered as a subtree of itself.

    

    Example 1:


    Input: root = [3,4,5,1,2], subRoot = [4,1,2]
    Output: true
    Example 2:


    Input: root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
    Output: false
    

    Constraints:

    The number of nodes in the root tree is in the range [1, 2000].
    The number of nodes in the subRoot tree is in the range [1, 1000].
    -104 <= root.val <= 104
    -104 <= subRoot.val <= 104

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

    subtree of another tree means that some parts are identical of a tree on another tree. 
    so we can check each node is that identical to another for this we may take help from
    Same Tree named problem, if not then we should move forward by big tree(root->left, root->right)
    
    n = root.size()
    m = subRoot.size()
    Time Complexity     : O(n * m)
    Space Complexity    : O(n + m) for call stack memory

*/
class Solution {
public:
    bool isIdentical(TreeNode* root, TreeNode* subRoot){
        if(root == NULL || subRoot == NULL){
            if(root == subRoot) return true;
            else return false ;
        }
        if(root->val == subRoot->val){
            if(isIdentical(root->left, subRoot->left) && isIdentical(root->right, subRoot->right)){
                return true;
            }
        }
        return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL){
            return false;
        }
        if(root->val == subRoot->val){
            if(isIdentical(root, subRoot)){
                return true;
            }
        }
        if(isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot)){
            return true;
        }
        return false;
    }
};