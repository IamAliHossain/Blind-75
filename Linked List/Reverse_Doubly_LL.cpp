/*  
    Problem Link : https://www.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1
    Problem Name : Reverse a Doubly Linked List
    Difficulty : Medium

------------------------------------------------------------------------------------------

    You are given the head of a doubly linked list. You have to reverse the doubly 
    linked list and return its head.

    Examples:

    Input:
    
    Output: 5 <-> 4 <-> 3
    Explanation: After reversing the given doubly linked list the new list will be 5 <-> 4 <-> 3.
    
    Input: 
    
    Output: 196 <-> 59 <-> 122 <-> 75
    Explanation: After reversing the given doubly linked list the new list will 
    be 196 <-> 59 <-> 122 <-> 75.
    
    Constraints:
    1 ≤ number of nodes ≤ 10^6
    0 ≤ node->data ≤ 10^4



*/



/*
    There are multiple approaches to reverse a Doubly Linked List

*/

#include<bits/stdc++.h>
using namespace std;


class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};


// Solution 1 : Solution using stack

/*
    
    TC : O(N)
    SC : O(N)

*/

class Solution {
  public:
    Node *reverse(Node *head) {
       if(head == nullptr) return head;
       Node* temp = head;
       stack<int> st;
        while(temp){
            st.push(temp->data);
            temp = temp->next;
        }
        temp = head;
        while(!st.empty()){
            int val = st.top();
            st.pop();
            temp->data = val;
            temp = temp->next;
        }
        return head;
    }
};


// Optimal Solution(in place avoid stack)
/*
    TC : O(N)
    SC : O(1)

    inner loop :

    যতক্ষণ পর্যন্ত curr null না হয়, প্রতিটি node এর next আর prev কে swap করবো।

    আগে back = curr->prev রেখে দিলাম, যেন পরে দরকার হয়।

    তারপর curr->prev = curr->next করলাম → অর্থাৎ আগের pointer এখন pointing করছে পরের দিকে।

    আর curr->next = back করলাম → অর্থাৎ পরের pointer pointing করছে আগের দিকে।

    শেষে curr = curr->prev করলাম → এখন যেহেতু prev আর next swap হয়ে গেছে, তাই পরের node 
    এ যেতে হলে prev দিয়ে move করতে হবে।

*/
class Solution{
    public:
        Node* reverse(Node* head){
            if(head == NULL || head->next == NULL) return head;
            
            Node* back = NULL;
            Node* curr = head;
            while(curr){
                back = curr->prev;
                curr->prev = curr->next;
                curr->next = back;
                // এখন যেহেতু prev আর next swap হয়ে গেছে, তাই পরের node এ যেতে হলে 
                // prev দিয়ে move করতে হবে।
                curr = curr->prev; 
            }
            // back আসলে শেষ iteration এর সময় curr->prev এর মান ধরে রেখেছিল। 
            // তাই শেষে back->prev নতুন head হবে।
            return back->prev;
        }
};

/*
    ✅ উদাহরণ (ছোট লিস্ট)

    ধরা যাক লিস্ট: 1 <-> 2 <-> 3

    শুরুতে: head = 1

    Iteration 1:
    curr = 1
    swap করলে → 1 এর next/prev পাল্টে যাবে
    curr চলে যাবে 2 এর দিকে।

    Iteration 2:
    curr = 2
    swap করলে → 2 এর next/prev পাল্টে যাবে
    curr চলে যাবে 3 এর দিকে।

    Iteration 3:
    curr = 3
    swap করলে → 3 এর next/prev পাল্টে যাবে
    curr = NULL (শেষ)।

    এখন নতুন head হবে back->prev = 3।
    ফাইনালি লিস্ট: 3 <-> 2 <-> 1

*/
