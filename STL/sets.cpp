//A set is an STL container that stores unique elements in sorted order.
// multiset is a set but in that duplicates are allowed
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {

    set<int> s;
    multiset<int> m;

    s.insert(10);
    m.insert(10);
    // O(log n) Time complexity to insert/search/delete
    // stores in sorted order
    s.insert(5);
    m.insert(5);
    s.insert(20);
    m.insert(20);
    s.insert(10); // duplicate
    m.insert(10); // duplicate but allowed

    cout<<s.size()<<endl;
    cout<<m.size()<<endl;
    cout<<s.count(5)<<endl; // check 5 exists
    cout<<m.count(10)<<endl; // no of occ of 10

    for(int x : s){
        cout << x << " ";
    }
    return 0;
}