#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f
#define pb push_back

typedef long long ll;

const int mxN = 15e4, mxC = 16;

int n, m;
int ans[mxN + 1];
int a[mxN + 1], b[mxN + 1], c[mxN + 1];
int diff[mxC + 1][mxN + 1];

struct node
{
    int div;
} st[1 << 19];

void build(int ti = 1, int tl = 0, int tr = n)
{
    if (tl == tr)
    {
        st[ti].div = ans[tl];
    }
    else
    {
        int mid = (tl + tr) / 2;
        build(ti << 1, tl, mid);
        build((ti << 1) + 1, mid + 1, tr);
        st[ti].div = gcd(st[ti << 1].div, st[(ti << 1) + 1].div);
    }
}

int query(int l, int r, int ti = 1, int tl = 0, int tr = n)
{
    // cout << tl << " " << tr << " " << ti << " " << st[ti].div << '\n';
    if (tl >= l && tr <= r)
    {
        return st[ti].div;
    }
    int mid = (tl + tr) / 2;
    return gcd(l <= mid ? query(l, r, ti << 1, tl, mid) : 0,
               r > mid ? query(l, r, (ti << 1) + 1, mid + 1, tr) : 0);
}

int main()
{
    // freopen("S_5-2.in", "r", stdin);
    // freopen("S_5-2.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i] >> b[i] >> c[i];
        diff[c[i]][a[i]]++;
        diff[c[i]][b[i] + 1]--;
    }
    for (int i = 1; i <= 16; i++)
    {
        int numDiv = 0;
        for (int j = 1; j <= n; j++)
        {
            numDiv += diff[i][j];
            diff[i][j] = numDiv;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int mult = 1;
        for (int j = 1; j <= 16; j++)
        {
            if (diff[j][i] > 0)
            {
                mult = mult * j / gcd(mult, j);
            }
        }
        ans[i] = mult;
    }
    // cout << "a\n";
    build();
    // cout << "a\n";
    for (int i = 1; i <= m; i++)
    {
        int val = query(a[i], b[i]);
        // cout << "query val: " << val << '\n';
        // cout << "target gcd: " << c[i] << '\n';
        if (val != c[i])
        {
            cout << "Impossible";
            return 0;
        }
    }
    // cout << "a\n";
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    // cout << "a\n";
}

/*
2 2
1 2 2
2 2 6
*/