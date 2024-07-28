#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f

const int mxN = 2e5;

int n, q;
int x[mxN + 1];

struct node
{
    int mn;
} st[2 << 19];

void update(int l, int val, int ti = 1, int tl = 0, int tr = n - 1)
{
    if (tl == tr)
    {
        st[ti].mn = val;
        return;
    }
    int mid = (tl + tr) / 2;
    if (l <= mid)
    {
        update(l, val, ti << 1, tl, mid);
    }
    else
    {
        update(l, val, (ti << 1) + 1, mid + 1, tr);
    }
    st[ti].mn = min(st[ti << 1].mn, st[(ti << 1) + 1].mn);
}

int query(int l, int r, int ti = 1, int tl = 0, int tr = n - 1)
{
    if (tl >= l && tr <= r)
    {
        return st[ti].mn;
    }
    int mid = (tl + tr) / 2;
    return min(l <= mid ? query(l, r, ti << 1, tl, mid) : INF,
               r > mid ? query(l, r, (ti << 1) + 1, mid + 1, tr) : INF);
}

int main()
{
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
        update(i, x[i]);
    }
    for (int i = 0; i < q; i++)
    {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 1)
        {
            update(--a, b);
        }
        else
        {
            cout << query(--a, --b) << '\n';
        }
    }
}

/*
8 2
7 6 4 6 2 9 4 8
2 1 1
2 1 2
*/