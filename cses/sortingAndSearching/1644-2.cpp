#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define INF 0x3f3f3f3f

typedef long long ll;

const int mxN = 2e5, mxX = 1e6, M = 1e9 + 7;

ll psa[mxN + 1];

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++)
    {
        cin >> psa[i];
        psa[i] += psa[i - 1];
    }
    ll ans = -2e14;
    set<ll> s;
    for (int i = 0; i <= n; i++)
    {
        if (i >= a)
        {
            s.insert(psa[i - a]);
        }
        if (s.size())
        {
            ans = max(ans, psa[i] - *s.begin());
        }
        if (i >= b)
        {
            s.erase(s.find(psa[i - b]));
        }
    }
    cout << ans;
}