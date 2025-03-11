#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f3f
#define pb push_back

void solve()
{
    int x;
    cin >> x;

    for (int i = 0; i < 32; i++)
    {
        int val = 1 << i;
        if (val >= x)
        {
            break;
        }
        int y = x - val;
        if ((x & y) != 0 && (x ^ y) > val)
        {
            cout << y << '\n';
            return;
        }
    }
    cout << "-1\n";
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