/*
    Problem Link : https://leetcode.com/problems/minimum-size-subarray-sum/description/
    Problem Name : Minimum Size Subarray Sum
    Difficulty : Medium

    Date : 16th November 2025


===============================================================================================
 
Given an array of positive integers nums and a positive integer target, return the minimal 
length of a subarray whose sum is greater than or equal to target. If there is no such subarray, 
return 0 instead.

 

Example 1:

Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
Example 2:

Input: target = 4, nums = [1,4,4]
Output: 1
Example 3:

Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0
 

Constraints:

1 <= target <= 109
1 <= nums.length <= 105
1 <= nums[i] <= 104
 

Follow up: If you have figured out the O(n) solution, try coding another solution of which 
the time complexity is O(n log(n)).

*/

#include<bits/stdc++.h>
using namespace std;


/*
    Here I've used Sliding Window technique to solve the problem efficiently 
    TC : O(N)
    SC : (1)


*/


class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int len = INT_MAX;
        int left = 0 ;
        int right = 0;
        int sum = 0 ;
        while(right < n){
            sum += nums[right];
            while(sum >= target && left <= right){
                len = min(len, right - left + 1);
                sum -= nums[left];
                left++;
            }
            right++;
        }
        return (len == INT_MAX ? 0 : len);
    }
};