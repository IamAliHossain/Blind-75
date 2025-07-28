/*
    Problem Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
    Problem Name: Remove Nth Node From End of List
    Problem Diff: Medium

*/

/*Two pointer Solution Technique*/

#include<bits/stdc++.h>
using namespace std;

class ListNode{
    public:
    int data;
    ListNode* next;

    ListNode(int data1, ListNode* next1){
        data = data1;
        next = next1;
    }
    ListNode(int data1){
        data = data1;
        next = nullptr;
    }
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* fast_pointer = head;
    ListNode* slow_pointer = head;
    for(int i=0; i<n; i++){
        fast_pointer = fast_pointer->next;
    }
    if(fast_pointer == NULL)return head->next;
    while(fast_pointer->next != NULL){
        fast_pointer = fast_pointer->next;
        slow_pointer = slow_pointer->next;
    }
    ListNode* delNode = slow_pointer->next;
    slow_pointer->next = slow_pointer->next->next;
    delete delNode;
    return head;
}

int main(){

    return 0;
}