#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ll n;
    cin >> n;
    ll sum = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int a;
        cin >> a;
        sum += a;
    }
    cout << n * (n + 1) / 2 - sum;
}