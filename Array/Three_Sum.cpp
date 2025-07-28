/*
    Problem Link: https://leetcode.com/problems/3sum/description/
    Problem Name: 3Sum
    Difficulty  : Medium
    Time Complexity : O(N * N * log N)
    Space Complexity: O(N)

*/

#include<bits/stdc++.h>
using namespace std;

/*
    Using Binary Search Technique 
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
    Using Two Pointer Technique 
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