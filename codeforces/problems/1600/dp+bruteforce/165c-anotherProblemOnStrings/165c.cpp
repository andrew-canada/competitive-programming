#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mxK = 1e6;

int psa[mxK + 1];
map<int, int> num;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int k;
    string s;
    cin >> k >> s;

    int n = s.size();
    num[0] = 1;

    ll ans = 0;
    for (int i = 0; i < n; ++i)
    {
        psa[i + 1] = psa[i] + (s[i] - '0');
        if (psa[i + 1] >= k)
        {
            ans += num[psa[i + 1] - k];
        }
        num[psa[i + 1]]++;
    }
    cout << ans << '\n';
}