/*
            This problem is not from blind75, 450 DSA cracker enlisted it from GFG

    Problem Link : https://www.geeksforgeeks.org/problems/leaf-at-same-level/1

    Problem Name : Leaves at Same Level or Notes
    Difficulty   : Easy
    
    Author : Ali Hossain
    Date : 31-08-2025
==============================================================================================


    Given a binary tree with n nodes, determine whether all the leaf nodes are at the same level 
    or not. Return true if all leaf nodes are at the same level, and false otherwise.

    Examples :

    Input: root = [1, 2, 3]
        1
    / \
    2   3
    Output: true
    Explanation: The binary tree has a height of 2 and the leaves are at the same level.
    Input: root = [10, 20, 30, 10, 15, N, N]
        10
    /  \
    20   30
    /  \
    10   15
    Output: false
    Explanation: The binary tree has a height of 3 and the leaves are not at the same level.
    Input: root = [3, 2, 1]
        3
    / \
    2   1
    Output: true
    Explanation: The binary tree has a height of 2 and the leaves are at the same level.
    Constraints:
    1 ≤ n ≤ 10^5

    Expected Complexities

    Time Complexity: O(n)
    Auxiliary Space: O(height of tree)
*/

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};


class Solution {
  public:
    /*You are required to complete this method*/
    
  
    bool check(Node *root) {
        // Your code here

        queue<Node*> q;
        q.push(root);
        int leaf1 =0, leaf2 = 0;
        int level = 0;
        while(!q.empty()){
            
            int sz = q.size();
            for(int i=0; i<sz; i++){

                root = q.front();
                q.pop();
                
                if(root->left){
                    q.push(root->left);
                }
                if(root->right){
                    q.push(root->right);
                }
                if(root->left == nullptr && root->right == nullptr){
                    if(leaf1 == 0){
                        leaf1 = level;
                    }
                    if(leaf1 != 0){
                        leaf2 = level;
                    }
                }
            }
            level++;
        }
        return leaf1 == leaf2;
    }

};