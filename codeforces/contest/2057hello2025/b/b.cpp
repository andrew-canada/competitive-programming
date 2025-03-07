#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define pb push_back

typedef long long ll;

const int mxN = 1e5;

int a[mxN + 1];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            mp[a[i]]++;
        }

        if (n == k)
        {
            cout << "1\n";
            continue;
        }

        vector<int> freq;
        for (const auto &val : mp)
        {
            freq.pb(val.second);
        }
        sort(freq.begin(), freq.end());
        int ans = freq.size();
        for (const auto &val : freq)
        {
            if (k >= val)
            {
                k -= val;
                ans--;
            }
            else
            {
                break;
            }
        }
        cout << ans << '\n';
    }
}