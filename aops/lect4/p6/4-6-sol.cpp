#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MAX_N 20
ll dp[2][1 << MAX_N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int cards[m];
    string card_string;
    for (int i = 0; i < m; ++i)
    {
        cin >> card_string;
        int card = 0;
        for (char ch : card_string)
        {
            card += 1 << ((int)ch - 65);
        }
        cards[i] = card;
    }
    int possible_values = 1 << n;
    dp[0][0] = 1;
    for (int i = 1; i < possible_values; ++i)
    {
        dp[0][i] = 0;
    }
    int curr = 0;
    for (int i = 0; i < m; ++i)
    {
        // don't use this card
        for (int j = 0; j < possible_values; ++j)
        {
            dp[1 - curr][j] = dp[curr][j];
        }
        // do use this card
        for (int j = 0; j < possible_values; ++j)
        {
            dp[1 - curr][j ^ cards[i]] += dp[curr][j];
        }
        curr = 1 - curr;
    }
    cout << (dp[curr][0] - 1) << '\n';
}