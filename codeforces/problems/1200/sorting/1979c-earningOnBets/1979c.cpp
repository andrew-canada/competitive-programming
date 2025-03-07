#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f3f
#define pb push_back

void solve()
{
    int n, lcmVal = 1, sum = 0;
    cin >> n;
    vector<int> k(n);
    for (int i = 0; i < n; i++)
    {
        cin >> k[i];
    }
    for (int i = 0; i < n; i++)
    {
        lcmVal = lcm(lcmVal, k[i]);
    }
    for (int i = 0; i < n; i++)
    {
        sum += lcmVal / k[i];
    }
    if (sum < lcmVal)
    {
        for (int i = 0; i < n; i++)
        {
            cout << lcmVal / k[i] << " ";
        }
        cout << '\n';
    }
    else
    {
        cout << "-1\n";
    }
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