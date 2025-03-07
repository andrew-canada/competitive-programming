#include <bits/stdc++.h>
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
// #define int long long
// #define for(i,r,l) for(int i=r;i<=l;i++)
// #define for(i,r,-l) for(int i=r;i>=l;--i)
using namespace std;

void solve()
{
    int n = 0, m = 0, k = 0;
    cin >> n >> m >> k;
    vector<int> a(m + 1, 0);
    deque<bool> q(n + 1, false);
    for (int i = 1; i <= m; i++)
        cin >> a[i];
    for (int i = 1; i <= k; i++)
    {
        int x = 0;
        cin >> x;
        q[x] = true;
    }
    string s;
    for (int i = 1; i <= m; i++)
    {
        if (n - k >= 2)
            s += '0';
        else if (k == n)
            s += '1';
        else if (q[a[i]] == false)
            s += '1';
        else
            s += '0';
    }
    cout << s << '\n';
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}