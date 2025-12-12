#include <bits/stdc++.h>
using namespace std;
#define ll long long

template <typename T>
class Stack{
    public:
    int capacity;
    T *arr;
    int tos;

    Stack(){
        capacity = 4;
        arr = new T[capacity];
        tos = -1;
    }

    void push(T data){
        if(tos == capacity - 1){
            T* newArr = new T[capacity * 2];
            for(int i = 0 ; i < capacity ; i++){
                newArr[i] = arr[i];
            }
            delete [] arr;
            arr = newArr;
            capacity *= 2;
        }
        arr[++tos] = data;
    }

    T pop(){
        if(tos == -1){
            cout<<"Nothing to Pop";
            return 0;
        }
            return arr[tos--];
    }

    T top(){
        if(tos == -1){
            cout<<"Stack Is Empty";
            return 0;
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
    Stack<string> s1;
    s1.push("rishabh");
    s1.push("kanojiya");
    cout<<s1.capacity<<endl;
    s1.push("tejas");
    cout<<s1.capacity<<endl;
    s1.pop();
    s1.push("aarya");
    s1.printStack();
    cout<<endl;
    cout<<s1.isEmpty();
    
    
    
    return 0;
}