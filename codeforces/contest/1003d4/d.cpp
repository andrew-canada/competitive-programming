#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f3f
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> arr(n, vector<int>(m));
        vector<ll> sum(n);
        vector<int> idx(n);
        ll ans = 0, cur = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> arr[i][j];
                sum[i] += arr[i][j];
            }
        }
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int i, int j)
             { return sum[i] > sum[j]; });
        for (int i : idx)
        {
            for (int j = 0; j < m; ++j)
            {
                cur += arr[i][j];
                ans += cur;
            }
        }
        cout << ans << '\n';
    }
}