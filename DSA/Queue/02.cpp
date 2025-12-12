#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

class Queue{
    public:
    Node* front;
    Node* rear;
    int size;

    Queue(){
        front = NULL;
        rear = NULL;
        size = 0;
    }

    void enqueue(int data){
        Node *node = new Node(data);
        if(rear == NULL){
            rear = node;
            front = node;
        }
        rear->next = node;
        rear = node;
        size++;
    }

    void dequeue(){
        if(front == NULL){
            cout<< "Queue Is empty";
            return;
        }else if(front == rear){
            Node* temp = front;
            front = NULL;
            rear = NULL;
            size = 0;
            delete temp;
        }
        Node* temp = front;
        front = front->next;
        size--;
        delete temp;
    }

    int getFront(){
        if(front == NULL){
            cout<<"queue is empty";
            return -1;
        }else{
            return front->data;
        }
    }
    int getSize(){
        return size;
    }

    void print(){
        if(front == NULL){
            cout<<"queue is empty";
            return;
        }
        Node* temp = front;
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }
};
int main() {
    std::ios_base::sync_with_stdio(false);
    Queue q1;
    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    q1.print();
    cout<<endl;
    q1.enqueue(10);
    q1.print();
    cout<<endl;
    q1.dequeue();
    q1.print();
    cout<<endl;
    q1.dequeue();
    q1.print();
    cout<<endl;
    cout<<q1.getFront()<<" "<<q1.getSize();
    
    return 0;
}