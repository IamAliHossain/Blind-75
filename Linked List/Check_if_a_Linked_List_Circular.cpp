
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};


/* Should return true if linked list is circular, else false */
class Solution {
  public:
    bool isCircular(Node *head) {
        if(head == nullptr) return true; // if it is empty then circular Linked List

        Node* temp = head;
        while(temp != NULL){
            if(temp->next == head){
                return true;
            }
            temp = temp -> next;
        }
        return false;
        
    }
};