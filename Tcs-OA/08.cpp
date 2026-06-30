#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    std::ios_base::sync_with_stdio(false);
    int num;
    cin >> num;

    int sum = 0;
    int power = 0;
    int temp = num;

    if (temp == 0)
    {
        power = 1;
    }
    else
    {
        while (temp > 0)
        {
            power++;
            temp /= 10;
        }
    }
    temp = num;
    while (temp > 0) {
            int digit = temp % 10;
            sum += round(pow(digit, power));
            temp /= 10;
        }
    cout << "sum = " << sum << endl;

    return 0;
}