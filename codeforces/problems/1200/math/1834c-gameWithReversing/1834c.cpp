#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f3f
#define pb push_back

void solve()
{
    int n, rep1 = 0, rep2 = 0;
    string s, t;
    cin >> n >> s >> t;
    for (int i = 0; i < n; i++)
    {
        rep1 += s[i] != t[i];
    }
    reverse(t.begin(), t.end());
    for (int i = 0; i < n; i++)
    {
        rep2 += s[i] != t[i];
    }
    int ans1 = (rep1 & 1) ? 2 * rep1 - 1 : 2 * rep1;
    int ans2 = (rep2 & 1) ? 2 * rep2 : 2 * rep2 - 1;
    ans2 = max(ans2, 2);
    cout << min(ans1, ans2) << '\n';
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