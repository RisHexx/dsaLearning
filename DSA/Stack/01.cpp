#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Stack{
    public:
    int capacity;
    int *arr;
    int tos;

    Stack(){
        capacity = 4;
        arr = new int[capacity];
        tos = -1;
    }

    void push(int data){
        if(tos == capacity - 1){
            int* newArr = new int[capacity * 2];
            for(int i = 0 ; i < capacity ; i++){
                newArr[i] = arr[i];
            }
            delete [] arr;
            arr = newArr;
            capacity *= 2;
        }
        arr[++tos] = data;
    }

    int pop(){
        if(tos == -1){
            cout<<"Nothing to Pop";
            return -1;
        }
        return arr[tos--];
    }

    int top(){
        if(tos == -1){
            cout<<"Stack Is Empty";
            return -1;
        }
        return  arr[tos];
    }

    bool isEmpty(){
        if(tos == -1){
            return true;
        }else{
            return false;
        }
    }

    void printStack(){
        if(tos == -1){
            cout<<"Stack Is Empty";
            return;
        }
        for(int i = tos ; i >= 0 ; i--){
            cout<<arr[i]<<" ";
        }
    }
};
int main() {
    std::ios_base::sync_with_stdio(false);
    Stack s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(30);
    cout<<s1.capacity<<endl;
    s1.push(30);
    cout<<s1.capacity<<endl;
    s1.pop();
    s1.push(40);
    s1.printStack();
    cout<<endl;
    cout<<s1.isEmpty();
    
    
    
    return 0;
}