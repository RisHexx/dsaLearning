#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Node{
    public:
    Node* prev;
    int data;
    Node* next;

    Node(int data){
        prev = NULL;
        this->data = data;
        next = NULL;
    }
};

void insertAtHead(Node*& head , int data){
    if(head == NULL){
        Node* node = new Node(data);
        head = node;
        return;
    }else{
        Node* node = new Node(data);
        head->prev = node;
        node->next = head;
        head = node;
    }
}


void insertAtTail(Node*& head , int data){
    if(head == NULL){
        Node* node = new Node(data);
        head = node;
        return;
    }else{
         Node* node = new Node(data);
         Node* temp = head;
         while(temp->next != NULL){
            temp = temp->next;
         }
         temp->next = node;
         node->prev = temp;
    }
}

void insertAtPos(Node*& head , int pos , int data){
    if(head == NULL){
        Node* node = new Node(data);
        head = node;
        return;
    }else if(pos == 1){
        Node* node = new Node(data);
        node->next = head;
        head->prev = node;
    }else{
        Node* node = new Node(data);
        Node* temp = head;
        for(int i = 1 ; i < pos-1 ; i++){
            temp = temp->next;
        }
        node->prev = temp;
        node->next = temp->next;
        temp->next->prev = node;
        temp->next = node;
    }
}

void deleteAtHead(Node*&head){
    if(head == NULL){
        cout<<"NOthing To delete";
        return;
    }else if(head->next == NULL){
        delete head;
        head = NULL;
        return;
    }else{
        Node* temp = head;
        head = head->next;
        head->prev = NULL;
        delete temp;
    }
}

void deleteAtTail(Node*& head){
    if(head == NULL){
        cout<<"NOthing To delete";
        return;
    }else if(head->next == NULL){
        delete head;
        head = NULL;
        return;
    }else{
        Node* temp = head;
        Node* prev = NULL;
        while(temp->next != NULL){
            temp = temp->next;
        }
        prev = temp->prev;
        prev->next = NULL;
        delete temp;
    }
}

void deleteAtPos(Node*& head , int pos){
    if(head == NULL){
        cout<<"NOthing To delete";
        return;
    }else if(head->next == NULL){
        delete head;
        head = NULL;
        return;
    }else if(pos == 1){
        Node* temp = head;
        head = head->next;
        head->prev = NULL;
        delete temp;
    }
    else{
        Node* temp = head;
        Node* toDelete = head;
        for(int i = 1 ; i < pos - 1 ; i++){
            temp = temp->next;
        }
        toDelete = temp->next;
        temp->next = toDelete->next;
        if (toDelete->next) {
        toDelete->next->prev = temp;
        }
        delete toDelete;
    }
}

void printLL(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

void printRev(Node* head){
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->prev;
    }
}


int main() {
    std::ios_base::sync_with_stdio(false);
    Node* head = NULL;
    insertAtHead(head,10);
    insertAtHead(head,30);
    insertAtHead(head,20);
    insertAtTail(head,50);
    insertAtTail(head,60);
    printLL(head);
    cout<<endl;
    insertAtPos(head,3,24);
    printLL(head);
    cout<<endl;
    // printRev(head);
    // deleteAtHead(head);
    // deleteAtTail(head);
    deleteAtPos(head,6);
    printLL(head);
    
    return 0;
}