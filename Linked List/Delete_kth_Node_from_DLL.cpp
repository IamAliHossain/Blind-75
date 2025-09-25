
#include<bits/stdc++.h>
using namespace std;


class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};


class Solution {
  public:
    int length(Node* head){
        int cnt = 0;
        while(head){
            cnt++;
            head = head->next;
        }
        return cnt;
    }
    
    Node* delPos(Node* head, int x) {
        // code here
        if(head == nullptr) return nullptr;
        // for head deletion where only one node availble
        if(length(head) == 1 && x == 1){
            return NULL;
        }
        // head deletion number of nodes are greater than one
        if(x == 1){
            head = head->next;
            head->prev= nullptr;
            return head;
        }
        // for tail deletion
        Node* curr = head;
        
        if(length(head) == x){ 
            int position = 0;
            Node* back;
            while(curr){
                if(curr->next == NULL){
                    back = curr->prev;
                    break;
                }
                curr = curr-> next;
            }
            back->next = NULL;
            curr->prev = NULL;
            return head;
        }
        
        // for any node deletion except head & tail
        curr = head;
        int position = 0;
        Node* front;
        Node* back;
        while(curr){
            position++;
            if(position == x){
                front = curr->next;
                back = curr->prev;
                break;
            }
            curr = curr -> next;
        }
        
        back->next = front;
        front->prev = back;
        curr->next = nullptr;
        curr->prev = nullptr;
        delete curr;
        return head;

    }
};

















