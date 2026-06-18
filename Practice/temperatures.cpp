#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int>result(n);
        for(int i = 0 ; i < n - 1 ; i++){
            int count = 1;
            int j = i + 1;
            while(j < n  &&  temperatures[j] < temperatures[i]){
                j++;
                count++;
            }
            if(j == n){
                result[i] = 0;
            }else{
                result[i] = count;
            }
        }
        result[n-1] = 0;
        return result;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    vector<int> temperatures = {30,60,90};
    vector<int> result;
    
    result = dailyTemperatures(temperatures);

    for(int i : result){
        cout<< i << " ";
    }
    
    return 0;
}