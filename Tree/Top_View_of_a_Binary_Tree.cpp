/*
            This problem is not from blind75, 450 DSA cracker enlisted it

    Problem Link : https://www.naukri.com/code360/problems/top-view-of-the-tree_799401?topList=love-babbar-dsa-sheet-problems&utm_source=website&utm_medium=affiliate&utm_campaign=450dsatracker&leftPanelTabValue=PROBLEM

    Problem Name : Top View Of a Binary Tree
    Difficulty   : Hard
    
    Author : Ali Hossain
    Date : 27-08-2025
==============================================================================================


    Problem Statement:

    You are given a Binary Tree of 'n' nodes.
    The Top view of the binary tree is the set of nodes visible when we see the tree from the top.



    Find the top view of the given binary tree, from left to right.



    Example :
    Input: Let the binary tree be:

    Output: [10, 4, 2, 1, 3, 6]

    Explanation: Consider the vertical lines in the figure. The top view contains the topmost node from each vertical line.
    Detailed explanation ( Input/output format, Notes, Images )
    Sample Input 1:
    1 2 3 4 5 -1 6 -1 7 -1 -1 8 -1 9 -1 -1 11 10 -1 -1 -1 -1 -1


    Sample Output 1:
    10 4 2 1 3 6


    Explanation of Sample Output 1:
    The binary tree is:

    Consider the vertical lines in the figure. The top view contains the topmost node from each vertical line.
    In test case 1,



    Sample Input 2:
    1 2 3 4 5 6 7 8 9 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1


    Sample Output 2:
    8 4 2 1 3 7


    Explanation of Sample Output 2:
    The binary tree is:

    From left to right, the top view of the tree will be [8,4,2,1,3,7], where 9, 5 and 6 will be hidden when we see from the top of the tree.


    Expected time complexity :
    The expected time complexity is O(n * log(n)).


    Constraints:
    1 <= 'n' <= 10000
    1 <= data in any node <= 10 ^ 6

    Time limit: 1 sec

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

    TC: O(N)+ for q size 
        O(NlogN)+ for inserting in map
        O(N) for iteating map

        TC : =(NlogN)

        SC : O(N)

*/

vector<int> getTopView(TreeNode<int> *root)
{
    map<int, vector<TreeNode<int>*>> hashMap;
    queue< pair<TreeNode<int>*, int> > q;
    q.push({root, 0});

    vector<int> ans;

    while(!q.empty()){
        int sz = q.size();
        for(int i=0; i<sz; i++){

            auto &entry = q.front();
            TreeNode<int>* node = entry.first;
            int column = entry.second;
            q.pop();

            hashMap[column].push_back(node);// O(N * logK)

            if(node->left){
                q.push({node->left, column-1}); // O(N*logN)
                
            }
            if(node->right){
                q.push({node->right, column + 1});
        
            }
        }
    }
    for(auto &entry : hashMap){
        int key = entry.first;
        auto &vec = entry.second;
        TreeNode<int> * node = vec[0];
        if(vec.size()>=1)ans.push_back(node->data);
    }
    return ans;
}
