/*
    Problem Link: https://leetcode.com/problems/sum-of-two-integers/description/
    Problem Name: Sum of Two Integers
    Difficulty  : Medium
    Time Complexity : O(32)
    Space Complexity: O(1)

*/
/*
====================================================================================================

Given two integers a and b, return the sum of the two integers without using the operators + and -.

Example 1:

Input: a = 1, b = 2
Output: 3
Example 2:

Input: a = 2, b = 3
Output: 5
 

Constraints:

-1000 <= a, b <= 1000

==================================================================================================

*/

#include<bits/stdc++.h>
using namespace std;

/*
    Using Bit Manipulation Technique 
*/

class Solution {
public:
    int getSum(int a, int b) {
        int sum ;
        int carry;
        while(carry){
            sum = a ^ b;
            carry = (a & b) << 1;
            a = sum;
            b = carry ;
        }
        return sum ;
    }
};
