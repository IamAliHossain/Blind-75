/*
    This problem is not listed in Blind75    

Problem Link : https://leetcode.com/problems/koko-eating-bananas/description/
    Problem Naem : 875. Koko Eating Bananas
    Difficulty   : Medium



    Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. 
    The guards have gone and will come back in h hours.

    Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile 
    of bananas and eats k bananas from that pile. If the pile has less than k bananas, she 
    eats all of them instead and will not eat any more bananas during this hour.

    Koko likes to eat slowly but still wants to finish eating all the bananas before the 
    guards return.

    Return the minimum integer k such that she can eat all the bananas within h hours.

    

    Example 1:

    Input: piles = [3,6,7,11], h = 8
    Output: 4
    Example 2:

    Input: piles = [30,11,23,4,20], h = 5
    Output: 30
    Example 3:

    Input: piles = [30,11,23,4,20], h = 6
    Output: 23
    

    Constraints:

    1 <= piles.length <= 10^4
    piles.length <= h <= 10^9
    1 <= piles[i] <= 10^9


*/

#include<bits/stdc++.h>
using namespace std;

/*

 This is my own approach(Binary Search) & solution code

    N = piles.size()
 
    TC : O(N * logN)
    SC : (1)

*/


class Solution {
public:
    bool check(int k, int h, vector<int> &piles){
        long long hours = 0;
        for(int i=0; i<piles.size(); i++){
            hours += (long long) (piles[i] / k);
            if(piles[i] % k)hours++;
        }
        return hours <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {

        int lo = 1 ;
        int hi = *max_element(piles.begin(), piles.end());
        int ans = 1;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if(check(mid, h, piles)){
                ans = mid ;
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }
        return ans;
    }
};