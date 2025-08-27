/*
            This problem is not from blind75, 450 DSA cracker enlisted it

    Problem Link : https://www.naukri.com/code360/problems/left-view-of-a-binary-tree_920519?
                    topList=love-babbar-dsa-sheet-problems&utm_source=website&utm_medium=affil
                    iate&utm_campaign=450dsatracker&leftPanelTabValue=PROBLEM

    Problem Name : Left View Of a Binary Tree
    Difficulty   : Medium
    
    Author : Ali Hossain
    Date : 27-08-2025
==============================================================================================

    Problem statement
    You have been given a binary tree of integers. You are supposed to find the left view of 
    the binary tree. The left view of a binary tree is the set of all nodes that are visible 
    when the binary tree is viewed from the left side.

    Example:

    The left view of the above binary tree is  {5, 7, 14, 25}.
    Detailed explanation ( Input/output format, Notes, Images )
    Constraints:
    1 <= T <= 100
    0 <= N <= 3000
    1 <= data <= 10^5 and data!=-1

    Where ‘T’ is the number of test cases, and ‘N’ is the total number of nodes in the binary tree, 
    and “data” is the value of the binary tree node

    Time Limit: 1 sec
    Sample Input 1:
    2
    3 4 -1 -1 -1 
    2 8 7 -1 5 -1 -1 1 -1 -1 -1
    Sample Output 1:
    3 4
    2 8 5 1
    Explanation of Sample Input 1:
    For the first test case, node 3 and node 4 are visible when the binary tree is viewed from the 
    left.

    For the second test case, nodes 2, 8, 5, 1 are visible when the binary tree is viewed from the 
    left.
    Sample Input 2:
    2
    1 3 5 12 -1 8 -1 -1 -1 -1 -1 
    9 6 3 -1 -1 4 8 -1 -1 -1 -1 
    Sample Output 2:
    1 3 12
    9 6 4
    Explanation of Sample Input 2:
    For the first test case, nodes 1, 3, 12 are visible when the binary tree is viewed from the left.

    For the second test case, nodes 9, 6, 4 are visible when the binary tree is viewed from the left.


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



#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
/*
    N is the totla number of nodes in tree

    TC : O(N)
    SC : O(N)
*/

vector<int> getLeftView(TreeNode<int> *root)
{
    if(root == nullptr) return{};
    queue<TreeNode<int> *> q;
    q.push(root);
    vector<int> ans;
    while(!q.empty()){

        int sz = q.size();

        for(int i=0; i<sz; i++){
            
            TreeNode<int>* node = q.front();
            q.pop();

            if(i == 0){
                ans.push_back(node->data);
            }
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
    }
    return ans;
}