/*
    Problem Link : https://leetcode.com/problems/longest-consecutive-sequence/description/
    Problem Name : 128. Longest Consecutive Sequence
    Difficulty   : Medium
    Time Complexity : 
    Space Complexity : 
    ================================================================================================

    Given an unsorted array of integers nums, return the length of the longest 
    consecutive elements sequence.

    You must write an algorithm that runs in O(n) time.

    Example 1:

    Input: nums = [100,4,200,1,3,2]
    Output: 4
    Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
    Example 2:

    Input: nums = [0,3,7,2,5,8,4,6,0,1]
    Output: 9
    Example 3:

    Input: nums = [1,0,1,2]
    Output: 3
    

    Constraints:

    0 <= nums.length <= 105
    -109 <= nums[i] <= 109
*/

// To solve this problem in O(N) we need to use set data structure

#include<bits/stdc++.h>
using namespace std;

//Most Optimal solution
/*
    using hash set follow up O(N) time complexity is achieved now
    TC : O(N) + O(N+N) --> O(3N) : O(N)
    SC : O(N)
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hash;
        int n = nums.size();
        for(int i=0; i<n; i++){ // O(N)
            hash.insert(nums[i]); // unsorted sorted hash set takes O(1) for per insert
        }
        
        int mxCnt = 1, left = 0, right = 1;
        for(auto x: hash){ // O(N+N)
            if(hash.find(x - 1) == hash.end()){
                int cnt = 1 ;
                while(hash.find(x + 1) != hash.end()){
                    cnt++;
                    x = x+1;
                }
                mxCnt = max(mxCnt, cnt);
            }
        }
        if(!n)return 0;
        return mxCnt;
    }
};

// solution 2
/*
    sliding window
    TC : O(n*logn)
    SC : O(N)

    but follow up korte bola hoyeche O(N) TC te

*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int, int> hash;
        int n = nums.size();
        for(int i=0; i<n; i++){
            hash[nums[i]]++; // sorted map takes O(logn) for per insert
        }
        vector<int> v;
        for(auto [x, y] : hash){
            v.push_back(x);
        }
        int mxCnt = 1, left = 0, right = 1;
        n = v.size();
        while(right<n){
            if(v[right-1] == v[right]-1){
                right++;
                mxCnt = max(mxCnt, right - left);
            }
            else{
                
                left = right;
                right++;
            }
        }
        if(!n)return 0;
        return mxCnt;
    }
};