/*
    This is not from Blind-75 series. This is taken from "450 DSA Cracker"
    Link : https://450dsa.com/heap


    Problem Link from Leetcode : https://leetcode.com/problems/sort-an-array/description/
    Difficulty : Medium

    Date : 17-08-2025


-----------------------------------------------------------------------------------------------------


    Given an array of integers nums, sort the array in ascending order and return it.

    You must solve the problem without using any built-in functions in O(nlog(n)) time complexity 
    and with the smallest space complexity possible.

    

    Example 1:

    Input: nums = [5,2,3,1]
    Output: [1,2,3,5]
    Explanation: After sorting the array, the positions of some numbers are not changed 
    (for example, 2 and 3), while the positions of other numbers are changed (for example, 1 and 5).
    
    
    Example 2:

    Input: nums = [5,1,1,2,0,0]
    Output: [0,0,1,1,2,5]
    Explanation: Note that the values of nums are not necessarily unique.
    

    Constraints:

    1 <= nums.length <= 5 * 10^4
    -5 * 10^4 <= nums[i] <= 5 * 10^4


*/


#include<bits/stdc++.h>
using namespace std;


/*

    To sort the array without built-in function we have to use max-heap concept
    step1 : convert the array into a max-heap
            so that we can easily sort the array
    step2 : swap the first and the last element of heap
            then heapify after swaping operation
            and decrease the size of the heap since one is completed after each
            operation
    

    heapify will make valid max-heap

    TC : O(n * logn)

*/

class Solution {
public:
    void heapify(vector<int> &ar, int n, int i){
        int largest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;
        
        if(left < n && ar[largest] < ar[left]){
            largest = left;
        }
        if(right < n && ar[largest] < ar[right]){
            largest = right;
        }

        if(largest != i){
            swap(ar[largest], ar[i]);
            heapify(ar, n, largest);
        }
    }

    void heapSort(vector<int> &ar, int n){
        int size = n;
        while(size){
            swap(ar[size], ar[0]);
            heapify(ar, size, 0);
            size--;
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        for(int i=n/2-1; i>=0; i--){
            heapify(nums, n, i);
        }
        heapSort(nums, n-1);
        return nums;
    }
};