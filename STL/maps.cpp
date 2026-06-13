#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    std::ios_base::sync_with_stdio(false);
    //A map is a container that stores many key-value pairs.
    //while pair just group 2 values together
    //sorted by keys and uses red-black trees as ds and log n time complexity
    map<int,string> m;

    m[1] = "apple";
    m[2] = "ball";
    m[3] = "cat";
    m.insert({4,"dog"});


    // traversing
    //it is not iterator its a map element
    for(auto it : m){
    cout << it.first << " " << it.second << endl;
    }

    cout<<m.size();
    return 0;
}