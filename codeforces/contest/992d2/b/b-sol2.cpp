#include <bits/stdc++.h>

#define int long long
#define all(x) x.begin(), x.end()
#define endl '\n'

using namespace std;

vector<int> lim;

void solve()
{
    int n;
    cin >> n;
    int x = lower_bound(lim.begin(), lim.end(), n) - lim.begin();
    cout << x + 1 << endl;
}
int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int v = 3;
    lim.push_back(1);
    lim.push_back(v);
    int i = 2;
    while (v <= 1e5)
    {
        v *= 2;
        lim.push_back(v);
        i++;
    }
    for (int i = 1; i < lim.size(); i++)
    {
        lim[i] += lim[i - 1];
    }
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}