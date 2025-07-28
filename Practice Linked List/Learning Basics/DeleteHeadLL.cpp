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

Node* ConvertArray2LL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1; i<arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void TraverseLL(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << ' ';
        temp = temp->next;
    }
    cout << endl;
}

Node* deleteHead(Node* head){
    if(head == NULL) return head;
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);

    vector<int> arr = {12, 4, 6, 3};
    Node* head = ConvertArray2LL(arr);
    head = deleteHead(head);
    TraverseLL(head);
}