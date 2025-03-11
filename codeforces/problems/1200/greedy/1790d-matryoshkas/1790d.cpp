#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f3f
#define pb push_back

void solve()
{
    int n, ans = 0, prev = 0;
    cin >> n;
    vector<int> a(n);
    map<int, int> freq;
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        freq[a[i]]++;
        s.insert(a[i]);
        s.insert(a[i] + 1);
    }
    for (int i : s)
    {
        ans += max(0, freq[i] - prev);
        prev = freq[i];
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