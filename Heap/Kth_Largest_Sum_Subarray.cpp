/*

    This problem is form Coding Ninjas Platform, listed on 450 DSA cracker(From Heap)

    Problem Link: https://www.naukri.com/code360/problems/k-th-largest-sum-contiguous-subarray_920398?topList=love-babbar-dsa-sheet-problems&utm_source=website&utm_medium=affiliate&utm_campaign=450dsatracker&leftPanelTabValue=PROBLEM
    Problem Name: K-th Largest Sum Subarray
    Difficulty : Easy
    Date : 19-08-2025



    Problem statement
    Given an array of integers, find the Kth largest sum subarray For example, given the array 
    [1, -2, 3, -4, 5] and K = 2, the 2nd largest sum subarray would be [3, -4, 5], which has a 
    sum of 4.

    Please note that a subarray is the sequence of consecutive elements of the array.

    Detailed explanation ( Input/output format, Notes, Images )
    
    Sample Input 1 :
    2
    3 3
    3 -2 5
    2 2
    4 1

    Sample output 1 :
    3
    4

    Explanation of Sample output 1 :
    For the first test case, 
    Sum of [0, 0] = 3
    Sum of [0, 1] = 1
    Sum of [0, 2] = 6
    Sum of [1, 1] = -2
    Sum of [1, 2] = 3
    Sum of [2, 2] = 5
    All sum of subarrays are {6, 5, 3, 3, 1, -2} where the third largest element is 3.

    For the second test case, 
    Sum of [0, 0] = 4
    Sum of [0, 1] = 5
    Sum of [1, 1] = 1
    All sum of subarrays are {5, 4, 1} where the second largest element is 4.
    
    
    Sample Input 2 :
    2
    4 10
    5 4 -8 6
    3 1
    1 2 3

    Sample output 2 :
    -8
    6

    Explanation of Sample output 2 :
    For the first test case, among the sum of all the subarray, the tenth-largest sum will be -8.

    For the second test case, among the sum of all the subarray, the largest sum will be 6.


    Constraints:
    1 <= T <= 50
    1 <= N <= 100
    1 <= k <= (N * (N + 1)) / 2
    -1000 <= ARR[i] <= 1000

    T is the number of Test cases


*/


#include<bits/stdc++.h>
using namespace std;

/*

	TC : O(N * N * logN)
	SC : O(N * N)

*/

int getKthLargest(vector<int> &arr, int k)
{

	int n = arr.size();
	priority_queue<int> maxHeap;
	for(int i=0; i<n; i++){ //O(N)
		int sum = 0;
		for(int j=i; j<n; j++){ // O(N)
			sum += arr[j];
			maxHeap.push(sum); // logN
		}
	}
	
	for(int i=1; i<k; i++){
		maxHeap.pop(); // logN
	}
	int kthMax = maxHeap.top(); // logN

	return kthMax;
}