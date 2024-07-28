#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mxN = 2e5;

int n, q;
int arr[mxN + 1];
struct node
{
    ll xr;
} st[1 << 19];

void update(int l, int val, int ti = 1, int tl = 0, int tr = n - 1)
{
    if (tl == tr)
    {
        st[ti].xr = val;
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
    st[ti].xr = st[ti << 1].xr ^ st[(ti << 1) + 1].xr;
}

ll query(int l, int r, int ti = 1, int tl = 0, int tr = n - 1)
{
    if (tl >= l && tr <= r)
    {
        return st[ti].xr;
    }
    int mid = (tl + tr) / 2;
    return (l <= mid ? query(l, r, ti << 1, tl, mid) : 0) ^
           (r > mid ? query(l, r, (ti << 1) + 1, mid + 1, tr) : 0);
}

int main()
{
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        update(i, arr[i]);
    }
    int a, b;
    for (int i = 0; i < q; i++)
    {
        cin >> a >> b;
        cout << query(a - 1, b - 1) << '\n';
    }
}