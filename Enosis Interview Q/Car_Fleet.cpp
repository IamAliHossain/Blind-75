/*
    Problem Link : https://leetcode.com/problems/car-fleet/description/
    Problem Name : Car Fleeet
    Difficulty : Medium

    Date : 3nd October 2025


========================================================================================
    There are n cars at given miles away from the starting mile 0, traveling to 
    reach the mile target.

    You are given two integer arrays position and speed, both of length n, where 
    position[i] is the starting mile of the ith car and speed[i] is the speed of 
    the ith car in miles per hour.

    A car cannot pass another car, but it can catch up and then travel next to it 
    at the speed of the slower car.

    A car fleet is a single car or a group of cars driving next to each other. The 
    speed of the car fleet is the minimum speed of any car in the fleet.

    If a car catches up to a car fleet at the mile target, it will still be considered 
    as part of the car fleet.

    Return the number of car fleets that will arrive at the destination.

    

    Example 1:

    Input: target = 12, position = [10,8,0,5,3], speed = [2,4,1,1,3]

    Output: 3

    Explanation:

    The cars starting at 10 (speed 2) and 8 (speed 4) become a fleet, meeting each 
    other at 12. The fleet forms at target.
    The car starting at 0 (speed 1) does not catch up to any other car, so it is a 
    fleet by itself.
    The cars starting at 5 (speed 1) and 3 (speed 3) become a fleet, meeting each 
    other at 6. The fleet moves at speed 1 until it reaches target.
    Example 2:

    Input: target = 10, position = [3], speed = [3]

    Output: 1

    Explanation:

    There is only one car, hence there is only one fleet.
    Example 3:

    Input: target = 100, position = [0,2,4], speed = [4,2,1]

    Output: 1

    Explanation:

    The cars starting at 0 (speed 4) and 2 (speed 2) become a fleet, meeting each other at 4. 
    The car starting at 4 (speed 1) travels to 5.
    Then, the fleet at 4 (speed 2) and the car at position 5 (speed 1) become one fleet, 
    meeting each other at 6. The fleet moves at speed 1 until it reaches target.
    

    Constraints:

    n == position.length == speed.length
    1 <= n <= 10^5
    0 < target <= 10^6
    0 <= position[i] < target
    All the values of position are unique.
    0 < speed[i] <= 10^6

*/


#include<bits/stdc++.h>
using namespace std;

/*
    TC : O(N*logN)
    SC : O(N)

    ধরা যাক:

    target = 12
    position = [10, 8, 0, 5, 3]
    speed    = [2, 4, 1, 1, 3]


    গাড়ি অনুযায়ী time হবে:

    pos 10 → (12-10)/2 = 1
    pos 8 → (12-8)/4 = 1
    pos 0 → (12-0)/1 = 12
    pos 5 → (12-5)/1 = 7
    pos 3 → (12-3)/3 = 3

    এখন descending order position এ traverse করলে:

    pos 10 → time 1 → নতুন fleet (fleet=1, curr=1)
    pos 8 → time 1 → curr=1 এর সমান → একই fleet
    pos 5 → time 7 → নতুন fleet (fleet=2, curr=7)
    pos 3 → time 3 → curr=7 এর চেয়ে ছোট → এইটা pos5 এর fleet এ মিশে যাবে
    pos 0 → time 12 → নতুন fleet (fleet=3, curr=12)

    শেষে উত্তর = 3 fleets 
*/

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        map<int, double> mp;
        
        int n = speed.size();
        // এখানে negative position ব্যবহার করা হয়েছে, যাতে map এ iterate করলে 
        // position descending order এ পাওয়া যায় (মানে target এর কাছের গাড়ি আগে আসবে)।
        for(int i=0; i<n; i++){
            double time = (double)(target - position[i])/speed[i];
            mp[-position[i]] = time;
        }
        int fleet = 0;
        double curr_time = 0;
        for(auto [pos, time] : mp){
            if(time > curr_time){
                curr_time = time;
                fleet++;
            }
        }
        return fleet;
    }
};