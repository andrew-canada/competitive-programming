#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f3f
#define pb push_back

void solve()
{
    int n, ans = -1;
    cin >> n;
    vector<int> l(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> l[i];
    }
    for (int i = 0; i <= n; i++)
    {
        int cur = 0;
        for (int j = 1; j <= n; j++)
        {
            cur += (l[j] > i);
        }
        if (cur == i)
        {
            ans = i;
        }
    }
    cout << ans << '\n';
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