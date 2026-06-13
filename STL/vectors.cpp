#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    std::ios_base::sync_with_stdio(false);
    vector<int> a;
    vector<int> v(5); // 0 0 0 0 0
    vector<int> b(5,10); // 10 10 10 10 10
    a.push_back(10);
    a.push_back(20);
    a.push_back(30);
    a.push_back(40);

    cout<<a.size()<<endl;

    cout<<a.empty()<<endl;

    cout<<a.front()<<endl;

    cout<<a.back()<<endl;

    a.pop_back();
    
    for(int i = 0 ; i < a.size() ; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    // range based loop
    for(int x : a){
        cout << x<<" ";
    }
    cout<<endl; 
    // iterators
    for(auto it = a.begin(); it != a.end(); it++){
        cout << *it<<" ";
    }
    
    return 0;
}