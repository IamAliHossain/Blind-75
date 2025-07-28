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

Node* deleteKth(Node* head, int k){
    if(head == NULL) return NULL;
    if(k == 1){
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    Node* temp = head;
    Node* prev;
    int cnt = 0;
    while(temp){
        cnt++;
        if(cnt == k){
            prev->next = prev->next->next;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    delete prev->next;

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

    vector<int> arr = {9, 4, 5, 2, 8, 6};
    Node* head = convertArray2LL(arr);
    head = deleteKth(head, 9);
    printLL(head);
}