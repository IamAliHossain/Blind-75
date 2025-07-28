/*
    Problem Link : https://leetcode.com/problems/reorder-list/description/ 
    Problem Name : Redorder List
    Difficulty : Medium 

    
    Time Complexity : O(N) [Middle of List] + O(N/2) [Reversing Second Half] + O(N/2) [Connecting both lists]  = O(2N)  = O(N)
    Space Complexity: O(1)


    Solution Technique: 
    step1 : Find middle point of List
    step2 : Reverse the List Till middle point
    step3 : Enventually connect them as the wanted order
 
 */
#include<bits/stdc++.h>
using namespace std;

class ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    
    ListNode* middle(ListNode* head){
        ListNode* fast_pointer = head;
        ListNode* slow_pointer = head;
        while(fast_pointer->next and fast_pointer->next->next){
            slow_pointer = slow_pointer->next;
            fast_pointer = fast_pointer->next->next;
        }
        return slow_pointer;
    }

    ListNode* reverseLL(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* forw = NULL;
        while(curr){
            forw = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forw;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return;
        }
        ListNode* midPoint = middle(head);
        ListNode* revLL_from_midPoint = reverseLL(midPoint->next);
        ListNode* revHead = revLL_from_midPoint;
        midPoint->next = NULL; // making last node nullptr

        ListNode* node1 = head;
        ListNode* node2 = revHead;
        ListNode* link1 = NULL;
        ListNode* link2 = NULL;
        while(node1 != NULL and node2 != NULL){
            link1 = node1->next;
            link2 = node2->next;

            node1->next = node2;
            node2->next = link1;

            node1 = link1;
            node2 = link2;
        }
    }
};


// something updates on that above code
class Solution {
public:
    
    // finding middle node using Floyd Warshal algorithm
    ListNode* middleNode(ListNode* head){
        ListNode* oneStep = head;
        ListNode* twoStep = head;
        while(oneStep != NULL && twoStep != NULL && twoStep->next != NULL){
            oneStep = oneStep ->next;
            twoStep = twoStep ->next ->next;
        }
        return oneStep;
    }
    //
    ListNode* reverseLL(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* nextNode;
        while(curr != nullptr){
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL) return;

        ListNode* midNode = middleNode(head);
        ListNode* reverse_from_midNode = reverseLL(midNode->next);
        ListNode* revHead = reverse_from_midNode;
        midNode -> next = NULL;

        ListNode* fstList = head;
        ListNode* scndList = revHead;
        
        ListNode* link1 = NULL;// it helps to connect diagonally 
        ListNode* link2 = NULL;

        while(fstList != NULL && scndList != NULL){
            link1 = fstList ->next;
            link2 = scndList ->next;

            fstList->next = scndList;
            scndList->next = link1;

            fstList = link1;
            scndList = link2;
        }
    }
};