/*
    Problem Link : https://leetcode.com/problems/sort-an-array/description/?ref=formation.dev
    Problem Name : Sort an array
    Difficulty : Medium

    Date : 17 sept 2025


================================================================================================

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

// Soluion1
/*

    To sort the array without built-in function we have to use max-heap concept
    step1 : convert the array into a max-heap
            so that we can easily sort the array
    step2 : swap the first and the last element of heap
            then heapify after swaping operation
            and decrease the size of the heap since one is completed after each
            operation
    

    heapify will make valid max-heap, aftwards max-heap will be sorted in ascending order

    TC : O(n * logn)
    SC : O(log n), due to the recursive call stack. 
                However, auxiliary space can be O(1) for iterative implementation.

*/

class Solution {
public:
    // let's build max-heap from given array by doing heapify(node shifting)
    void heapify(vector<int>&nums, int n, int i){
        int largest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;
        if(left < n && nums[largest] < nums[left]){
            largest = left;
        }
        if(right < n && nums[largest] < nums[right]){
            largest = right;
        }
        // parent and child node not same means need to swap both nodes 
        if(largest != i){
            swap(nums[largest], nums[i]);
            heapify(nums, n, largest);
        }
    }

    // since my array now converted to min-heap now let's sort in ascending order
    void heapSort(vector<int> &nums, int size){
        while(size){
            swap(nums[size], nums[0]);
            heapify(nums, size, 0);
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


// Merge sort
/*

    Previous soluiton was using Heap Sort, now I'll apply Merge Sort Technique
    
    Merge sort follow divide and conquer rule :
        1. Array কে দুই ভাগে ভাগ করা
        2. প্রতিটা ভাগকে recursively sort করা
        3. তারপর merge করে একসাথে আনা
    
    TC : O(n * logn)
    SC : O(n), due to extra array using

*/

class Solution {
public:
    void merge(vector<int> &nums, int low, int mid, int high){
        int left = low;
        int right = mid+1;
        vector<int> temp;
        while(left <= mid && right <= high){
            if(nums[left] <= nums[right]){
                temp.push_back(nums[left]);
                left++;
            }
            else{
                temp.push_back(nums[right]);
                right++;
            }
        }
        // যদি left part এ কিছু বাকি থাকে → সবগুলো temp এ ঢুকিয়ে দিচ্ছে
        while(left <= mid){
            temp.push_back(nums[left]);
            left++;
        }
        // যদি right part এ কিছু বাকি থাকে → সেগুলোও temp এ ঢুকিয়ে দিচ্ছে
        while(right <= high){
            temp.push_back(nums[right]);
            right++;
        }
        // i-low ব্যবহার করা হয়েছে যেন temp এর 0-based index কে nums এর low-based index এর সাথে map করা যায়।
        // ধরা যাক low = 3, high = 6
        // nums[3] এ বসাতে চাইলে temp[3] নিতে যেতো, কিন্তু temp[3] হয়তো আসলেই নেই, cause each temp is created in fresh
        for(int i=low; i<=high; i++){
            nums[i] = temp[i-low]; 
        }
    }
    void mergeSort(vector<int>& nums, int low, int high){
        if(low == high) return;
        int mid = (low + high) / 2 ;
        mergeSort(nums, low, mid);
        mergeSort(nums, mid+1, high);
        merge(nums, low, mid, high);
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        mergeSort(nums, 0, n-1);
        return nums;
    }
};

// quick sort
/*

    Previous 2 soluiton were using Heap Sort and Merge Sort, now I'll apply Quick Sort Technique
    which is Memory efficient than Merge Sort
    
    Quick sort follow divide and conquer rule :
        
    Time Complexity:
        Best & Average Case → O(n log n)
        Worst Case (যখন array already sorted / pivot খারাপ choose হয়) → O(n^2)
            Such as : [110, 100, 0] will give TLE
            
    Space Complexity: O(1) (in-place কাজ করছে)


    partition() → pivot ঠিক জায়গায় বসায়।
    quickSort() → divide করে বাম আর ডান অংশ recursively sort করে।
s   ortArray() → main entry point।

*/

class Solution {
public:
    int partition(vector<int>&nums, int i, int j){
        int low = i;
        int pivot = nums[low]; // pivot হিসেবে প্রথম element (nums[low]) নেওয়া হলো you choose any element
        
        // আমাদের কাজ হলো pivot-এর থেকে ছোট element গুলোকে বাম দিকে আনা, 
        // আর বড় element গুলোকে ডান দিকে আনা।
        while(i < j){
            while(nums[i] <= pivot && i < j){
                i++;
            }
            while(nums[j] >= pivot && j >= i){
                j--;
            }
            if(i < j){
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[low], nums[j]);

        return j;
    }
    void quickSort(vector<int> &nums, int low, int high){
        if(low > high) return; // যদি low > high, তাহলে কিছু করার দরকার নেই (empty subarray)।

        int partitionIndex = partition(nums, low, high);  //প্রথমে partition() call করে pivot-এর সঠিক জায়গা বের করে আনা হয়।
        quickSort(nums, low, partitionIndex-1); // তারপর বাম দিক (low → partitionIndex-1) sort করা হয়।
        quickSort(nums, partitionIndex+1, high); // তারপর ডান দিক (partitionIndex+1 → high) sort করা হয়।
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        quickSort(nums, 0, n-1);
        return nums;
    }
};