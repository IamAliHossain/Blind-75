/*
            This problem is not from blind75, 450 DSA cracker enlisted it from GFG

    Problem Link : https://www.geeksforgeeks.org/problems/transform-to-sum-tree/1

    Problem Name : Convert Binary tree into Sum tree
    Difficulty   : Easy
    
    Author : Ali Hossain
    Date : 31-08-2025
==============================================================================================

    Given a Binary Tree of size N , where each node can have positive or negative values. 
    Convert this to a tree where each node contains the sum of the left and right sub 
    trees of the original tree. The values of leaf nodes are changed to 0.

    Example 1:

    Input:
                10
            /      \
            -2        6
        /   \     /  \
        8     -4   7    5

    Output:
                20
            /    \
            4        12
        /  \     /  \
        0     0   0    0

    Explanation:

            (4-2+12+6)
            /           \
        (8-4)          (7+5)
        /   \         /  \
        0     0       0    0
    

    Your Task:  
    You dont need to read input or print anything. Complete the function toSumTree() which takes 
    root node as input parameter and modifies the given tree in-place.

    Note: If you click on Compile and Test the output will be the in-order traversal of the 
    modified tree.


    Expected Time Complexity: O(N)
    Expected Auxiliary Space: O(height of tree)
    

    Constraints:
    1 ≤ N ≤ 10^4


*/

#include<bits/stdc++.h>


/* 
    Time Complexity: O(N)
    Auxiliary Space: O(height of tree)
*/
/* A binary tree node*/
struct Node
{
    int data;
    Node* left, * right;
}; 

class Solution {
  public:

    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    
    int dfs(Node* &root){
        if(root == NULL) return 0;
        
        int old_val = root->data;
        
        root->data = dfs(root->left) + dfs(root->right);
        
        return root->data + old_val;
        
    }
    
    
    void toSumTree(Node *node) {
        dfs(node);
        
    }
};