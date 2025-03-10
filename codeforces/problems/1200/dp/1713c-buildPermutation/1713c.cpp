#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f3f
#define pb push_back

void solve()
{
    int n, cur, x, start, need;
    cin >> n;
    vector<int> dp(n);
    cur = n - 1;
    while (cur > 0)
    {
        x = ceil(sqrt(cur));
        start = cur, need = x * x - cur;
        for (int i = need; i <= start; i++)
        {
            dp[i] = cur;
            --cur;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << dp[i] << " ";
    }
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}