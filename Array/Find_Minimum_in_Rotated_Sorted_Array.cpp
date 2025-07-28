
/*
    Problem Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-srray/description/
    Problem Name: Find Minimum in Rotated Sorted Array
    Difficulty  : Easy
    Time Complexity : O(log N)
    Space Complexity: O(1)

*/

#include<bits/stdc++.h>
using namespace std;

/*
    We basically compare arr[mid] with arr[low] and arr[high] in the following way:

    If arr[low] <= arr[mid]: In this case, we identified that the left half is sorted.
    If arr[mid] <= arr[high]: In this case, we identified that the right half is sorted.

    Example:{4,5,1,2,3}
    low=0,high=4,mid=2
    Check if arr[low] <= arr[mid], its not, 
    So right part is sorted. 
    We take ans=min(ans,arr[2]) => ans=1, and high = mid-1.

    low=0,high=1,mid=0;
    arr[low]<=arr[mid] = true. 
    So we update ans as min(ans,arr[0]) => ans=1; 
    Since the left part was sorted low=mid+1. Which makes low = high = 1.

    low=1,high=1,mid=1
    arr[low] <= arr[mid] = true. 
    So we update ans as min(ans,arr[1]) => ans=1;  
    Since the left part was sorted low=mid+1. Which makes low = 2. Loop Stops.
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0, hi = n - 1, mini = INT_MAX;
        while(l <= hi){
            int mid = l + (hi - l) / 2 ;
            if(nums[l] <= nums[mid]){
                mini = min(mini, nums[l]);
                l = mid + 1;
            }
            else{
                mini = min(mini, nums[mid]);
                hi = mid - 1;
            }
        }
        return mini;
    }
};