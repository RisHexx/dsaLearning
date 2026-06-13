#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    std::ios_base::sync_with_stdio(false);
    // unordered_set stores unique elements, but not in sorted order.
    // It uses a hash table internally.
    // o(1) time complexity

    unordered_set<int> s;

    s.insert(10);
    s.insert(25);
    s.insert(7);

    return 0;
}