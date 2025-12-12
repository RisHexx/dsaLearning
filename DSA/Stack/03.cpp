#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Stack using LL


class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

class Stack{
    public:
    Node* head;
    int size;

    Stack(){
        head = NULL;
        size = 0;
    }

    int getSize(){
        return size;
    }

    bool isEmpty(){
        if(size == 0) return true;
        return false;
    }

    void push(int data){
        Node *node = new Node(data);
        if(head == NULL){
            head = node;
            size++;
            return;
        }
        node->next = head;
        head = node;
        size++;
    }

    int pop(){
        if(head == NULL){
            cout<<"Stack is Empty";
            return -1;
        }
        Node* temp = head;
        head = head->next;
        size--;
        int data = temp->data;
        delete temp;
        return data;
    }

    int top(){
        if(head == NULL){
            cout<<"Stack is Empty";
            return -1;
        }
        return head->data;
    }

    void print(){
         if(head == NULL){
            cout<<"Stack is Empty";
            return;
        }else{
            Node* temp = head;
            while(temp != NULL){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
        }
    }


};

int main() {
    std::ios_base::sync_with_stdio(false);
    Stack s1;
    cout<<s1.getSize()<<endl;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    cout<<s1.getSize()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.top()<<endl;
    cout<<s1.getSize()<<endl;
    cout<<s1.top()<<endl;
    s1.print();
    
    return 0;
}