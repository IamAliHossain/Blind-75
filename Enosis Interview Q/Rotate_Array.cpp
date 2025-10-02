/*
    Problem Link : https://leetcode.com/problems/rotate-array/description/
    Problem Name : Rotate Array
    Difficulty : Medium

    Date : 2nd October 2025


========================================================================================

Given an integer array nums, rotate the array to the right by k steps, 
where k is non-negative.


Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
 

Constraints:

1 <= nums.length <= 10^5
-2^31 <= nums[i] <= 2^31 - 1
0 <= k <= 10^5
 

Follow up:

Try to come up with as many solutions as you can. There are at least three 
different ways to solve this problem.

Could you do it in-place with O(1) extra space?


*/

#include<bits/stdc++.h>
using namespace std;

/*
    This is using extra space so space complexity 
    O(N) but I am asked to solve using O(1) space
    I'll do it next solution

    TC : O(n)

*/
// Solution 1
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        
        int n = nums.size();
        k = k % n;

        vector<int> v;
        for(int i=n-k; i<n; i++){
            v.push_back(nums[i]);
        }
        for(int i=0; i<n-k; i++){
            v.push_back(nums[i]);
        }
        for(int i=0; i<n; i++){
            nums[i] = v[i];
        }
    }
};

// Solution 2 optimal code

/*
    This is most optimal solution using O(1) space complexity

    Let's Dry Run :
    n = 7, k = 3
    Original Array ---------------------->[1,2,3,4,5,6,7]
    reverse whole array once -----------> [7,6,5,4,3,2,1]
    reverse 1st k elements now----------> [5,6,7,4,3,2,1]
    reverse from kth element to last ---> [5,6,7,1,2,3,5]

    TC : O(n)
    SC : O(1)

*/

class Solution {
public:
    void reverse(vector<int>& nums, int start, int end){
        while(start < end){
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        
        int n = nums.size();
        k = k % n;
        reverse(nums, 0, n-1);
        reverse(nums, 0, k-1);
        reverse(nums, k, n-1);
        
    }
};