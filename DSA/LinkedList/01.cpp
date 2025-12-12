#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Singly LinkedList

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

// ref of pointer head beacuse we modifying head here
void insertAtHead(Node*&head,int data){
    if(head == NULL){
        Node* node = new Node(data);
        head = node;
    }else{
        Node* node = new Node(data);
        node->next = head;
        head = node;
    }
}

void insertAtTail(Node*&head , int data){
    if(head == NULL){
        Node* node = new Node(data);
        head = node;
    }else{
    Node* node = new Node(data);
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
        }
    temp->next = node;
    }
}

void insertAtPosition(Node*& head , int pos , int data){
    if(pos == 1){
        Node* node = new Node(data);
        node->next = head;
        head = node;
        return;
    }else{
        Node* temp = head;
        Node* node = new Node(data);
        for(int i = 1 ; i < pos-1 ; i++){
            temp = temp->next;
        }
        node->next = temp->next;
        temp->next = node;
    }
}

void deleteAtHead(Node*&head){
    if(head == NULL){
        cout<<"Nothing to Delete";
        return;
    }else{
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void deleteAtTail(Node*& head){
    if(head == NULL){
        cout<<"Nothing to Delete";
        return;
    }else if(head->next == NULL){
        delete head;
        head = NULL;
        return;
    }
    else{
        Node*temp = head;
        Node*prev = NULL;
        while(temp->next != NULL){
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        delete temp;
    }
}

void deleteAtPos(Node*& head , int pos){
    if(head == NULL){
        cout<<"Nothing to Delete";
        return;
    }else if(pos == 1){
        Node*temp = head;
        head = head->next;
        delete temp;
        return;
    }else{
        Node* temp = head;
        Node* newtemp = NULL;
        for(int i = 1 ; i < pos-1 ; i++){
            temp = temp->next;
        }
        newtemp = temp->next;
        temp->next = temp->next->next;
        delete newtemp;
    }
}

int searchLL(Node* head, int data){
    int pos = 1;
    Node* temp = head;
    while(temp != NULL){
        if(temp->data == data){
            return pos;
        }
        pos++;
        temp = temp->next;
    }
    return -1;
}

void printLL(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

void reversePrint(Node*head){
    if(head == NULL) return;
    reversePrint(head->next);
    cout<<head->data<<" ";
}


void reverseLL(Node*&head){
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL; 
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    Node* head = NULL;
    insertAtHead(head,10);
    insertAtHead(head,40);
    insertAtHead(head,30);
    insertAtTail(head,9);
    insertAtTail(head,8);
    insertAtPosition(head,3,25);
    printLL(head);
    cout<<endl;
    // cout<<searchLL(head , 10);
    deleteAtHead(head);
    deleteAtTail(head);
    // deleteAtPos(head,3);
    printLL(head);
    cout<<endl;
    // reversePrint(head);
    reverseLL(head);
    printLL(head);
    
    return 0;
}