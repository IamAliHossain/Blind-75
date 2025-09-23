/*
    Problem Link : https://leetcode.com/problems/reverse-nodes-in-k-group/description/
    Problem Name : Reverse Nodes in K group
    Problem Diff : Hard

    Date : 23-09-2025

---------------------------------------------------------------------------------------------------------

    Given the head of a linked list, reverse the nodes of the list k at a time, and return the 
    modified list.

    k is a positive integer and is less than or equal to the length of the linked list. 
    If the number of nodes is not a multiple of k then left-out nodes, in the end, 
    should remain as it is.

    You may not alter the values in the list's nodes, only nodes themselves may be changed.

    

    Example 1:


    Input: head = [1,2,3,4,5], k = 2
    Output: [2,1,4,3,5]
    Example 2:


    Input: head = [1,2,3,4,5], k = 3
    Output: [3,2,1,4,5]
    

    Constraints:

    The number of nodes in the list is n.
    1 <= k <= n <= 5000
    0 <= Node.val <= 1000
    

    Follow-up: Can you solve the problem in O(1) extra memory space?

*/


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


/*  
    My Intution (সহজভাবে)

    পুরো লিঙ্কড লিস্টটা প্রথমে দেখে নিতে হবে, মোট কয়টা নোড আছে সেটা জানা জরুরি। না হলে শেষ দিকে 
    যদি k এর চেয়ে কম নোড থাকে তখন সমস্যা হবে। তাই আগে length বের করি।

    তারপর চিন্তা করি—
    “যতক্ষণ পর্যন্ত k নোড পাওয়া যাচ্ছে, ততক্ষণ ওই k নোড একসাথে reverse করব।”

    একেকটা গ্রুপ রিভার্স করার পর সেটা নতুন লিস্টে যুক্ত করতে হবে।

    প্রথম গ্রুপ হলে সেটাই হবে নতুন head।

    পরের গ্রুপগুলোকে আগের গ্রুপের শেষে জুড়ে দিতে হবে।

    একেকটা গ্রুপ শেষ হলে, সেই গ্রুপের শুরুটা (যেটা রিভার্সের পর শেষে চলে যায়) হবে tail। ওই tail দিয়ে 
    পরের গ্রুপকে লিঙ্ক করাব।

    যখন শেষের দিকে k এর কম নোড বাকি থাকবে, তখন আর রিভার্স করব না—সরাসরি যেভাবে আছে সেভাবেই 
    tail-এর সাথে লিঙ্ক করব।

    Total time complexity: 
        Length calculation: O(n)
        Reversals: O(n)
        Overall: O(n)

    Space complexity :
        No extra data structures (only pointers).
        Space: O(1)

*/

int listLen(ListNode* head){
    int cnt = 0;
    while(head){
        head = head ->next;
        cnt++;
    }
    return cnt;
}

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr) return head;

        ListNode* curr = head;
        ListNode* newList = nullptr;
        ListNode* tail = nullptr;
        int len = listLen(head); // O(n)

        while(curr && len>=k){ // O(n / k)

            ListNode* groupHead = curr;
            ListNode* prev = nullptr;
            ListNode* nextNode = nullptr;
            
            // group wise reveresed now by 2nd while loop

            int temp = k ;
            while(curr && temp){ // O(k)
                nextNode = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextNode;
                temp--;
            }
            len -= k;
            if(newList == nullptr){
                newList = prev;
            }

            if(tail != nullptr){
                tail -> next = prev;
            }
            tail = groupHead;
            
        }
        // when len % k != 0 then some nodes remains so need to take them at the last
        if(tail != nullptr){
            tail->next = curr;
        }
        return newList;
    }
};