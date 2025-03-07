#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f3f
#define pb push_back

void solve()
{
    int n, m, a, idx = 0;
    set<int> s[2];
    cin >> n >> m >> a;
    s[idx].insert(a);
    while (m--)
    {
        int x;
        char c;
        cin >> x >> c;
        while (!s[idx].empty())
        {
            int u = *(s[idx].begin());
            s[idx].erase(u);
            if (c == '?' || c == '0')
            {
                s[idx ^ 1].insert((u + x - 1) % n + 1);
            }
            if (c == '?' || c == '1')
            {
                s[idx ^ 1].insert((u - x - 1 + n) % n + 1);
            }
        }
        idx ^= 1;
    }
    cout << s[idx].size() << '\n';
    for (int i : s[idx])
    {
        cout << i << ' ';
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
