#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mxN = 1e6;

ll pts[mxN + 1], psa[mxN + 1];

int main()
{
    ll n, c;
    cin >> n >> c;
    int pt;
    for (int i = 0; i < n; i++)
    {
        cin >> pt;
        pts[pt]++;
    }
    psa[0] = pts[0];
    for (int i = 1; i < c; i++)
    {
        psa[i] = psa[i - 1] + pts[i];
    }
    ll ans = n * (n - 1) * (n - 2) / 6;
    ll opp, np;
    for (int i = 0; i < c; i++)
    {
        opp = (i + c / 2) % c;
        if (i < opp)
        {
            np = psa[opp] - (i >= 1 ? psa[i - 1] : 0);
        }
        else
        {
            np = psa[opp] + (psa[c - 1] - (i >= 1 ? psa[i - 1] : 0));
        }
        ans -= pts[i] * (np - pts[i]) * (np - pts[i] - 1) / 2;
        ans -= (np - pts[i]) * pts[i] * (pts[i] - 1) / 2;
        ans -= pts[i] * (pts[i] - 1) * (pts[i] - 2) / 6;
    }
    if (c & 1 ^ 1)
    {
        for (int i = 0; i < c / 2; i++)
        {
            opp = (i + c / 2) % c;
            ans += pts[i] * pts[opp] * (pts[opp] - 1) / 2;
            ans += pts[opp] * pts[i] * (pts[i] - 1) / 2;
        }
    }
    cout << ans;
}