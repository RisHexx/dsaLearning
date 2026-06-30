#include <bits/stdc++.h>
using namespace std;
#define ll long long

int fact(int n){
    if(n <= 0) return 1;
    return n * fact(n - 1);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    int n;
    cin>>n;

    cout<<fact(n);
    
    return 0;
}