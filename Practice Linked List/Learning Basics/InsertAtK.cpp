#include"bits/stdc++.h"
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
void printLL(Node* head){
    while(head){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* insertAtK(Node* head, int pos, int val){
    if(head == NULL){
        if(pos == 1){
            return new Node(val);  
        }
        else return NULL;
    }
    if(pos == 1){
        Node* temp = new Node(val, head);
        return temp;
    }
    int cnt = 0;
    Node* temp = head;
    while(temp){
        cnt++;
        if(cnt == pos-1){
            Node* x = new Node(val);
            x->next = temp->next;
            temp->next = x;
            break;
        }
        temp = temp->next;
    }
    return head;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);

    vector<int> arr = {2, 5, 9, 6, 11};
    Node* head = convertArray2LL(arr);
    head = insertAtK(head, 7, 15);
    printLL(head);
}