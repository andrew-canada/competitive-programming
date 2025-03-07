#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f3f
#define pb push_back

const int mxN = 2e5;

int dp[mxN + 1];

void solve()
{
    int n;
    cin >> n;
    cout << dp[n] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, val, cur;
    cin >> t;
    for (int i = 1; i <= mxN; i++)
    {
        cur = i, val = 0;
        while (cur)
        {
            val += cur % 10;
            cur /= 10;
        }
        dp[i] = dp[i - 1] + val;
    }
    while (t--)
    {
        solve();
    }
}