#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f3f
#define pb push_back

void solve()
{
    int n, a, ans = 0;
    set<int> s;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        s.insert(a);
    }
    while (!s.empty())
    {
        a = *s.rbegin();
        s.erase(a);
        if (a % 2 == 0)
        {
            ans++;
            s.insert(a / 2);
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