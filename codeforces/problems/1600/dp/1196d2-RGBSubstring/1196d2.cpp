#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string t = "RGB";
    int q, n, k;
    cin >> q;
    while (q--)
    {
        string s;
        cin >> n >> k >> s;
        int ans = INF;
        for (int offset = 0; offset < 3; offset++)
        {
            vector<int> res(n);
            int cur = 0;
            for (int j = 0; j < n; ++j)
            {
                res[j] = (s[j] != t[(j + offset) % 3]);
                cur += res[j];
                if (j >= k)
                {
                    cur -= res[j - k];
                }
                if (j >= k - 1)
                {
                    ans = min(ans, cur);
                }
            }
        }
        cout << ans << '\n';
    }
}