#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<array<int, 2>> v(n * m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[m * i + j][0];
            v[m * i + j][1] = i;
        }
    }
    if (n == 1)
    {
        cout << "1\n";
        return;
    }
    sort(v.begin(), v.end());
    set<int> s;
    vector<int> ord(n);
    for (int i = 0; i < n; i++)
    {
        s.insert(v[i][1]);
        ord[i] = v[i][1];
    }
    if (s.size() != n)
    {
        cout << "-1\n";
        return;
    }
    int idx;
    for (int i = n; i < n * m; i++)
    {
        // cout << "a " << v[i][0] << " " << v[i][1] << '\n';
        if (i % n == 0)
        {
            idx = 0;
        }
        if (v[i][1] != ord[idx])
        {
            // cout << "a ";
            cout << "-1\n";
            return;
        }
        idx++;
    }
    // cout << "a ";
    for (int i : ord)
    {
        cout << i + 1 << " ";
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