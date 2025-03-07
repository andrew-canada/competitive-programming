#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    string s;
    cin >> n >> k >> s;

    string ans = s;
    ans.resize(k, 'z');
    for (int i = 1; i <= n; ++i)
    {
        string pref = s.substr(0, i);
        string cur;
        while (cur.size() < k)
        {
            cur += pref;
        }
        cur.resize(k);
        if (cur < ans)
        {
            ans = cur;
        }
    }

    cout << ans << '\n';
}