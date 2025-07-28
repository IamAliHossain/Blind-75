/*
    Problem Link: https://leetcode.com/problems/container-with-most-water/submissions/1618030238/
    Problem Name: Container With Most Water
    Difficulty  : Medium
    Time Complexity : O(N)
    Space Complexity: O(1)

*/

#include<bits/stdc++.h>
using namespace std;

/*
    Using Two Pointer Technique 
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n - 1;
        int maxWater = 0;
        int area = height[0];
        while(l <= r){
            if(height[l] <= height[r]){
                area = height[l] * (r - l);
                maxWater = max(maxWater, area);
                l++;
            }
            else{
                area = height[r] * (r-l);
                maxWater = max(maxWater, area);
                r--;
            }
        }
        return maxWater;
    }
};