#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f3f
#define pb push_back

void solve()
{
    int n, ans = 0;
    cin >> n;
    int j = n - 1;
    vector<int> x(n), y(n);
    vector<array<int, 2>> diff(n);

    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> y[i];
    }
    for (int i = 0; i < n; i++)
    {
        diff[i][0] = y[i] - x[i];
        diff[i][1] = i;
    }
    sort(diff.rbegin(), diff.rend());
    for (int i = 0; i < n; i++)
    {
        while (j > i && diff[i][0] + diff[j][0] < 0)
        {
            j--;
        }
        if (j <= i)
        {
            break;
        }
        ans++;
        j--;
    }
    cout << ans << '\n';
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
