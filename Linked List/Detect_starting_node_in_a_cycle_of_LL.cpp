/*
    Problem Link : https://www.geeksforgeeks.org/problems/find-the-first-node-of-loop-in-linked-list--170645/1
    Problem Name : Find the first node of loop in linked list
    Difficulty   : Medium

    Date : 24th september 2025
--------------------------------------------------------------------------------------------------------
    You are given the head of a singly linked list. If a loop is present in the linked list 
    then return the first node of the loop else return -1.

    Note: Internally, pos(1 based index) is used to denote the position of the node that tail's 
    next pointer is connected to. If pos = 0, it means the last node points to null, indicating 
    there is no loop. Note that pos is not passed as a parameter.

    Examples:

    Input: pos = 2,
    
    Output: 3
    Explanation: We can see that there exists a loop in the given linked list and the first node 
    of the loop is 3.
    Input: pos = 0,
    
    Output: -1
    Explanation: No loop exists in the above linked list. So the output is -1.
    Constraints:
    1 ≤ no. of nodes ≤ 10^6
    1 ≤ node->data ≤ 10^6 



*/




#include<bits/stdc++.h>
using namespace std;

// Definition of Node
class Node {
public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
  public:
    int cycleStart(Node* head) {

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
            slow_pointer = head;
            while(slow_pointer != fast_pointer){
                slow_pointer = slow_pointer->next;
                fast_pointer = fast_pointer->next;
            }
            return slow_pointer->data;
        }
        
        return -1;
    }
};