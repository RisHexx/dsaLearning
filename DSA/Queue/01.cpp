#include <bits/stdc++.h>
using namespace std;
#define ll long long


// circular queue
class Queue{
    public:
    int* arr;
    int rear;
    int front;
    int size;

    Queue(){
        arr = new int[5];
        rear= -1;
        front= -1;
        size = 0;
    }

    void enqueue(int data){
        // if((front == 0 && rear == 4) || (front - rear) == 1){ when we dont have size
        if(size == 5){
            cout<<"Queue is full";
            return;
        }
        else if(rear == -1){
            arr[++rear] = data;
            front++;
        }else{
            rear = (rear + 1) % 5 ;
            arr[rear] = data;
        }
        size++;
    }

    int dequeue(){
        if(size == 0){
            cout<<"Queue is empty";
            return -1;
        }else if(front == rear){
            int data = arr[front];
            rear = -1;
            front= -1;
            size = 0 ;
            return data;
        }else{
            size--;
            front = (front + 1) % 5;
            return arr[front];
        }
    }

    int getFront(){
        if(rear== -1){
            cout<<"Queue is empty";
            return -1;
        }
        return arr[front];
    }

    void print(){
        if(rear== -1){
            cout<<"Queue is empty";
            return;
        }
        int i = front;
        while(i != rear){
            cout<<arr[i] << " ";
            i = (i + 1) % 5;
        }
        cout << arr[rear];
    }
    int getSize(){
        return size;
    }

};

int main() {
    std::ios_base::sync_with_stdio(false);
    Queue q1;
    q1.print();
    cout<<endl;
    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    q1.enqueue(40);
    q1.enqueue(50);
    q1.print();
    cout<<endl;
    q1.dequeue();
    q1.enqueue(60);
    q1.print();
    cout<<endl;
    cout<<q1.getFront();
    cout<<endl;
    cout<<q1.getSize();
    cout<<endl;
    q1.enqueue(50);
    
    return 0;
}