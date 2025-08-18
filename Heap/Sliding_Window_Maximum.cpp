/*
    This is not from Blind-75 series. This is taken from "450 DSA Cracker"
    Link : https://450dsa.com/heap


    Problem Link from Leetcode : https://leetcode.com/problems/sliding-window-maximum/description/
    Problem Name : 239. Sliding Window Maximum
    Difficulty : Hard

    Date : 17-08-2025


-----------------------------------------------------------------------------------------------------

    You are given an array of integers nums, there is a sliding window of size k which is moving from 
    the very left of the array to the very right. You can only see the k numbers in the window. 
    Each time the sliding window moves right by one position.

    Return the max sliding window.

    

    Example 1:

    Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
    Output: [3,3,5,5,6,7]
    Explanation: 
    Window position                Max
    ---------------               -----
    [1  3  -1] -3  5  3  6  7      3
    1 [3  -1  -3] 5  3  6  7       3
    1  3 [-1  -3  5] 3  6  7       5
    1  3  -1 [-3  5  3] 6  7       5
    1  3  -1  -3 [5  3  6] 7       6
    1  3  -1  -3  5 [3  6  7]      7
    
    
    
    Example 2:

    Input: nums = [1], k = 1
    Output: [1]
    

    Constraints:

    1 <= nums.length <= 10^5
    -10^4 <= nums[i] <= 10^4
    1 <= k <= nums.length
    
*/


/*
    Approach 💡
    Iterate over the array with a right pointer.

    For each element:

    Remove all smaller elements from the back of the deque (they can never be maximum again).

    Add the current index to the deque.

    Compute the left boundary: left = right - k + 1.

    If the maximum (front of deque) is out of the window, remove it.

    Once the first full window is formed (right >= k - 1), add nums[deque[0]] to the result.



    TC : O(N)
    SC : O(K)

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        vector<int> ans;
       
        for(int i=0; i<n; i++){
            
            // remove out of window indices from the front & move forward
            if(dq.size() && dq.front() <= i - k){
                dq.pop_front();
            }
            while(dq.size() && nums[dq.back()] < nums[i]){
                dq.pop_back();
            }

            dq.push_back(i);
            if(i >= k - 1){
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};