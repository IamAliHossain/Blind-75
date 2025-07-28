/*
    Problem Link: https://leetcode.com/problems/search-in-rotated-sorted-array/description/
    Problem Name: Search in Rotated Sorted Array
    Difficulty  : Medium
    Time Complexity : O(log N)
    Space Complexity: O(1)

    If arr[low] <= arr[mid]: In this case, we identified that the left half is sorted.
    If arr[mid] <= arr[high]: In this case, we identified that the right half is sorted.
        but need to check whether target is in this range or not also in both case
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, hi = n-1;
        int ansId = -1;
        while(l <= hi){
            int mid = l + (hi - l) / 2 ;
            if(nums[mid] == target){
                return mid;
            }
            if(nums[l] <= nums[mid]){
                if(nums[l] <= target and target <= nums[mid]){
                    hi = mid ;
                }
                else{ 
                    l = mid + 1;
                }
            }
            else if(nums[mid] <= nums[hi]){
                if(nums[mid] <= target and target <= nums[hi]){
                    l = mid;
                }
                else{
                    hi = mid - 1;
                } 
            }  
        }
        return -1;
    }
};