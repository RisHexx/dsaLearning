#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    std::ios_base::sync_with_stdio(false);
    vector<int> A = {1,1, 1, 2, 2};
    vector<int> result;
	result.push_back(A[0]);
	for(int i = 1 ; i < A.size() ; i++){
		if(result[i - 1] == A[i]){
			continue;
		}else{
			result.push_back(A[i]);
		}
	}
    for(int i = 0 ; i < result.size() ; i++){
        cout<<result[i] <<" ";
    }
    cout<<endl;
	cout<<result.size();
    return 0;
}