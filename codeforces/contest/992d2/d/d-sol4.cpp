#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
const int N = 2e5 + 10;
const int maxn = 5e5 + 10;
const int inf = 0x3f3f3f3f;

struct edge
{
    int to, ne;
} e[maxn];
int head[N], ecnt = 1;

void add(int x, int y)
{
    e[++ecnt].to = y;
    e[ecnt].ne = head[x];
    head[x] = ecnt;
}

int color[N];

bool dfs(int x, int c)
{
    color[x] = c;
    for (int i = head[x]; i; i = e[i].ne)
    {
        int y = e[i].to;
        if (!color[y])
        {
            if (dfs(y, 3 - c))
                return 1;
        }
        else if (color[y] == c)
            return 1;
    }
    return 0;
}

int in[N];
bool vis[N];
int ans[N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        for (int i = 0; i <= n; i++)
        {
            vis[i] = head[i] = ans[i] = color[i] = 0;
            in[i] = 0;
        }
        ecnt = 1;
        for (int i = 1; i <= n - 1; i++)
        {
            int x, y;
            cin >> x >> y;
            in[x]++, in[y]++;
            add(x, y), add(y, x);
        }

        int pos = 0;
        for (int i = 1; i <= n; i++)
        {
            if (in[i] == n - 1)
            {
                ans[i] = 2;
                pos = i;
                break;
            }
        }
        if (pos)
        {
            int up = 4;
            for (int i = head[pos]; i; i = e[i].ne)
            {
                int y = e[i].to;
                ans[y] = up;
                up += 2;
            }
            for (int i = 1; i <= n; i++)
            {
                if (ans[i] == ans[pos] + 2)
                    ans[i] = 1;
            }
            for (int i = 1; i <= n; i++)
                cout << ans[i] << ' ';
            cout << endl;
            continue;
        }

        dfs(1, 1);
        vector<int> v1, v2;
        for (int i = 1; i <= n; i++)
        {
            if (color[i] == 1)
                v1.push_back(i);
            else
                v2.push_back(i);
        }
        int mi = inf, z = 0;
        for (auto i : v2)
        {
            if (in[i] < mi)
            {
                mi = in[i];
                z = i;
            }
        }
        int cnt = 0;
        for (int i = head[z]; i; i = e[i].ne)
        {
            int y = e[i].to;
            cnt++;
            vis[y] = 1;
        }

        // cout << v2.size() << endl;

        int m = v1.size();
        ans[z] = (m + 1) * 2;
        int up = 2 * m, low = 2;
        for (auto i : v1)
        {
            if (!vis[i])
            {
                ans[i] = up;
                up -= 2;
            }
            else
            {
                ans[i] = low;
                low += 2;
            }
        }

        // if (v1.size() == cnt)
        // {
        //     for (int i = 1; i <= n; i++)
        //     {
        //         if (ans[i] == ans[z] - 2)
        //         {
        //             ans[i] = ans[z] - 1;
        //             break;
        //         }
        //     }
        // }

        up = ans[z] + 2;
        for (auto i : v2)
        {
            if (!ans[i])
            {
                ans[i] = up;
                up += 2;
            }
        }

        for (int i = 1; i <= n; i++)
            cout << ans[i] << ' ';
        cout << endl;
    }
}