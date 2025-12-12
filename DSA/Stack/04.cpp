#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    std::ios_base::sync_with_stdio(false);
    stack<int> s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    cout<<s1.size()<<" ";
    s1.pop();
    cout<<s1.top();
    cout<<s1.empty();
    
    return 0;
}