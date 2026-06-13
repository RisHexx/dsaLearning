#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    std::ios_base::sync_with_stdio(false);
    //unordered_map stores key–value pairs, just like map.
    // its uses o(1) avg time complexity
    unordered_map<int,string> m;
    m[1] = "apple";
    m[2] = "banana";
    m[3] = "mango";

    for(auto& it : m){
    cout << it.first << " " << it.second << endl;
    }
    // no orderring this loops uses iterators behind the scenes

    cout<<m.count(3); // check if its exist or not 1 if exists else 0
    return 0;
}