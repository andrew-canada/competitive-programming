#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mxN = 1e6, mxM = 1500;

ll ans[2 * mxN + 1];
ll a[mxM + 1][mxM + 1];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll cur = 1;
    for (int i = 1; i < mxM; i++)
    {
        for (int j = i - 1; j >= 1; j--)
        {
            a[j][i - j] = a[j - 1][i - j] + a[j][i - j - 1] - a[j - 1][i - j - 1] + cur * cur;
            ans[cur] = a[j][i - j];
            cur++;
        }
    }

    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << ans[n] << '\n';
    }
}