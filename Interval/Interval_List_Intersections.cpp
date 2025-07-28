// This is not from Blind75 list
/*
    Problem Link : https://leetcode.com/problems/interval-list-intersections/description/
    Problem Name : 986. Interval List Intersections
    Difficulty   : Medium
    Time Complexity : O(N) = O(N);
    Space Complexity : O(N)

    ================================================================================================

*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        if(firstList.empty())return firstList;
        if(secondList.empty())return secondList;
        int i =0, j = 0;
        vector<vector<int>> intersection;
        while(i < firstList.size() && j < secondList.size()){
            int start = max(firstList[i][0], secondList[j][0]);
            int end = min(firstList[i][1], secondList[j][1]);
            if(start <= end){
                intersection.push_back({start, end});
            }
            if(firstList[i][1] < secondList[j][1]){
                i++;
            }
            else{
                j++;
            }
        }
        return intersection;
    }
};