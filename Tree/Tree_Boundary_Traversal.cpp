/*
            This problem is not from blind75, 450 DSA cracker enlisted it from GFG

    Problem Link : https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

    Problem Name : Tree Boundary Traversal
    Difficulty   : Medium
    
    Author : Ali Hossain
    Date : 30-08-2025
==============================================================================================


    Problem Statement:
    Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order: 

    Left Boundary: This includes all the nodes on the path from the root to the leftmost leaf node. 
    You must prefer the left child over the right child when traversing. Do not include leaf nodes 
    in this section.

    Leaf Nodes: All leaf nodes, in left-to-right order, that are not part of the left or right 
    boundary.

    Reverse Right Boundary: This includes all the nodes on the path from the rightmost leaf node 
    to the root, traversed in reverse order. You must prefer the right child over the left child 
    when traversing. Do not include the root in this section if it was already included in the 
    left boundary.

    Note: If the root doesn't have a left subtree or right subtree, then the root itself is the 
    left or right boundary. 

    Examples:

    Input: root[] = [1, 2, 3, 4, 5, 6, 7, N, N, 8, 9, N, N, N, N]
    Output: [1, 2, 4, 8, 9, 6, 7, 3]
    Explanation:
    
    Input: root[] = [1, N, 2, N, 3, N, 4, N, N] 
    Output: [1, 4, 3, 2]
    Explanation:

    Left boundary: [1] (as there is no left subtree)
    Leaf nodes: [4]
    Right boundary: [3, 2] (in reverse order)
    Final traversal: [1, 4, 3, 2]
    Constraints:
    1 ≤ number of nodes ≤ 10^5
    1 ≤ node->data ≤ 10^5

    Expected Complexities
    Company Tags

    Flipcart, Amazon, Microsoft, Samsung and many more
*/


#include<bits/stdc++.h>


// Tree Node


class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

/* 
    [Approach - 1] Using Recursion - O(n) Time and O(h) Space
    The idea is to traverse the boundary of the binary tree in three parts:

    Collect Left Boundary Nodes: 
                            Collects all nodes from the root’s left child, 
                            excluding leaf nodes, until a leaf is reached.
    Collect Leaf Nodes: 
                        Using recursion traverse the tree and 
                        collect all leaf nodes in the result.
    Collect Right Boundary Nodes: 
                                Collects all nodes from the root’s right child,
                                excluding leaf nodes, in reverse order.
                                
    By combining these parts, we achieve the desired boundary traversal.
    Each part is collected using recursive functions for left boundary, 
    leaf nodes, and right boundary traversal.

*/







class Solution {
  public:
  
    void leftBoundary(Node* root, vector<int>& res){
        if(root == NULL || (root->left == NULL && root->right == NULL)) return;
        
        res.push_back(root->data);
        
        if(root->left){
            leftBoundary(root->left, res);
        }
        else if(root->right){
            leftBoundary(root->right, res);
        }
    }
    
    void bottomBoundary(Node* root, vector<int> &res){
        if(root == NULL) return;
        
        if(root->left == NULL && root->right == NULL){
            res.push_back(root->data);
            return;
        }
        
        bottomBoundary(root->left, res);
        bottomBoundary(root->right, res);
        
    }
    
    void rightBoundary(Node* root, vector<int> & res){
        if(root == NULL || (root->left == NULL && root->right == NULL))return;
        
        if(root -> right){
            rightBoundary(root->right, res);
        }
        else if(root->left){
            rightBoundary(root->left, res);
        }
        
        res.push_back(root->data);
    }
    vector<int> boundaryTraversal(Node *root) {
        vector<int> res;
        if(root == NULL) return res;
        
        if(root->left != NULL || root->right != NULL){
            res.push_back(root->data);
        } 
        
        leftBoundary(root->left, res);
        bottomBoundary(root, res);
        rightBoundary(root->right, res);
  
        return res;
    }
};