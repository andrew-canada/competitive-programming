#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f

void solve()
{
    int n, k, x, ans = 0;
    cin >> n >> k;
    vector<int> freq(2 * n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        freq[x]++;
    }
    for (int i = 1; i < k; i++)
    {
        if (i == k - i)
        {
            ans += freq[i] / 2;
            continue;
        }
        int minFreq = min(freq[i], freq[k - i]);
        ans += minFreq;
        freq[i] -= minFreq, freq[k - i] -= minFreq;
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