/*
    Problem Link : https://leetcode.com/problems/reverse-linked-list/description/
    Problem Num  : 206
    Problem Diff : Easy
*/

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

Node* convertArray2LL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1; i<arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void printLL(Node* head){
    Node* temp = head;
    while(temp){
        cout << temp->data << ' ';
        temp = temp->next;
    }
    cout << endl;
}
Node* reverseLL(Node* head){
    if(head == NULL or head->next == NULL){
        return head;
    }
    Node* newHead = reverseLL(head->next); // 7
    Node* front = head->next;
    return front;
}

//another way of reverse a Linked List

//Definition for singly-linked list.
 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* nextNode ;
        while(curr != NULL){
            nextNode = curr->next;
            curr->next = prev; // this line make link to backwards to reverse the list & cut forward link off
            prev = curr;
            curr = nextNode ; // this line for while loop only go to the last node of list
        }
        return prev; // returning 'prev' since head stored at prev node now from while loop
    }
};

int main(){
    vector<int> arr={4, 2, 5, 1, 7};
    Node* head = convertArray2LL(arr);
    head = reverseLL(head);
    printLL(head);
}