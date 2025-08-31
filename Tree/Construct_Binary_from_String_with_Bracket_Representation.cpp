/*
            This problem is not from blind75, 450 DSA cracker enlisted it from GFG

    Problem Link : https://www.geeksforgeeks.org/problems/construct-binary-tree-from-string-with-bracket-representation/1

    Problem Name : Construct Binary Tree from String with Bracket Representation
    Difficulty   : Medium
    
    Author : Ali Hossain
    Date : 31-08-2025
==============================================================================================


    Construct a binary tree from a string consisting of parenthesis and integers. 
    The whole input represents a binary tree. It contains an integer followed by zero, 
    one or two pairs of parenthesis. The integer represents the roots value and a pair 
    of parenthesis contains a child binary tree with the same structure. Always start 
    to construct the left child node of the parent first if it exists. The integer values 
    will be less than or equal to 10^5.

    Example 1:

    Input: "1(2)(3)" 
    Output: 2 1 3
    Explanation:
            1
            / \
            2   3
    Explanation: first pair of parenthesis contains 
    left subtree and second one contains the right 
    subtree. Inorder of above tree is "2 1 3".
    Example 2:

    Input: "4(2(3)(1))(6(5))"
    Output: 3 2 1 4 5 6
    Explanation:
            4
            /   \
            2     6
        / \   / 
        3   1 5   
    Your Task:
    You don't need to read input or print anything. Your task is to complete the function 
    treeFromString() which takes a string str as input parameter and returns the root node 
    of the tree.


    Expected Time Complexity: O(N)
    Expected Auxiliary Space: O(N)


    Constraints:
    1 <= |str| <= 10^6

   
*/


#include<bits/stdc++.h>
using namespace std;
/*
    Time Complexity: O(N)
    Auxiliary Space: O(N)

*/


class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};


class Solution {
  public:
  
    unordered_map<int, int> pairMap;
    
    void parenthesisMap(string s){
        
        stack<int> st;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '('){
                st.push(i);
            }
            else if(s[i] == ')'){
                pairMap[st.top()] = i;
                st.pop();
            }
        }
    }
    
    bool isDigit(char ch){
        if(ch >= '0' and ch <= '9') return true;
        return false;
    }
    
    Node* buildTree(string &s, int startId, int eId){
        if(startId > eId) return NULL;
        
        int num = 0;
        while(startId < s.size() && isDigit(s[startId])){
            num = num * 10 + (s[startId] - '0');
            startId++;
        }
        
        startId--;

        // now create new root using num
        Node* root = new Node(num);
        
        int index = -1;
        
        if(startId + 1 <= eId and s[startId+1] == '('){
            index = pairMap[startId+1];
        }
        
        if(index != -1){ 
            root->left = buildTree(s, startId+2, index-1);
            
            root->right = buildTree(s, index+2, eId-1);
        }
        
        return root;
    }
    
    Node *treeFromString(string str) {
        parenthesisMap(str);
        
        return buildTree(str, 0, str.length()-1);
        
    }
};