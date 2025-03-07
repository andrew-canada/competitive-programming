#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mxN = 5e5;

int n, b, s, e, v, q;
ll ans;
struct node
{
    ll s, lz;
} st[1 << 20];

void app(int ti, int val, int tl, int tr)
{
    st[ti].s += val * (tr - tl + 1);
    st[ti].lz += val;
}

void psh(int mid, int ti, int tl, int tr)
{
    app(2 * ti, st[ti].lz, tl, mid);
    app(2 * ti + 1, st[ti].lz, mid + 1, tr);
    st[ti].lz = 0;
}

ll qry(int l, int r, int ti = 1, int tl = 1, int tr = n)
{
    if (tl >= l && tr <= r)
    {
        return st[ti].s;
    }
    int mid = (tl + tr) / 2;
    psh(mid, ti, tl, tr);
    return (l <= mid ? qry(l, r, 2 * ti, tl, mid) : 0) +
           (r > mid ? qry(l, r, 2 * ti + 1, mid + 1, tr) : 0);
}

void upd(int l, int r, int val, int ti = 1, int tl = 1, int tr = n)
{
    if (tl >= l && tr <= r)
    {
        app(ti, val, tl, tr);
        return;
    }
    int mid = (tl + tr) / 2;
    psh(mid, ti, tl, tr);
    if (l <= mid)
    {
        upd(l, r, val, 2 * ti, tl, mid);
    }
    if (r > mid)
    {
        upd(l, r, val, 2 * ti + 1, mid + 1, tr);
    }
    st[ti].s = st[2 * ti].s + st[2 * ti + 1].s;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> b;
    for (int i = 0; i < b; i++)
    {
        cin >> s >> e >> v >> q;
        upd(s, e, v);
        cout << qry(q, q) << '\n';
    }
}