#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pb push_back

const int mxN = 2e5;

int n, q;
ll x[mxN + 1];

struct node
{
    ll mn, s, lz;
} st[1 << 19];

void app(int ti, ll x, int tl, int tr)
{
    st[ti].mn += x;
    st[ti].s += x * (tr - tl + 1);
    st[ti].lz += x;
}

void psh(int ti, int tl, int mid, int tr)
{
    app(2 * ti, st[ti].lz, tl, mid);
    app(2 * ti + 1, st[ti].lz, mid + 1, tr);
    st[ti].lz = 0;
}

void upd(int l, ll x, int ti = 1, int tl = 0, int tr = n - 1)
{
    if (tl == tr)
    {
        st[ti].mn = x;
        st[ti].s = x;
        return;
    }
    int mid = (tl + tr) / 2;
    psh(ti, tl, mid, tr);
    if (l <= mid)
    {
        upd(l, x, 2 * ti, tl, mid);
    }
    else
    {
        upd(l, x, 2 * ti + 1, mid + 1, tr);
    }
    st[ti].mn = min(st[2 * ti].mn, st[2 * ti + 1].mn);
    st[ti].s = st[2 * ti].s ^ st[2 * ti + 1].s;
}

void upd2(int l, int r, ll x, int ti = 1, int tl = 0, int tr = n - 1)
{
    if (tl >= l && tr <= r)
    {
        app(ti, x, tl, tr);
        return;
    }
    int mid = (tl + tr) / 2;
    psh(ti, tl, mid, tr);
    if (l <= mid)
    {
        upd2(l, r, x, 2 * ti, tl, mid);
    }
    if (mid < r)
    {
        upd2(l, r, x, 2 * ti + 1, mid + 1, tr);
    }
    st[ti].mn = min(st[2 * ti].mn, st[2 * ti + 1].mn);
    st[ti].s = st[2 * ti].s + st[2 * ti + 1].s;
}

ll qry(int l, int r, int ti = 1, int tl = 0, int tr = n - 1)
{
    if (tl >= l && tr <= r)
    {
        return st[ti].s;
    }
    int mid = (tl + tr) / 2;
    psh(ti, tl, mid, tr);
    return (l <= mid ? qry(l, r, 2 * ti, tl, mid) : 0) +
           (mid < r ? qry(l, r, 2 * ti + 1, mid + 1, tr) : 0);
}

int main()
{
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
        upd(i, x[i]);
    }
    int type, a, b, u, k;
    while (q--)
    {
        cin >> type;
        if (type == 1)
        {
            cin >> a >> b >> u, --a, --b;
            upd2(a, b, u);
        }
        else
        {
            cin >> k, --k;
            cout << qry(k, k) << '\n';
        }
    }
}