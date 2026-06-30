#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool palindrome(string &input, int i, int j){
    if(i >= j) return true;
    return (input[i] == input[j]) &&
           palindrome(input, i + 1, j - 1);
}


bool palindrome2(string &input, int i, int j){
    if(i >= j) return true;

    if(input[i] != input[j])
        return false;

    return palindrome2(input, i + 1, j - 1);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    string input;
    cin>>input;

    int i = 0;
    int j = input.size() - 1;
    cout<<palindrome(input , i , j);
    
    return 0;
}