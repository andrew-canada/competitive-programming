#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt()
{
    int x;
    cin >> x;
    return x;
}

void solve()
{
    int n = nxt();
    vector<char> used(n, false);
    int cur = 0;
    for (int i = 0; i < n; ++i)
    {
        int x = nxt() - 1;
        if (used[x])
        {
            while (used[cur])
            {
                ++cur;
            }
            x = cur;
        }
        used[x] = true;
        cout << x + 1 << " ";
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = nxt();
    while (t--)
    {
        solve();
    }

    return 0;
}