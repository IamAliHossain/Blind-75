/*
    Problem Link : https://leetcode.com/problems/same-tree/description/
    Problem Name : 100. Same Tree
    Difficulty   : Easy
    
    Author : Ali Hossain
    Date : 16-05-2025

==============================================================================================

    Given the roots of two binary trees p and q, write a function to check if they are the same or not.

    Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

    

    Example 1:


    Input: p = [1,2,3], q = [1,2,3]
    Output: true
    Example 2:


    Input: p = [1,2], q = [1,null,2]
    Output: false
    Example 3:


    Input: p = [1,2,1], q = [1,1,2]
    Output: false
    

    Constraints:

    The number of nodes in both trees is in the range [0, 100].
    -104 <= Node.val <= 104

*/


// Definition for a binary tree node.
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

// DFS solution takes Time Complexity : O(n)
// Space Complexity : O(hight) during recursion call stack use this memory space so space complexity : O(height) : O(n)
class Solution {
public:
    bool compare(TreeNode* p, TreeNode* q){
        if(p == NULL || q == NULL){
            if(p == q) return true;
            else return false;
        }
        if((p->val == q-> val) && compare(p->left, q->left) && compare(p->right, q->right)){
            return 1;
        }
        else return 0;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return compare(p, q);
    }
};