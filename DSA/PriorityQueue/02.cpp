#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    std::ios_base::sync_with_stdio(false);
    // inbuilt priority queue - its Maxpriority
    priority_queue<int> p1;
    cout<<p1.empty();
    p1.push(10);
    p1.push(60);
    p1.push(30);
    p1.push(50);
    cout<<endl;
    cout<<p1.top();
    p1.pop();
    cout<<endl;
    cout<<p1.top();
    
    return 0;
}