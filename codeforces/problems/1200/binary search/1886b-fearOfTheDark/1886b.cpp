#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f3f
#define pb push_back

double dist(int x1, int y1, int x2, int y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void solve()
{
    int px, py, ax, ay, bx, by;
    cin >> px >> py >> ax >> ay >> bx >> by;
    double pa = dist(px, py, ax, ay), pb = dist(px, py, bx, by);
    double oa = dist(0, 0, ax, ay), ob = dist(0, 0, bx, by);
    double ab = dist(ax, ay, bx, by);
    double ans = INF;
    ans = min({ans, max(pa, oa), max(pb, ob), max({ab / 2, pa, ob}), max({ab / 2, pb, oa})});
    cout << setprecision(10) << fixed << ans << '\n';
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