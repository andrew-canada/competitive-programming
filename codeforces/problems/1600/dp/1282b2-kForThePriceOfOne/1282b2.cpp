#include <bits/stdc++.h>
using namespace std;

const int mxN = 2e5;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, p, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> p >> k;
        int pref = 0;
        int ans = 0;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        for (int i = 0; i <= k; i++)
        {
            int sum = pref;
            if (sum > p)
            {
                break;
            }
            int cnt = i;
            for (int j = i + k - 1; j < n; j += k)
            {
                if (sum + a[j] <= p)
                {
                    cnt += k;
                    sum += a[j];
                }
                else
                {
                    break;
                }
            }
            pref += a[i];
            ans = max(ans, cnt);
        }
        cout << ans << "\n";
    }
}