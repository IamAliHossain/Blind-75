#include<bits/stdc++.h>
using namespace std;

  // leaf node check kora lagbe na cause single node to true heap 
    // leaf node pabo from 0 to n/2 -1 till and seigula process korbo



// This is Max-heap every parent node wil be greater than child node
void heapifyForMinHeap(vector<int> &ar, int n, int i){
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(smallest < n && ar[smallest] > ar[left]){
        smallest = left;
    }
    if(smallest < n && ar[smallest] > ar[right]){
        smallest = right;
    }

    if(smallest != i){
        swap(ar[smallest], ar[i]);
        heapifyForMinHeap(ar, n, smallest);
    }
}



// This is Min-heap where every parent node wil be less than child node
void heapifyForMaxHeap(vector<int> &ar, int n, int i){
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(largest < n && ar[largest] > ar[left]){
        largest = left;
    }
    if(largest < n && ar[largest] > ar[right]){
        largest = right;
    }

    if(largest != i){
        swap(ar[largest], ar[i]);
        heapifyForMaxHeap(ar, n, largest);
    }
}

int  main(){
    vector<int> ar = {9, 8, 7, 1, -1};

    int n = ar.size();
  
    for(int i=n/2-1; i>=0; i--){
        heapifyForMinHeap(ar, n, i);
        heapifyForMaxHeap(ar, n, i);
    }
}