/*
    Problem Link    : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
    Problem Name    : 235. Lowest Common Ancestor of a Binary Search Tree
    Difficulty      : Medium
    Time Complexity : O(height)
    Space Complexity: O(1) 

    Author : Ali Hossain
    Date : 19-05-2025

========================================================================================================

    Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

    According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

    

    Example 1:


    Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
    Output: 6
    Explanation: The LCA of nodes 2 and 8 is 6.
    Example 2:


    Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
    Output: 2
    Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.
    Example 3:

    Input: root = [2,1], p = 2, q = 1
    Output: 2
    

    Constraints:

    The number of nodes in the tree is in the range [2, 105].
    -109 <= Node.val <= 109
    All Node.val are unique.
    p != q
    p and q will exist in the BST.

*/

#include<bits/stdc++.h>
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


/*
    Approach 1 only for BST: 

    BST property is root is greater than left child whereas root is less than right child
    since this is BST the value is sorted if we traverse it in inorder traverse .
    
    if root greater than both p & q then ancestor is on the right so traverse to right
    if root less than both p & q then ancestor is on the left so traverse to left
    else this is ancestor

    from example 2 : 
    if p = 8, q = 9 ; so we will traverse to right since 6 < 8 and 6 < 9
    now root became 8 ; 8 < and 8 < 9 is not true again 8 > 8 and 8 > 9 also not true
    so the ans is 8

    Time Complexity : O(Height) since condition diye traverse hocce eijonno maximum height porjonto gelei ans pawa jay
    Space Complexity : O(1) eikhane jehetu only height porjonto traverse hocche sob node na tai call stack e O(n) hoy na tai overall space O(1)
    SO,
    TC : O(height)
    SC : O(1)

*/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL; 
        if(root->val > p->val && root->val > q->val){
            return lowestCommonAncestor(root->left, p, q);
        }
        if(root->val < p->val && root->val < q->val){
            return lowestCommonAncestor(root->right, p, q);
        }
        return root;
    }
};


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 /*
    Approach 2 for BS ans BST both: 
    

    Time Complexity : O(N) we are traversing each node of the tree
    Space Complexity : O(N) for call stack 

*/
class Solution {
public:
    TreeNode* LCA(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == NULL) return NULL;
        if(root == p) return p;
        if(root == q) return q;
        TreeNode* leftChild = LCA(root->left, p, q);
        TreeNode* rightChild = LCA(root->right, p, q);

        if(leftChild == NULL){
            return rightChild;
        }
        else if(rightChild == NULL){
            return leftChild;
        }
        return root; // else both are equal to lest and right node so root is lca
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return LCA(root, p, q);
    }
};