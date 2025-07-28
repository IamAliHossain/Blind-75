/*
    Problem Link    : https://leetcode.com/problems/merge-k-sorted-lists/description/
    Problem Name    : 23. Merge k Sorted Lists
    Difficulty      : Hard
    Time Complexity : 
    Space Complexity: 

    Author : Ali Hossain
    Date : 21-05-2025

===================================================================================================
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

 

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []
 

Constraints:

k == lists.length
0 <= k <= 10^4
0 <= lists[i].length <= 500
-10^4 <= lists[i][j] <= 10^4
lists[i] is sorted in ascending order.
The sum of lists[i].length will not exceed 10^4.

*/

#include<bits/stdc++.h>
using namespace std;


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Bruteforce Approach:
// Time Complexity : O(n) + O(n * logn) ---> n for traversing the lists and nlogn for sorting the vector
// In the worscase O(nlogn)
class Solution {
public:

    ListNode* convertArr2List(vector<int> & arr){
        ListNode* dummyNode = new ListNode(-1);
        ListNode* mover = dummyNode;
        for(int i=0; i<arr.size(); i++){
            ListNode* temp = new ListNode(arr[i]);
            mover->next = temp;
            mover = temp;
        }
        return dummyNode->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> ans;
        for(int i=0; i<lists.size(); i++){
            ListNode* temp = lists[i];
            while(temp){
                ans.push_back(temp->val);
                temp = temp->next;
            }
        }
        sort(ans.begin(), ans.end());
        return convertArr2List(ans);
    }
};


// Optimal Approach:
// Time Complexity : in the for loop O(k * longk) logk for push operation in priority_queue
//                   in the while loop O(k * n * logk) n for all list in the lists and logk for operation in pq pq.top(), pq.pop(), pq.push()
//  TC : O(k*log) + O(k * n * logk) = O(k * n * logk)

// Space Complexity: O(k) just used a priority_queue 


class Solution {
public:

    // optimal approach using min-heap concept

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;
        for(int i=0; i<lists.size(); i++){
            if(lists[i]){ 
                // stores only head node of all non-null lists
                pq.push({lists[i]->val, lists[i]});
            }
        }
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode ;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            // storing the next node if it is not null
            if(it.second->next){
                pq.push({it.second->next->val, it.second->next});
            }
            // taking the next node of the merged k list
            temp->next = it.second;
            temp = temp->next;
        }
        return dummyNode->next;
    }
};