/*  
    This problem is a Leetcode Premium

    Problem Link : https://www.geeksforgeeks.org/problems/remove-duplicates-from-an-unsorted-linked-list/1
    Problem Name : Remove Duplicates from unsorted List
    Difficulty : Easy

    Date : 30th sept 2025

============================================================================================

    Given an unsorted linked list. The task is to remove duplicate elements from this 
    unsorted Linked List. When a value appears in multiple nodes, the node which appeared 
    first should be kept, all other duplicates are to be removed.

    Examples:

    Input: LinkedList: 5->2->2->4
    Output: 5->2->4
    Explanation: Given linked list elements are 5->2->2->4, in which 2 is repeated only. 
    So, we will delete the extra repeated elements 2 from the linked list and the 
    resultant linked list will contain 5->2->4
    
    Input: LinkedList: 2->2->2->2->2
    Output: 2
    Explanation:Given linked list elements are 2->2->2->2->2, in which 2 is repeated. 
    So, we will delete the extra repeated elements 2 from the linked list and the 
    resultant linked list will contain only 2.

    Expected Time Complexity: O(n)
    Expected Space Complexity: O(n)

    Constraints:
    1 <= number of nodes <= 10^6
    0 <= node->data <= 10^6

*/


#include<bits/stdc++.h>
using namespace std;


//Definition for singly-linked list.
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

/*
    Time Complexity: O(n)
    Space Complexity: O(n)

*/

class Solution {
  public:
    Node *removeDuplicates(Node *head) {
        if(head == NULL || head->next == NULL) return head;
        

        unordered_set<int> se;

        Node* dummy = new Node(-1);
        Node* prev = dummy;
        Node* curr = head;
        while(curr){
            if(se.find(curr->data) == se.end()){
                se.insert(curr->data);
                prev->next = curr;
                prev = curr;
            }
            else{
                prev->next = curr->next;
            }
            curr = curr->next;
        }
        return dummy->next;
    }
};