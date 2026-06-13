// Each container provides iterators so you can traverse (move through) the elements in that container.
//container_type::iterator

// :: scope resolution operator tells about scope


#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    std::ios_base::sync_with_stdio(false);
    vector<int>arr = {3,5,7,9,2,6};
    vector<int>::iterator it;
    vector<int>result;
    int key = 5;
    unordered_map<int , int> m;
    for(int i = 0 ; i < arr.size() ; i++){
        int diff = abs(arr[i] - key);
        m[diff] = arr[i];
        result.push_back(diff);
    }
    sort(result.begin() , result.end());
    for(int i = 0 ; i < result.size() ; i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
    for(int i = 0 ; i < result.size() ; i++){
        result[i] = m[result[i]];
    }
    for(int i = 0 ; i < result.size() ; i++){
        cout<<result[i]<<" ";
    }
    return 0;
}