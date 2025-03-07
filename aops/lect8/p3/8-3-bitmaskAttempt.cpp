#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

double p[121];
map<string, double> dp;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < 2 * n; i++)
    {
        cin >> p[i];
    }
    dp[string(2 * n, '0')] = 1;
    for (ll role = 0; role < n; role++)
    {
        for (const auto &state : dp)
        {
            const string &actors = state.first;
            double prob = state.second;
            for (ll i = 0; i < 2 * n; i++)
            {
                if (actors[i] == '1')
                {
                    continue;
                }
                for (ll j = i + 1; j < 2 * n; j++)
                {
                    if (actors[j] == '1')
                    {
                        continue;
                    }
                    string next = actors;
                    next[i] = '1', next[j] = '1';
                    dp[next] = max(dp[next], dp[actors] * (1 - p[i] + 1 - p[j] - (1 - p[i]) * (1 - p[j])));
                }
            }
        }
    }
    cout << fixed << setprecision(9) << dp[string(2 * n, '1')];
}