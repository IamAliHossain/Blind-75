// This is from Blind75 premium problem
/*
    Problem Link : https://leetcode.com/problems/meeting-rooms-ii/description/
    Problem Name : 253. Meeting Rooms II
    Difficulty   : Medium
    Time Complexity : O() 
    Space Complexity : O()

    Date : 28-05-2025
    ================================================================================================

Given an array of meeting time intervals intervals where intervals[i] = [starti, endi], return the minimum number of conference rooms required.

 

Example 1:

Input: intervals = [[0,30],[5,10],[15,20]]
Output: 2
Example 2:

Input: intervals = [[7,10],[2,4]]
Output: 1
 

Constraints:

1 <= intervals.length <= 10^4
0 <= starti < endi <= 10^6

*/

#include<bits/stdc++.h>
using namespace std;

/*
    Solve this according to the end time of the range, which class will end before that will be vacant early
    so we need to know which classroom is free right now and to get this we will use a min_heap.

    sort function --> TC : O(n * logn)
    for loop -------> TC : O(n)
    finding mini ---->TC : O(log n)
    So TC : O(n * logn) + O(n) + O(log n) : O(n * logn)

    min_heap(priority  queue)takes space ----> O(n)
    Space Complexity : O(n)

*/

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<pair<int, int>> vp;
        for(auto u : intervals){
            vp.push_back({u[0], u[1]});
        }
        sort(vp.begin(), vp.end());
        int roomCnt = 1;
        priority_queue<int, vector<int>, greater<int> > mini ;
        mini.push(vp[0].second);
        int lastUsed = mini.top();
        for(int i=1; i<vp.size(); i++){
            int end = mini.top();
            int start = vp[i].first;
            if(end <= start ){
                mini.pop();
            }
            mini.push(vp[i].second);
        }
        roomCnt = mini.size();
        return roomCnt;
    }
};