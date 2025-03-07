#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

struct edge
{
    int from, to;
} eg[N << 1];

int front[N], num;

void add(int x, int y)
{
    eg[++num] = (edge){front[x], y};
    front[x] = num;
}

vector<int> node[N];
int top[N], ans[N], fa[N];

void dfs(int o, int from, int _top, int dep)
{
    node[dep].push_back(o);
    top[o] = _top;
    fa[o] = from;

    for (int i = front[o]; i; i = eg[i].from)
    {
        int to = eg[i].to;
        if (to == from)
            continue;
        if (o == 1)
            _top = to;
        dfs(to, o, _top, dep + 1);
    }
}

void solve(int Case)
{
    int n;
    cin >> n;

    num = 0;
    for (int i = 1; i <= n; ++i)
        node[i].clear(), front[i] = 0;
    for (int i = 1, x, y; i < n; ++i)
        cin >> x >> y, add(x, y), add(y, x);

    dfs(1, 0, 0, 1);

    ans[1] = 1;

    int now = 3, _s = eg[front[1]].to;
    for (int i = 2; i <= n; ++i)
    {
        if (node[i].size() == 0)
            continue;
        if (fa[node[i][0]] == node[i - 1].back())
            ans[node[i][0]] = ans[node[i - 1].back()] + 1;
        else
        {
            ans[node[i][0]] = ans[node[i - 1].back()] + 2;
            if ((ans[node[i][0]] - ans[fa[node[i][0]]]) & 1)
                --ans[node[i][0]];
        }
        int now = ans[node[i][0]];
        for (int j = 1; j < node[i].size(); ++j)
        {
            now += 2;
            if ((node[i - 1].size() > 1 && ((now - ans[fa[node[i][j]]]) & 1)) || (node[i - 1].size() == 1 && j == 1))
                ++now;
            ans[node[i][j]] = now;
        }
    }

    for (int i = 1; i <= n; ++i)
        cout << ans[i] << " ";
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int T, Case = 0;
    cin >> T;
    while (T--)
        solve(++Case);
}