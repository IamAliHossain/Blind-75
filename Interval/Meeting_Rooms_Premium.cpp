// This is from Blind75 premium problem
/*
    Problem Link : https://leetcode.com/problems/meeting-rooms/description/
    Problem Name : 252. Meeting Rooms
    Difficulty   : Easy
    Time Complexity : O(N) 
    Space Complexity : O(N)

    ================================================================================================

    Given an array of meeting time intervals where intervals[i] = [starti, endi], determine if a person could attend all meetings.

 

Example 1:

Input: intervals = [[0,30],[5,10],[15,20]]
Output: false
Example 2:

Input: intervals = [[7,10],[2,4]]
Output: true
 

Constraints:

0 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti < endi <= 106

*/
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        vector<pair<int, int>> vp;
        for(auto it : intervals){
            vp.push_back({it[0], it[1]});
        }
        sort(vp.begin(), vp.end());
        int j = 0 ;
        int missCnt = 0;
        for(int i=1; i<intervals.size(); i++){
            int end = vp[j].second ;
            int start = vp[i].first;
            if(end <= start) j = i;
            else{
                missCnt++;
            }
        }
        if(missCnt == 0) return true;
        
        return false;
    }
};

