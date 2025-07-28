#include<bits/stdc++.h>
using namespace std;

class Node {
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

Node* convertArrayToLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head ;
    for(int i=1; i<arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

int LengthOfLL(Node* head){
    Node* temp = head;
    int cnt = 0;
    while(temp){
        // cout << temp->data << ' ';
        temp = temp->next;
        cnt++;
    }
    return cnt;
}

bool SearchElementInLL(Node* head, int val){
    Node* temp = head;
    while(temp){
        if(temp->data == val) return true;
        temp = temp->next;
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    vector<int> arr = {5, 7, 3, 6, 8};

    // Traversing Linked List
    Node* head = convertArrayToLL(arr) ;
    Node* temp = head;
    while(temp){
        cout << temp->data << ' ';
        temp = temp->next; 
    }
    cout << endl;

    // Length Of Linked List
    int length = LengthOfLL(head);
    cout << length << endl;

    // search in Linked List
    cout << SearchElementInLL(head, 7) << endl;
}