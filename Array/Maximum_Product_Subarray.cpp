/*
    Problem Link: https://leetcode.com/problems/maximum-product-ubarray/description/
    Problem Name: Maximum Product Subarray
    Difficulty  : Medium
    Time Complexity : 
    Space Complexity: 

*/

#include<bits/stdc++.h>
using namespace std;
//Updated Version of Kadanas Algorithm
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int mxResProd = nums[0];
        vector<int> dpMx(n), dpMn(n);
        dpMx[0] = nums[0];
        for(int i=1; i<n; i++){
            if(nums[i] == 0){
                dpMx[i] = 1;
                dpMn[i] = 1;
                mxResProd = max({mxResProd, dpMx[i-1], dpMn[i-1]});
                continue;
            }
            dpMx[i] = max({dpMx[i-1] * nums[i], dpMn[i-1] * nums[i], nums[i]});
            dpMn[i] = min({dpMx[i-1] * nums[i], dpMn[i-1] * nums[i], nums[i]});
            mxResProd = max({mxResProd, dpMx[i], dpMn[i]});
        }
        return mxResProd;
    }
};

/*
    Time Complexity : O(n) and Space Complexity O(1)
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
    // vector<int> nums = {1,0,-1,2,3,-5,-2};
    // vector<int> nums = {-3,0,1,-2};
    // vector<int> nums = {-2,0,-1};
    int n = nums.size();
    int pref = 1, suff = 1, maxi = INT_MIN;
    for(int i=0; i<n; i++){
        if(pref == 0){
            pref = 1;
        }
        if(suff == 0){
            suff = 1;
        }
        pref = pref * nums[i];
        suff = suff * nums[n-i-1];
        maxi = max(maxi, max(pref, suff));
    }
    cout << maxi << endl;
    }
};