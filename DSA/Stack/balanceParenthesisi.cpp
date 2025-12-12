#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    std::ios_base::sync_with_stdio(false);
    string equation;
    cin>>equation;
    cout<<equation<<endl;
    stack<char> s1;
    for (char c : equation) {
        if (c == '{' || c == '(' || c == '[') {
            s1.push(c);
        }
        else if (c == ')' || c == '}' || c == ']') {
            if (s1.empty()) {
                cout << "Not Balanced";
                return 0;
            }
            if (c == ')' && s1.top() == '(') {
                s1.pop();
            }
            else if (c == '}' && s1.top() == '{') {
                s1.pop();
            }
            else if (c == ']' && s1.top() == '[') {
                s1.pop();
            } else {
                cout<<"Not Balanced";
                return 0;
            }
        }
    }

    if(s1.empty()){
        cout<<"balanced";
    }else{
        cout<<"Not Balanced";
    }
    return 0;
}