#include <bits/stdc++.h>
using namespace std;
#define ll long long

int sum(int n){
    if (n <= 0) return 0;
    return n + sum(n -1);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    int i;
    cin>>i;

    cout<<sum(i);
    
    return 0;
}