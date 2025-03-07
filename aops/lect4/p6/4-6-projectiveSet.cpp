#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mxN = 20, mxM = 60;

int cards[mxM + 1];
ll dp[2][1 << mxN + 1];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    string s;
    for (int i = 0; i < m; i++)
    {
        cin >> s;
        int card = 0;
        for (char c : s)
        {
            card |= (1 << (c - 'A'));
        }
        cards[i] = card;
    }

    int possible = 1 << n;
    bool cur = 0;
    dp[0][0] = 1;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < possible; j++)
        {
            dp[!cur][j] = dp[cur][j];
        }
        for (int j = 0; j < possible; j++)
        {
            dp[!cur][j ^ cards[i]] += dp[cur][j];
        }
        cur = !cur;
    }
    cout << dp[cur][0] - 1 << '\n';
}