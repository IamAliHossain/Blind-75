/*
    This problem is form Coding Ninjas Platform, listed on 450 DSA cracker

    Problem Link: https://www.naukri.com/code360/problems/merge-two-binary-max-heaps_1170049?topList=love-babbar-dsa-sheet-problems&utm_source=website&utm_medium=affiliate&utm_campaign=450dsatracker&count=25&page=4&search=&sort_entity=order&sort_order=ASC&leftPanelTabValue=PROBLEM
    Problem Name: Merge Two Binary Max Heaps

    Date : 19-08-2025


    -------------------------------------------------------------------------------------------------------------------

    Problem statement

    You are given two integer arrays ‘ARR1’ and ‘ARR2’ of size ‘N’ and ‘M’ respectively, 
    Both ‘ARR1’ and ‘ARR2’ represent a Max-Heap. Your task is to merge the two arrays firstly 
    keep all the elements of the ‘ARR1’ (without changing order) than elements of array ‘ARR2’ 
    (without changing order), and then find the Max-Heap obtained by merging arrays. Print an 
    array of sizes ‘N + M’, representing the Max-Heap obtained after merging.

    A binary Max-Heap is a complete binary tree in which the value in each internal node is 
    greater than or equal to the values in the children of that node.

    Max-Heaps are usually represented by an array, as follows :

    1. Each element in the array represents a node of the heap.

    2. Element at index 0 represent the root of the heap.

    3. If a node is represented by elements at index ‘i’ then its left and right child is 
    represented by elements at indices ‘2*i + 1’ and ‘ 2*i + 2’  respectively..

    Example :
    Consider ‘ARR1’ = [10, 5, 6, 2] and ‘ARR2’ = [12, 7, 9]. 

    The max-heap obtained by merging can be represented by array [12, 10, 9, 2, 5, 7, 6]
    Detailed explanation ( Input/output format, Notes, Images )
    Constraints :
    1 <= ‘T’ <= 50
    1 <= ‘N’ <= 10^4
    1 <= ‘M’ <= 10^4
    1 <= ‘ARR1[i]’, ‘ARR2[i]’ <= 10^9
    Time limit: 1 sec

    Sample Input 1 :
    2
    1 1
    2 
    2
    4 3
    10 5 6 2
    12 7 9

    Sample Output 1 :
    2 2
    12 10 9 2 5 7 6
    Explanation For Sample Input 1:
    Test case 1:
    In this case,  Both heaps have only one element i.e 2,  thus after merging, the new array 
    obtained will be [2, 2] which also represents a max-heap of size 2. 

    Test case 2:
    See the problem statement for an explanation.
    Sample Input 2:
    2
    6 7
    10 5 6 4 5 6
    9 7 9 4 3 8 3
    2 3
    3 1
    10 6 8
    Sample Output 2:
    10 9 9 7 5 8 6 5 4 4 3 6 3
    10 8 3 6 1

*/


#include <bits/stdc++.h> 

// building max-heap

void heapify(vector<int> &a, int n, int i){
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && a[largest] < a[left]){
        largest = left;
    }
    if(right < n && a[largest] < a[right]){
        largest = right;
    }

    if(largest != i){
        swap(a[largest], a[i]);
        heapify(a, n, largest);
    }

}


vector<int> mergeHeap(int n, int m, vector<int> &arr1, vector<int> &arr2) {
    // Write your code here
    vector<int> maxHeap;
    for(int i=0; i<n; i++)maxHeap.push_back(arr1[i]);
    for(int i=0; i<m; i++)maxHeap.push_back(arr2[i]);

    int ln = n + m;
    for(int i=ln/2-1; i>=0; i--){
        heapify(maxHeap, ln, i);
    }

    return maxHeap;
}