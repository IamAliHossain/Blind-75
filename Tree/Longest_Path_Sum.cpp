/*
            This problem is not from blind75, 450 DSA cracker enlisted it from GFG

    Problem Link : https://www.naukri.com/code360/problems/longest-path_3210613?topList=love-babbar-dsa-sheet-problems&utm_source=website&utm_medium=affiliate&utm_campaign=450dsatracker

    Problem Name :  Longest Path Sum
    Difficulty   : Medium
    
    Author : Ali Hossain
    Date : 02-09-2025

==============================================================================================

    You are given a series of rooms, with each room having a path to at most two other rooms. In short, they are represented as a Binary tree.

    Each room has some amount of money. You can start from the root and only go downwards. Find the amount of money you can earn on the longest path. If there are multiple longest paths, find the one where you can earn maximum money.

    Detailed explanation ( Input/output format, Notes, Images )
    Constraints -
    1 <= T <= 10
    1 <= Num <= 10^5
    1 <= A[i] <= 10^4 or A[i] = -1, i ∈ (1,Num)

    Note - The sum of 'Num’ over all test cases does not exceed 10^5.

    Time Limit: 1 sec
    Sample Input 1:
    1
    11
    4 100 2 -1 -1 5 9 -1 -1 -1 -1
    Sample Output 1
    15
    Explanation for Sample Input 1:

    There are two paths on length 3 here, namely 4->2->9 and 4->2->5. Out of these two, 4 -> 2 -> 9 has the greater sum, so the answer is 4+2+9=15.
    Sample Input 2:
    1
    13
    7 2 9 1 5 -1 14 -1 -1 -1 -1 -1 -1
    Sample Output 2:
    30


*/


#include <bits/stdc++.h> 
using namespace std;

/*
    TC : O(N)
    SC : O(N) for recurison call stack memory
*/


/* Structure of the Node of the Binary Tree is */
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val) 
    {
        data = val;
        left = right = NULL;
    }
};


void pathSum(Node* root, int sum, int &maxSum, int len, int &maxLen){
    if(root == NULL){
        if(len > maxLen){
            maxSum = sum;
            maxLen = len;
        }
        else if(len == maxLen && sum > maxSum){
            maxSum = sum;
        }
        return;
    }

    pathSum(root->left, sum + root->data, maxSum, len+1, maxLen);
    pathSum(root->right, sum + root->data, maxSum, len+1, maxLen);
}

int longestPath(Node *root)
{
    if(root == nullptr) return 0;
    int maxLen = 0, maxSum = INT_MIN;
    pathSum(root, 0, maxSum, 1, maxLen);

    return maxSum;
}