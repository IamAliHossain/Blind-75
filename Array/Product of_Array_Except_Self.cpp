/*
    Problem Link: https://leetcode.com/problems/product-of-array-except-self/description/
    Problem Name: Product of Array Except Self
    Difficulty  : Medium
    Time Complexity : O(N)
    Space Complexity: O()

    
    Given an integer array nums, return an array answer such that answer[i] is equal to 
    the product of all the elements of nums except nums[i].

    The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

    You must write an algorithm that runs in O(n) time and without using the division operation.

 

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
 

Constraints:

2 <= nums.length <= 10^5
-30 <= nums[i] <= 30
The input is generated such that answer[i] is guaranteed to fit in a 32-bit integer.
 

Follow up: Can you solve the problem in O(1) extra space complexity? (The output array 
does not count as extra space for space complexity analysis.)

*/

#include<bits/stdc++.h>
using namespace std;
/* 
    Solution using Divison operation but it problem said to not use division operation
    that's why go below for best solution
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1, zeroCnt = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]) product *= nums[i];
            else zeroCnt++;
        }
        vector<int> ans;
        if(zeroCnt > 1){
            for(int i=0; i<nums.size(); i++){
                ans.push_back(0);
            }
        }
        else if(zeroCnt == 1){ 
            for(int i=0; i<nums.size(); i++){
                if(nums[i])ans.push_back(0);
                else{
                    ans.push_back(product);
                }
            }
        }
        else{
            for(int i=0; i<nums.size(); i++){
                ans.push_back(product/nums[i]);
            }
        }
        return ans;
    }
};



/*
    This solution is mine after 45 minutes of brainstorming : 

    যেই index এ আছি সেই index এর আগের prefix product & তার পরের index এর suffix product 
    multiply করে ঐ index এর product পাবো except that index, এজন্য we need a prefix product array 
    যেটা index er left part er product bear করবে & একটা suffix product array লাগবে 
    যেটা কোন index এর right part এর suffix product bear করবে ।

    কোন index এর product except that index = prefProduct[index-1] * suffixProduct[inex+1]
 
    TC : O(N)
    SC : O(N) + O(N) : O(N)

    Follow Up task for Space Complexity is O(!) where I used O(N) that's why I need to 
    optimize that which added in the next solution 3
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefProd(n), suffProd(n);
        prefProd[0] = nums[0];
        suffProd[n-1] = nums[n-1];
        for(int i=1; i<n; i++){
            prefProd[i] = prefProd[i-1] * nums[i];
        }
        for(int i=n-2; i>=0; i--){
            suffProd[i] = suffProd[i+1] * nums[i];
        }
        for(int i=0; i<n; i++){
            if(i == 0){
                nums[i] = suffProd[i+1];
            }
            else if(i == n-1){
                nums[i] = prefProd[i-1];
            }
            else{
                nums[i] = prefProd[i-1] * suffProd[i+1];
            }
        }
        return nums;
    }
};