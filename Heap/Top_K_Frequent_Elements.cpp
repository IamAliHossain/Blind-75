/*
    Problem Link    : https://leetcode.com/problems/top-k-frequent-elements/description/
    Problem Name    : 347. Top K Frequent Elements
    Difficulty      : Hard
    Time Complexity : 
    Space Complexity: 

    Author : Ali Hossain
    Date : 22-05-2025

===================================================================================================


    Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

    

    Example 1:

    Input: nums = [1,1,1,2,2,3], k = 2
    Output: [1,2]
    Example 2:

    Input: nums = [1], k = 1
    Output: [1]
    

    Constraints:

    1 <= nums.length <= 10^5
    -10^4 <= nums[i] <= 10^4
    k is in the range [1, the number of unique elements in the array].
    It is guaranteed that the answer is unique.
    

    Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Bruteforce approach:
    // TC : O(nums.size()) + O(n * logn) : O(n * logn)
    // SC : O(k)
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        vector<pair<int, int>> p;
        for(int i=0; i<nums.size(); i++){
            hash[nums[i]]++;
        }
        for(auto u : hash){
            p.push_back({u.second, u.first});
        }
        vector<int> ans;
        sort(p.begin(), p.end(), greater<pair<int, int>>());
        for(auto u : p){
            k--;
            ans.push_back(u.second);
            if(k == 0)break;
        }
        return ans;
    }
};


class Solution {
public:
    // Optimal approach: using bucket sort algorithm
    // TC : O(nums.size()) + O(n) + O(n) : O(n)
    // SC : O(k)
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hash;

        for(int i=0; i<nums.size(); i++){
            hash[nums[i]]++;
        }

        vector<vector<int>>bucket(nums.size()+1);
        for(auto u : hash){
            bucket[u.second].push_back(u.first);
        }
        vector<int> ans;
        for(int i=bucket.size()-1; i>=0; i--){
            for(auto val : bucket[i]){
                ans.push_back(val);
                if(k == ans.size()){
                    break;
                }
            }
            if(ans.size() == k) break;
        }
        return ans;
    }
};