/*
    Problem Link: https://leetcode.com/problems/3sum/description/
    Problem Name: 3Sum
    Difficulty  : Medium


    Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that 
    i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

    Notice that the solution set must not contain duplicate triplets.

    

    Example 1:

    Input: nums = [-1,0,1,2,-1,-4]
    Output: [[-1,-1,2],[-1,0,1]]
    Explanation: 
    nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
    nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
    nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
    The distinct triplets are [-1,0,1] and [-1,-1,2].
    Notice that the order of the output and the order of the triplets does not matter.
    Example 2:

    Input: nums = [0,1,1]
    Output: []
    Explanation: The only possible triplet does not sum up to 0.
    Example 3:

    Input: nums = [0,0,0]
    Output: [[0,0,0]]
    Explanation: The only possible triplet sums up to 0.
    

    Constraints:

    3 <= nums.length <= 3000
    -105 <= nums[i] <= 10^5
        

*/

#include<bits/stdc++.h>
using namespace std;

/*
    Using Binary Search Technique 
    Time Complexity : O(N * N * log N)
    Space Complexity: O(N)
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> ind;
        for(int i=0; i<n; i++){
            ind.push_back({nums[i], i});
        }
        sort(ind.begin(), ind.end());

        set<vector<int>> used;
        vector<vector<int>> ans;
        for(int i=0; i<n-2; i++){
            for(int j=i+1; j<n-1; j++){
                if (i > 0 && ind[i].first == ind[i - 1].first) continue;
                int l = j+1, hi = n-1;
                int sum = ind[i].first + ind[j].first;
                int need = 0 - sum ;
                if (j > i + 1 && ind[j].first == ind[j - 1].first) continue;
                while(l <= hi){
                    int mid = l + (hi - l) / 2;
                    if(ind[mid].first == need){
                        vector<int> sum3 = {ind[i].first, ind[j].first, ind[mid].first};
                        sort(sum3.begin(), sum3.end());
                        if (!used.count(sum3)) {
                            ans.push_back(sum3);
                            used.insert(sum3); 
                        }
                        break;
                    }
                    else if (ind[mid].first < need) {
                        l = mid + 1;
                    } else {
                        hi = mid - 1;
                    }
                }
            }
        }
        return ans;
    }
};


/*
    Using Two Pointer Technique 1
*/


/*
    TC : O(n*logn) for sorting function + O(n * n) 

    Therefore :
    Time Complexity : O(n^2)
    Space Complexity : O(n^2)

*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for(int i=0; i<n; i++){
            // skiping duplicates
            if(i != 0 and nums[i] == nums[i-1])continue;
            int j = i+1;
            int k = n-1;
            // using Two Pointer 
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum < 0){
                    j++;
                }
                else if(sum > 0){
                    k--;
                }
                else{
                    vector<int> res ={nums[i], nums[j], nums[k]};
                    ans.push_back(res);
                    j++;
                    k--;
                    // skip duplicates
                    while(j<k && nums[j] == nums[j-1])j++;
                    while(j<k && nums[k] == nums[k+1])k--;
                }
            }
        }
        return ans;
    }
};

// using two pointer technique 2
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> ind;
        for(int i=0; i<n; i++){
            ind.push_back({nums[i], i});
        }
        sort(ind.begin(), ind.end());

        set<vector<int>> used;
        vector<vector<int>> ans;
        for(int i=0; i<n-2; i++){
            //skip duplicates
            if (i > 0 && ind[i].first == ind[i - 1].first) continue;
            for(int j=i+1; j<n-1; j++){
                
                int l = j+1, hi = n-1;
                int sum = ind[i].first + ind[j].first;
                int need = 0 - sum ;
                //skip duplicates
                if (j > i + 1 && ind[j].first == ind[j - 1].first) continue;
                while(l <= hi){
                    // Need To write code
                }
            }
        }
        return ans;
    }
};