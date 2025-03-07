#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

const int mxN = 2e5;

int nxt[mxN + 1][27];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s, t;
    int tc;
    cin >> tc;
    while (tc--)
    {
        cin >> s >> t;
        memset(nxt, INF, sizeof(nxt));
        for (int i = s.size() - 1; i >= 0; i--)
        {
            for (int j = 0; j < 26; j++)
            {
                nxt[i][j] = nxt[i + 1][j];
            }
            nxt[i][s[i] - 'a'] = i;
        }

        int ans = 1, pos = 0;
        for (int i = 0; i < t.size(); i++)
        {
            if (pos == s.size())
            {
                pos = 0;
                ans++;
            }
            if (nxt[pos][t[i] - 'a'] == INF)
            {
                pos = 0;
                ans++;
            }
            if (nxt[pos][t[i] - 'a'] == INF && pos == 0)
            {
                ans = INF;
                break;
            }
            pos = nxt[pos][t[i] - 'a'] + 1;
        }

        if (ans >= INF)
        {
            cout << "-1\n";
        }
        else
        {
            cout << ans << '\n';
        }
    }
}