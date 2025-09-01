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


/*
    Dry Run for input : [20, -9, 20, null, null, 15, 7 ]
    Output is : 55

    3️⃣ Step-by-Step Recursion Trace
    🟢 Leaf Nodes (Bottom থেকে শুরু)

    Node 15

            left = 0

            right = 0

            currSum = 15 + 0 + 0 = 15

            maxPathSum = max(-∞, 15) = 15

            return = max(15+0, 15+0) = 15

    Node 7: 
            left = 0

            right = 0

            currSum = 7

        maxPathSum = max(15, 7) = 15

        return = 7

    🟢 Node 20 (right child of root)

            leftSum = max(0, dfs(15)) = max(0, 15) = 15

            rightSum = max(0, dfs(7)) = max(0, 7) = 7

            currSum = 20 + 15 + 7 = 42

            maxPathSum = max(15, 42) = 42

            return = max(20+15, 20+7) = max(35, 27) = 35

    🟢 Node -9 (left child of root)

            left = 0, right = 0

            currSum = -9

            maxPathSum = max(42, -9) = 42

            return = max(-9, -9) = -9

    🟢 Root Node 20

            leftSum = max(0, dfs(-9)) = max(0, -9) = 0

            rightSum = max(0, dfs(20_right)) = max(0, 35) = 35

            currSum = 20 + 0 + 35 = 55

            maxPathSum = max(42, 55) = 55

            return = max(20+0, 20+35) = max(20, 55) = 55

    4️⃣ Final Result

    Maximum Path Sum = 55

    Path = 15 → 20 → 20

    🔎 Recursion Tree Flow Summary
    dfs(15) = 15   → maxPathSum = 15
    dfs(7)  = 7    → maxPathSum = 15
    dfs(20_right) = 35 → maxPathSum = 42
    dfs(-9) = -9   → maxPathSum = 42
    dfs(20_root) = 55 → maxPathSum = 55

*/


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
        
        //this line for taking maximum node either left path or right path from a node returns to parent node
        return root->val + max(0, max(leftNode, rightNode));
    }
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN ;
        sum(root, maxi);
        return maxi ;
    }
};