#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mxX = 1e6, M = 1e9 + 7;

ll nC2(ll n)
{
    // modular inverse of 2 under odd M is (M+1)/2
    return (((n % M) * ((n - 1) % M) % M) * ((M + 1) / 2)) % M;
}

int main()
{
    ll n, nxt, ans = 0;
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        nxt = n / (n / i);
        ans = ans + ((n / i) % M) * (nC2(nxt + 1) - nC2(i)) % M;
        i = nxt;
    }
    cout << ans % M;
}