/*
    GFG is not accepting this code though logic it right
    Date : 24th september 2025

*/

#include<bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};


class Solution {
  public:
    void removeLoop(Node* head) {
        
        Node* fast_pointer = head;
        Node* slow_pointer = head;
        bool cycleExist = false;
        while(fast_pointer && slow_pointer && fast_pointer->next){
            fast_pointer = fast_pointer->next->next;
            slow_pointer = slow_pointer->next;
            if(fast_pointer == slow_pointer){
                cycleExist = true;
                break;
            }
        }
        
        if(cycleExist){
            
            Node* prev = head;
            slow_pointer = head;
            while(slow_pointer != fast_pointer){
                slow_pointer = slow_pointer->next;
                prev = fast_pointer;
                fast_pointer = fast_pointer->next;
            }
            prev->next = nullptr;
        }
    }
};