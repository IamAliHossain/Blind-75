/*
    Problem Link    : https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/
    Problem Name    : 230. Kth Smallest Element in a BST
    Difficulty      : Medium
    Time Complexity : O(N)
    Space Complexity: O(N) for call stack auxiliary memory use

    Author : Ali Hossain
    Date : 18-05-2025

========================================================================================================

    Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

    Example 1:

    Input: root = [3,1,4,null,2], k = 1
    Output: 1
    Example 2:

    Input: root = [5,3,6,2,4,null,null,1], k = 3
    Output: 3 

    Constraints:

    The number of nodes in the tree is n.
    1 <= k <= n <= 104
    0 <= Node.val <= 104
    
    Follow up: If the BST is modified often (i.e., we can do insert and delete operations) and you need to find the kth smallest frequently, how would you optimize?

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
    Time Complexity analysis :
    O(n*logn) --> sorting function
    O(n)  ------> traversing the tree

    Space Complexity analysis :
    O(n) ---> for using a vector
    O(n) ---> Auxiliary stack space 

    Overal Complexity :
    Time Complexity : O(n * logn) + O(n) : O(n * logn)
    Space Complexity : O(n) + O(n) : O(n)

    There is also a follow up question to optimize the time complexity go next approach
*/
// Aproach 1
class Solution {
public:
    vector<int>solve(TreeNode* root, vector<int> &v){
        if(root == NULL) return {};
        solve(root->left, v);
        solve(root->right, v);
        v.push_back(root->val);
        return v;
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> v;
        solve(root, v);
        sort(v.begin(), v.end());
        return v[k-1];
    }
};

// Approach 2 ---> Inorder Traversal wil auto sort the BST
// Time Complexity : O(n) 
// Space Complexity : O(n)
class Solution {
public:
    vector<int>solve(TreeNode* root, vector<int> &v){
        if(root == NULL) return {};
        // Inorder Traversal Left -> Root -> Right
        solve(root->left, v); // Left
        v.push_back(root->val); // Root
        solve(root->right, v); // Right
        return v;
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> v;
        solve(root, v);
        return v[k-1];
    }
};