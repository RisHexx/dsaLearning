#include <bits/stdc++.h>
using namespace std;
#define ll long long

int myPower(int x , int n){
    if(n == 0) return 1;
    return x * myPower(x , n - 1);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    int x , n;
    cin >> x >> n;

    cout<<myPower(x,n);
    
    return 0;
}