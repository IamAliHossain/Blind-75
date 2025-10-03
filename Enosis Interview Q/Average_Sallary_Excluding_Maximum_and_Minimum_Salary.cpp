/*
    Problem Link : https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/
    Problem Name : Average Salary Excluding the Minimum and Maximum Salary
    Difficulty : Easy

    Date : 3rd October 2025
==============================================================================================

    You are given an array of unique integers salary where salary[i] is the salary of 
    the ith employee.

    Return the average salary of employees excluding the minimum and maximum salary. 
    Answers within 10-5 of the actual answer will be accepted.

    

    Example 1:

    Input: salary = [4000,3000,1000,2000]
    Output: 2500.00000
    Explanation: Minimum salary and maximum salary are 1000 and 4000 respectively.
    Average salary excluding minimum and maximum salary is (2000+3000) / 2 = 2500
    Example 2:

    Input: salary = [1000,2000,3000]
    Output: 2000.00000
    Explanation: Minimum salary and maximum salary are 1000 and 3000 respectively.
    Average salary excluding minimum and maximum salary is (2000) / 1 = 2000
    

    Constraints:

    3 <= salary.length <= 100
    1000 <= salary[i] <= 10^6
    All the integers of salary are unique.



*/


#include<bits/stdc++.h>
using namespace std;

/*

    TC : O(n*logn)
    SC: O(1)

*/

// Solution 1

class Solution {
public:
    double average(vector<int>& salary) {
        
        long long  sum = 0;
        int n = salary.size();
        sort(salary.begin(), salary.end());
        for(int i=0; i<salary.size(); i++){
            sum += salary[i];
            
        }

        sum -= salary[0];
        sum -= salary[n-1];
        double ans = (double) sum/(n-2);
        return ans;
    }
};


// Optimal Solution

/*

    TC : O(n)
    SC: O(1)

*/

class Solution {
public:
    double average(vector<int>& salary) {
        long long mx = 0, mn = 1e6;
        long long  sum = 0;
        for(int i=0; i<salary.size(); i++){
            sum += salary[i];
            if(mx < salary[i]){
                mx = salary[i];
            }
            if(mn > salary[i]){
                mn = salary[i];
            }
        }

        sum -= mx;
        sum -= mn;
        double ans = (double) sum/(salary.size()-2);
        return ans;
    }
};