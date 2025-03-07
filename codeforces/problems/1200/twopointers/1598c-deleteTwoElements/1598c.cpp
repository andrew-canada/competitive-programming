#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f3f
#define pb push_back

void solve()
{
    int n, v1, v2;
    ll ans = 0, sum = 0, rem;
    cin >> n;
    vector<int> a(n);
    map<int, int> freq;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
        freq[a[i]]++;
    }
    if (2 * sum % n)
    {
        cout << "0\n";
        return;
    }
    rem = (2 * sum) / n;
    for (int i = 0; i < n; i++)
    {
        v1 = a[i];
        v2 = rem - v1;
        if (freq.count(v2))
        {
            ans += freq[v2];
        }
        if (v1 == v2)
        {
            ans -= 1;
        }
    }
    cout << ans / 2 << '\n';
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