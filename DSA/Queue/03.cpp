#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    std::ios_base::sync_with_stdio(false);
    queue<int>q1;
    q1.push(10);
    q1.push(20);
    q1.push(30);
    q1.pop();

    cout<<q1.size()<<" ";
    cout<<q1.front();
    
    return 0;
}