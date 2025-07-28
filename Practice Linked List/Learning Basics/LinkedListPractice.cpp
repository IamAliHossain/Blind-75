#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0),cout.tie(0);

    vector<int> v = {4, 3, 5};
    Node* y = new Node(v[0]);
    cout << y->data << endl;
}