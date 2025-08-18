/*
    This is not from Blind-75 series. This is taken from "450 DSA Cracker"
    Link : https://450dsa.com/heap


    Problem Link : https://leetcode.com/problems/kth-largest-element-in-an-array/description/
    Problem Name : 215. Kth Largest Element in an Array
    Difficulty : Medium

    Date : 18-08-2025


-----------------------------------------------------------------------------------------------------

    Given an integer array nums and an integer k, return the kth largest element in the array.

    Note that it is the kth largest element in the sorted order, not the kth distinct element.

    Can you solve it without sorting?

    

    Example 1:

    Input: nums = [3,2,1,5,6,4], k = 2
    Output: 5
    Example 2:

    Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
    Output: 4
    

    Constraints:

    1 <= k <= nums.length <= 10^5
    -10^4 <= nums[i] <= 10^4
        
*/


#include<bits/stdc++.h>
using namespace std;


/*

    TC : O(N*logN)
    SC : O(N)
*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> maxHeap;
        for(int i=0; i<nums.size(); i++){
            maxHeap.push(nums[i]);
        }
        int i=0;
        for(int i=0; i<k-1; i++){
            maxHeap.pop();
        }
        int largestElement = maxHeap.top();
        return largestElement;
    }
};

