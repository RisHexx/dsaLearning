#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    std::ios_base::sync_with_stdio(false);
    vector<int>arr = {1,6,2};
    int n = arr.size();
    vector<int>result(n);
    stack<int>s;

    for(int i = 0 ; i < n ; i++ ){
        while(!s.empty() && s.top() >= arr[i]){
            s.pop();
        }
        if(s.empty()){
            result[i] = -1;
        }else{
            result[i] = s.top();
        }
        s.push(arr[i]);
    }

    for(int i : result){
        cout<<i<<" ";
    }
    
    return 0;
}