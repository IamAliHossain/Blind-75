/*
            This problem is not from blind75, 450 DSA cracker enlisted it from GFG

    Problem Link : https://www.geeksforgeeks.org/problems/duplicate-subtree-in-binary-tree/1
    Problem Name : Duplicate Subtree
    Difficulty   : Medium
    
    Author : Ali Hossain
    Date : 03-09-2025

==============================================================================================

    Given a binary tree, find out whether it contains a duplicate sub-tree of size two or more, 
    or not.

    Note: Two same leaf nodes are not considered as subtree as size of a leaf node is one. 

    Example 1 :

    Input : 
                1
                /   \ 
            2       3
            /   \       \    
            4     5       2     
                        /  \    
                        4    5
    Output : 1
    Explanation : 
        2     
    /   \    
    4     5
    is the duplicate sub-tree.
    Example 2 :

    Input : 
                1
                /   \ 
            2       3
    Output: 0
    Explanation: There is no duplicate sub-tree 
    in the given binary tree.
    Your Task:  
    You don't need to read input or print anything. Your task is to complete the function dupSub() 
    which takes root of the tree as the only argument and returns 1 if the binary tree contains a 
    duplicate sub-tree of size two or more, else 0.

    Expected Time Complexity: O(N)
    Expected Space Complexity: O(N)

    Constraints:
    0 ≤ Data of nodes ≤ 12
    1 ≤ Number of nodes ≤ 10^5 


 
*/

#include<bits/stdc++.h>
using namespace std;


/*The structure of the Binary Tree Node  is */
struct Node
{
  char data;
  struct Node* left;
  struct Node* right;
};


/*

    Time Complexity: O(N)
    Space Complexity: O(N)


*/
class Solution {
  public:
    /*This function returns true if the tree contains
    a duplicate subtree of size 2 or more else returns false*/
    
    string dfs(Node* root, unordered_map<string, int>&hashMap){
        if(root == nullptr) return "";
        
        string s= "";
        string s1 = dfs(root->left, hashMap);
        string s2 =  dfs(root->right, hashMap);
        s += s1 + root->data + s2;
        if(s.size() >= 2){
            hashMap[s]++;
        }
        return s;
    }
    
    int dupSub(Node *root) {
        unordered_map<string, int> hashMap;
        dfs(root, hashMap);
        for(auto u : hashMap){
            int y = u.second;
            if(y >= 2) return true;
        }
        return false;
        
    }
};
