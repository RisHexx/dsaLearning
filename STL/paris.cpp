#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    std::ios_base::sync_with_stdio(false);
    //A pair stores two values together.

    //pair<data_type1, data_type2> variable_name;
    pair<int, int> p;
    //pair<int,int> p = {5,7};
    p.first = 10;
    p.second = 20;

    cout<<p.first<<" "<<p.second;
    cout<<endl;

    //creating vector of pair

    vector<pair<int,int>> v ;
    v.push_back({1,2});
    cout<<v[0].first<<" "<<v[0].second;

    
    
    return 0;
}