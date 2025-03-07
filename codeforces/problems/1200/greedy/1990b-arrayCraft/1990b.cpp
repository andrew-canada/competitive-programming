#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f3f
#define pb push_back

void solve()
{
    int n, x, y, val = -1;
    cin >> n >> x >> y;
    vector<int> a(n, 1);
    --x, --y;
    for (int i = x + 1; i < n; i++)
    {
        a[i] = val;
        val *= -1;
    }
    val = -1;
    for (int i = y - 1; i >= 0; i--)
    {
        a[i] = val;
        val *= -1;
    }
    for (int i = 0; i < n; i++)
    {
        if (i)
        {
            cout << " ";
        }
        cout << a[i];
    }
    cout << '\n';
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
