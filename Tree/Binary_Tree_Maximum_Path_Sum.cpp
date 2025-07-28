/*
    Problem Link    : https://leetcode.com/problems/binary-tree-maximum-path-sum/description/
    Problem Name    : 124. Binary Tree Maximum Path Sum
    Difficulty      : Hard
    Time Complexity : O(N)
    Space Complexity: O(N) for call stack memory use

    Author : Ali Hossain
    Date : 16-05-2025

========================================================================================================
    
    A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the 
    sequence has an edge connecting them. A node can only appear in the sequence at most once. 
    Note that the path does not need to pass through the root.

    The path sum of a path is the sum of the node's values in the path.

    Given the root of a binary tree, return the maximum path sum of any non-empty path.


    Example 1:


    Input: root = [1,2,3]
    Output: 6
    Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.
    Example 2:


    Input: root = [-10,9,20,null,null,15,7]
    Output: 42
    Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.
    

    Constraints:

    The number of nodes in the tree is in the range [1, 3 * 10^4].
    -1000 <= Node.val <= 1000

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
// For more clear understant just Dry-run the recursion process it will clear
// Editorial video : https://www.youtube.com/watch?v=WszrfSwMz58

class Solution {
public:
    int sum(TreeNode* root, int &maxi){
        if(root == NULL){
            return 0;
        }
        // if any is negative then make that 0 means we are skiping that node
        int leftNode = max(0, sum(root->left, maxi));
        int rightNode = max(0, sum(root->right, maxi)); 

        // maxi will record the max value of a path from a node 
        int currSum = root->val + leftNode + rightNode ;
        maxi = max(maxi, currSum);
        
        //this line for taking maximum node either left path or right path from a node
        return root->val + max(0, max(leftNode, rightNode));
    }
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN ;
        sum(root, maxi);
        return maxi ;
    }
};