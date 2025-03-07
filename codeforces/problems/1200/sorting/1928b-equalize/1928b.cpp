#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f

void solve()
{
    int n, a;
    cin >> n;
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        s.insert(a);
    }
    vector<int> v(s.begin(), s.end());
    int ans = 0, num = 0;
    for (int i = 0; i < v.size(); i++)
    {
        while (v[i] - v[num] >= n)
        {
            num++;
        }
        ans = max(ans, i - num + 1);
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