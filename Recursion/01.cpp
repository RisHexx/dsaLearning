#include <bits/stdc++.h>
using namespace std;
#define ll long long

void print(int n){
    if(n <= 0) return;
    cout<<n<<endl;
    print(n-1);
}

void printA(int n){
    if(n <= 0) return;

    printA(n - 1);
    cout << n << endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    int n;
    cin>>n;

    print(n);
    cout<<"-------"<<endl;
    printA(n);
    
    return 0;
}