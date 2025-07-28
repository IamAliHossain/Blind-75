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

Node* convertArray2LL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1; i<arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

Node* deleteElementLL(Node* head, int element){
    if(head == NULL) return head;
    Node* temp = head;
    if(element == head->data){
        head = head->next;
        delete temp;
        return head;
    }
    Node* prev = nullptr;
    temp = head;
    while(temp != NULL){
        if(temp->data == element){
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

void printLL(Node* head){

    while(head){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);

    vector<int> arr = {12, 9, 10, 8, 4};
    Node* head = convertArray2LL(arr);
    head = deleteElementLL(head, 4);
    printLL(head);
}