#include <bits/stdc++.h>
using namespace std;
#define ll long long


void reverse(string& inp , int i , int j){
    if(i >= j) return;
    swap(inp[i] , inp[j]);
    reverse(inp, i + 1 , j -1 );
}

int main() {
    std::ios_base::sync_with_stdio(false);
    string inp;
    cin>>inp;

    int i = 0;
    int j = inp.size() - 1;
    reverse(inp , i , j);
    cout<<inp;
    
    return 0;
}