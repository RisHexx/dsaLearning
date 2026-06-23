#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    std::ios_base::sync_with_stdio(false);
    string str;
    //getline() reads an entire line, including spaces, until it encounters a newline (\n).
    getline(cin, str);

    // we push the word in set while traversing it 
    // next time we got that word which is in set we skip
    unordered_set<string>s;
    bool first = true;
    string result =  "";
    stringstream ss(str);
    string word;
    while (ss >> word) {
        if(s.count(word) == 0){
            if(!first){
            result += " ";
            }
            first = false;
            result += word;
            s.insert(word);
        }
    }
    cout<<result;
    
    return 0;
}