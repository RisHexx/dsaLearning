#include <bits/stdc++.h>
using namespace std;
#define ll long long

int fib(int i){
    if(i <= 1){
        return i;
    }
    return fib(i-1) + fib(i - 2);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    int i ;
    cin>>i;

    cout<<fib(i);
    
    return 0;
}