#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f3f
#define pb push_back

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), lastIdx(n + 1, -1);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int ans = INF;
    for (int i = 0; i < n; i++)
    {
        if (lastIdx[a[i]] != -1)
        {
            ans = min(ans, i - lastIdx[a[i]] + 1);
        }
        lastIdx[a[i]] = i;
    }
    cout << (ans > n ? -1 : ans) << '\n';
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