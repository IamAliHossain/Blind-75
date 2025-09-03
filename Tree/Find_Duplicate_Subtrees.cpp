/*
            This problem is not from blind75, 450 DSA cracker enlisted it from GFG & LeetCode

    Problem Link : https://leetcode.com/problems/find-duplicate-subtrees/description/
    Problem Name : Find Duplicate Subtrees
    Difficulty   : Medium
    
    Author : Ali Hossain
    Date : 03-09-2025

==============================================================================================

    Given the root of a binary tree, return all duplicate subtrees.

    For each kind of duplicate subtrees, you only need to return the root node of any one of them.

    Two trees are duplicate if they have the same structure with the same node values.

    

    Example 1:


    Input: root = [1,2,3,4,null,2,4,null,null,4]
    Output: [[2,4],[4]]
    Example 2:


    Input: root = [2,1,1]
    Output: [[1]]
    Example 3:


    Input: root = [2,2,2,3,null,3,null]
    Output: [[2,3],[3]]
    

    Constraints:

    The number of the nodes in the tree will be in the range [1, 5000]
    -200 <= Node.val <= 200
 
*/


#include<bits/stdc++.h>
using namespace std;



/* Definition for a binary tree node */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


/*

    DFS traversal(posorder)
    TC : O(N), the dfs function traverses each node exactly once and performs constant time operations
                for each node. So, the total time complexity is linear with respect to the 
                number of nodes in the binary tree
    SC : O(N)

*/

class Solution {
public:
    string dfs (TreeNode* root, vector<TreeNode*> &ans, unordered_map<string, int> &subTree){
        if(root == nullptr) return "#";

        string s = "";
        string left = dfs(root->left, ans, subTree);
        string right = dfs(root->right, ans, subTree);

        // use comma to avoid confusion during serialization such as : [12] and [1,2]
        s += left + "," + to_string(root->val) + "," + right + ",";

        // this ensure when duplicate is found for twice only take it
        if(subTree.count(s) && subTree[s] == 1){
            ans.push_back(root);
            subTree[s] ++;
        }
        // if first occurence then increase counter
        else if(!subTree.count(s)){
            subTree[s] = 1;
        }
        
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> ans;
        unordered_map<string, int> subTree;

        dfs(root, ans, subTree);

        return ans;
    }
};