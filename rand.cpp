#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    std::ios_base::sync_with_stdio(false);
    string input;
    getline(cin,input);
    int start = 0;
    int n = input.size();
    for(int i = 0 ; i  <= n ; i++){
        if(input[i] == ' ' || i == n){
            int left = start;
            int right = i - 1;

            while(left < right){
                swap(input[left] , input[right]);
                left++;
                right--;
            }
            start = i + 1;
        }
    }

    cout<<input;
    
    return 0;
}