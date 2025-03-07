#include <bits/stdc++.h>

using namespace std;

#define pb push_back

typedef long long ll;

const int mxN = 6e4;

int n;
array<ll, 2> pts[mxN + 1];
vector<array<ll, 2>> hull;

bool clockwise(const array<ll, 2> &p, const array<ll, 2> &q, const array<ll, 2> &r)
{
    return (r[1] - p[1]) * (q[0] - p[0]) < (r[0] - p[0]) * (q[1] - p[1]);
}

void calcHull()
{
    int idx = 0;
    for (int i = 1; i < n; i++)
    {
        if (pts[i][1] < pts[idx][1] || pts[i][1] == pts[idx][1] && pts[i][0] < pts[idx][0])
        {
            idx = i;
        }
    }
    swap(pts[0], pts[idx]);

    array<ll, 2> cur = pts[0];
    sort(pts + 1, pts + n, [&cur](array<ll, 2> p, array<ll, 2> q)
         { return !clockwise(cur, p, q); });

    hull.pb(pts[0]), hull.pb(pts[1]), hull.pb(pts[2]);
    for (int i = 3; i < n; i++)
    {
        while (hull.size() > 1 && clockwise(hull[hull.size() - 2], hull.back(), pts[i]))
        {
            hull.pop_back();
        }
        hull.pb(pts[i]);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> pts[i][0] >> pts[i][1];
    }

    calcHull();
    int c = hull.size();
    cout << 2 * n - c - 2;
}