#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, q, l, r;
    char c;
    cin >> n >> q;
    vector<vector<int>> pref1(n + 1, vector<int>(26, 0));
    vector<vector<int>> pref2(n + 1, vector<int>(26, 0));
    for (int i = 1; i <= n; i++)
    {
        cin >> c;
        pref1[i][c - 'a']++;
        for (int j = 0; j < 26; j++)
        {
            pref1[i][j] += pref1[i - 1][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> c;
        pref2[i][c - 'a']++;
        for (int j = 0; j < 26; j++)
        {
            pref2[i][j] += pref2[i - 1][j];
        }
    }
    while (q--)
    {
        cin >> l >> r;
        int dif = 0;
        for (int c = 0; c < 26; c++)
        {
            int v1 = pref1[r][c] - pref1[l - 1][c];
            int v2 = pref2[r][c] - pref2[l - 1][c];
            dif += abs(v1 - v2);
        }
        cout << dif / 2 << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}