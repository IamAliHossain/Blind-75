#include<bits/stdc++.h>
using namespace std;

  // leaf node check kora lagbe na cause single node to true heap 
    // leaf node pabo from 0 to n/2 -1 till and seigula process korbo



// This is Min-heap every parent node have to be less than child node
void heapifyForMinHeap(vector<int> &ar, int n, int i){
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && ar[smallest] > ar[left]){
        smallest = left;
    }
    if(right < n && ar[smallest] > ar[right]){
        smallest = right;
    }

    if(smallest != i){
        swap(ar[smallest], ar[i]);
        heapifyForMinHeap(ar, n, smallest);
    }
}



// This is Max-heap where every parent node have to be greater than child node
void heapifyForMaxHeap(vector<int> &ar, int n, int i){
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && ar[largest] < ar[left]){
        largest = left;
    }
    if(right < n && ar[largest] < ar[right]){
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
  
    for(int i=(n/2)-1; i>=0; i--){
        heapifyForMinHeap(ar, n, i);
        heapifyForMaxHeap(ar, n, i);
    }
}