#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f3f
#define pb push_back

void solve()
{
    int n, a, sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        sum += a;
    }
    cout << sum - (n - 1) << '\n';
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