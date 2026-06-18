#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    std::ios_base::sync_with_stdio(false);
    int cost = 5;
    int weight,distance;
    cin>>weight>>distance;
    cost += (weight * 2);
    distance /= 10;
    cost += (distance * 0.5);
    cout<<cost;
    return 0;
}