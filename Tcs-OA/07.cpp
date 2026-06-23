#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    std::ios_base::sync_with_stdio(false);
    int size;
    cin>>size;
    vector<int> score(size);
    vector<string> names(size);
    for(int i = 0 ; i < size ; i++){
        cin>>score[i];
    }
    for(int i = 0 ; i < size ; i++){
        cin>>names[i];
    }

    int maxScore = score[0];
    int maxIndx = 0;
    for(int i = 1 ; i < score.size() ; i++){
        if(maxScore < score[i]){
            maxScore = score[i];
            maxIndx = i;
        }
    }
    cout<<names[maxIndx];
    
    return 0;
}