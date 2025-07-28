#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }
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
    Node* temp = head;
    while(temp){
        cout << temp->data << ' ';
        temp = temp->next;
    }
    cout << endl;
}

Node* insertHead(Node* head, int val){
    return new Node(val, head);
}
Node* insertTail(Node* head, int val){
    if(head == NULL){
        return new Node(val);
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new Node(val);
    return head;
}

Node* insertAtK(Node* head, int val, int k){
    if(head == NULL){
        if(k == 1){ 
            return new Node(val);
        }
        else{
            return NULL;
        }
    }
    if(k == 1){
        return new Node(val, head);
    }
    int cnt = 0;
    Node* temp = head;
    while(temp){
        cnt++;
        if(cnt == k - 1){
            Node* newNode = new Node(val);
            newNode->next = temp->next;
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }
    return head;
}

Node* deleteHead(Node* head){
    Node* temp = head->next;
    delete head;
    return temp;
}

Node* deleteTail(Node* head){
    if(head == NULL or head->next == NULL ){
        return NULL;
    }
    Node* temp = head;
    while(temp->next->next ){
        temp = temp->next;
    }
    delete temp->next->next;
    temp->next = NULL;
    return head;
}
Node* deleteAtK(Node* head, int k){
    if(head == NULL ){
        return NULL;
    }
    if(k == 1){
        Node* temp = head;
        head = temp->next;
        delete temp;
        return head;
    }
    Node* temp = head;
    Node* prev;
    int cnt = 0;
    while(temp){
        if(cnt == k-1){
            prev->next = prev->next->next;
            break;
        }
        prev = temp ;
        temp = temp->next;
        cnt++;
    }
    delete prev->next;
    return head;

}
int main(){
    vector<int> arr={4, 2, 5, 1, 7};
    Node* head = convertArray2LL(arr);
    head = deleteAtK(head, 1);
    printLL(head);
}