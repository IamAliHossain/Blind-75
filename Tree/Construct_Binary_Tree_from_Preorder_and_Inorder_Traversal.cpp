/*
    Problem Link    : https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
    Problem Name    : 105. Construct Binary Tree from Preorder and Inorder Traversal
    Difficulty      : Medium
    Time Complexity : O(n)
    Space Complexity: O(n) for using a map + for call stack memory use

    Author : Ali Hossain
    Date : 18-05-2025

========================================================================================================
    
    Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

 
    Example 1:


    Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
    Output: [3,9,20,null,null,15,7]
    Example 2:

    Input: preorder = [-1], inorder = [-1]
    Output: [-1]
    

    Constraints:

    1 <= preorder.length <= 3000
    inorder.length == preorder.length
    -3000 <= preorder[i], inorder[i] <= 3000
    preorder and inorder consist of unique values.
    Each value of inorder also appears in preorder.
    preorder is guaranteed to be the preorder traversal of the tree.
    inorder is guaranteed to be the inorder traversal of the tree.

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
    in solve() function each node will traverse only once hence time complexity is n times 
    and for using inMap space complexity is O(n) + call stack memory O(n);

    Time Complexity : O(n)
    Space Complexity : O(n)

*/
class Solution {
public:
    
    TreeNode* solve(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, unordered_map<int, int> &inMap){
        
        if(preStart > preEnd || inStart > inEnd) return NULL;

        TreeNode* root = new TreeNode(preorder[preStart]);
        int inRoot = inMap[root->val]; // inorder er root
        int inLeft = inRoot - inStart; // inorder er left nums

        /*
         now build left and right nodes of root recursively
         Left Node of the root
         preorder array theke Left Node range = (preStart+1) TO (preStart+inLeft)   
         inorder array theke Left Node range = inStart TO inRoot 

        */
        root->left = solve(preorder, preStart+1, preStart+inLeft, inorder, inStart, inRoot-1, inMap);
        
        /* 
        Right node of root
        preorder array theke Right Node range = (preStart+inLeft+1) TO preEnd  
        inorder array theke Right Node range = (inRoot+1) TO inEnd
        */
        root->right = solve(preorder, preStart+inLeft+1, preEnd, inorder, inRoot+1, inEnd, inMap);
        
        return root;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inMap;
        int n = preorder.size();
        for(int i=0; i<n; i++){
            inMap[inorder[i]] = i;
        }
        TreeNode* root = solve(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, inMap);
        return root;
    }
};