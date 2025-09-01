/*
            This problem is not from blind75, 450 DSA cracker enlisted it from GFG

    Problem Link : https://www.geeksforgeeks.org/problems/leaf-at-same-level/1

    Problem Name : Leaves at Same Level or Notes
    Difficulty   : Easy
    
    Author : Ali Hossain
    Date : 31-08-2025
==============================================================================================


    
    Given a binary tree. The task is to find subtree with maximum sum in the tree and return its sum.

    Example 1:

    Input:
                1
                /   \
            2      3
            / \    / \
            4   5  6   7

    Output: 28
    Explanation: 
    As all the tree elements are positive,
    the largest subtree sum is equal to
    sum of all tree elements.


    Example 2:
    Input:
                1
                /    \
            -2      3
            / \    /  \
            4   5  -6   2
    Output: 7
    Explanation: 
    Subtree with largest sum is : 
    -2
    /  \ 
    4    5
    Also, entire tree sum is also 7.
    

    Your Task:  
    You don't need to read input or print anything. Your task is to complete the function 
    findLargestSubtreeSum() which takes the root of a binary tree and returns an integer.
    

    Expected Time Complexity: O(N)
    Expected Auxiliary Space: O(N)

    Constraints:
    1 <= N <= 10^5
    -10^3 <= tree.val <= 10^3


*/

#include<bits/stdc++.h>
using namespace std;

/*  
    Recursive Solution approach : Traversing in postorder

    Time Complexity: O(N)
    Auxiliary Space: O(N)

*/

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};


class Solution {
  public:
    
    int maxSubTreeSum(Node* root, int &ans){
        if(root == nullptr) return 0;
        
        
        int leftSum = maxSubTreeSum(root->left, ans);
        int rightSum = maxSubTreeSum(root->right, ans);
        
        int currSum = root->data + leftSum + rightSum;
        
        ans = max(ans, currSum);
        
        return currSum;
        
        
    }
    int findLargestSubtreeSum(Node* root) {

        int ans = INT_MIN;
        maxSubTreeSum(root, ans);
        
        return ans;
        
    }
};