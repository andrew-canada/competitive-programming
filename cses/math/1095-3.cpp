#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int M = 1e9 + 7;

ll mult(ll b, ll e)
{
    ll a = 1;
    while (e)
    {
        if (e & 1)
        {
            a = (a * b) % M;
        }
        e >>= 1;
        b = (b * b) % M;
    }
    return a;
}

int main()
{
    ll n, b, e;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> b >> e;
        cout << mult(b, e) << '\n';
    }
}