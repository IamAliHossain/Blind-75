/*
    Problem Link: https://leetcode.com/problems/linked-list-cycle/
    Problem Name: Linked List Cycle
    Problem Diff: Easy

*/
 /* solution using Floyd Warshall Cycle Finding Algorithm 
    Follow the steps below to solve the problem:

    1. Traverse linked list using two pointers.
    2. Move one pointer(slow) by one step ahead and another pointer(fast) by two steps ahead.
    3. If these pointers meet at the same node then there is a loop. 
        If pointers do not meet then the linked list doesn’t have a loop.
 */

 #include<bits/stdc++.h>
 using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


// This is solved by using hare and tortoise algorithm, also known as Floyd Warshall algo
// TC : O(N)
// SC : O(1)
class Solution {
    public:
    bool hasCycle(ListNode *head) {
        
        ListNode* oneStep = head;
        ListNode* twoStep = head;

        while(oneStep != NULL && twoStep != NULL && twoStep->next != NULL){
            oneStep = oneStep->next;
            twoStep = twoStep->next->next;
            // if they meet, there is a cycle
            if(oneStep == twoStep){
                return true;
            }
        }
        return false;
    }
};
