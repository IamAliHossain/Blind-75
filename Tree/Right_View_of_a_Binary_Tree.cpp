/*
            This problem is not from blind75, 450 DSA cracker enlisted it

    Problem Link : https://leetcode.com/problems/binary-tree-right-side-view/description/
    Problem Name : 199. Binary Tree Right Side View
    Difficulty   : Medium
    
    Author : Ali Hossain
    Date : 27-08-2025
==============================================================================================

    Given the root of a binary tree, imagine yourself standing on the right side of it, return the 
    values of the nodes you can see ordered from top to bottom.

    
    Example 1:

    Input: root = [1,2,3,null,5,null,4]

    Output: [1,3,4]

    Explanation:



    Example 2:

    Input: root = [1,2,3,4,null,null,null,5]

    Output: [1,3,4,5]

    Explanation:



    Example 3:

    Input: root = [1,null,3]

    Output: [1,3]

    Example 4:

    Input: root = []

    Output: []

    

    Constraints:

    The number of nodes in the tree is in the range [0, 100].
    -100 <= Node.val <= 100


*/


#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

/*

    BFS solution (this solution is my own)
    
    TC : O(N)
    SC : O(N) for using queue + O(N) for using vector
        : O(N) ultimatly

*/

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr) return {};

        queue<TreeNode*> q ;
        q.push(root);
        vector<int> ans;

        while(!q.empty()){
            int sz = q.size();
            for(int i=0; i<sz; i++){
                root = q.front();
                q.pop();

                if(i == sz - 1){
                    ans.push_back(root->val);
                }
                if(root->left){
                    q.push(root->left);
                }
                if(root->right){
                    q.push(root->right);
                }
            }
        }
        return ans;
    }
};
