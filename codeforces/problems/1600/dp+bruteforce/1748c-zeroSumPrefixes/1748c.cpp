#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mxN = 2e5;

ll a[mxN + 1];
map<ll, ll> freq;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n;
    cin >> t;
    while (t--)
    {
        ll maxFreq = 0, curSum = 0, ans = 0;
        bool found = false;
        freq.clear();
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] == 0)
            {
                if (found)
                {
                    ans += maxFreq;
                }
                else
                {
                    ans += freq[0];
                }
                found = true;
                maxFreq = 0, freq.clear();
            }
            curSum += a[i];
            maxFreq = max(maxFreq, ++freq[curSum]);
        }
        if (found)
        {
            ans += maxFreq;
        }
        else
        {
            ans += freq[0];
        }
        cout << ans << '\n';
    }
}