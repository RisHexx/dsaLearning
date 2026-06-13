#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    std::ios_base::sync_with_stdio(false);
    // smart pointers -> no need to free
    //unique_ptr  → only ONE owner -> make_unique

    unique_ptr<int> p = make_unique<int>(45);
    // auto p = make_unique<int>(45);
    cout<<*p;

    unique_ptr<int[]> arr = make_unique<int[]>(5);
    // auto arr = make_unique<int[]>(5);
    arr[0] = 10;  // natural syntax
    // auto deleted, no delete[] needed
    
    return 0;
}