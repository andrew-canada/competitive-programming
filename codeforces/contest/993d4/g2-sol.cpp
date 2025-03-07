#include <bits/stdc++.h>
using namespace std;

void sol()
{
    int n;
    cin >> n;
    vector<int> p(n + 1), in(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
        in[p[i]]++;
    }

    queue<int> q;
    vector<int> len(n + 1, 1);

    for (int i = 1; i <= n; i++)
    {
        if (!in[i])
            q.push(i);
    }
    int mx = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        mx = max(mx, len[u]);
        int v = p[u];
        len[v] += len[u];
        if (!--in[v])
            q.push(v);
    }

    cout << mx + 2 << '\n';
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    int T = 1;
    cin >> T;
    while (T--)
        sol();

    return 0;
}