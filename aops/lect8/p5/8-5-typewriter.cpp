#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int p[26], numStr[8], fallback[8][26];
double dp[2][22 * 8];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, t;
    string w;
    cin >> n >> w >> t;
    int wsz = w.size();

    // precompute
    for (int i = 0; i < wsz; i++)
    {
        numStr[i] = w[i] - 65;
    }

    // fallback
    for (int loc = 0; loc < wsz; loc++)
    {
        for (int letter = 0; letter < 26; letter++)
        {
            if (letter == numStr[loc])
            {
                continue;
            }
            for (int prefStart = 0; prefStart <= loc; prefStart++)
            {
                bool overlap = true;
                int fallbackPos = 0;
                while (prefStart + fallbackPos < loc)
                {
                    if (numStr[prefStart + fallbackPos] != numStr[fallbackPos])
                    {
                        overlap = false;
                        break;
                    }
                    fallbackPos++;
                }
                if (!overlap || letter != numStr[fallbackPos])
                {
                    continue;
                }
                fallback[loc][letter] = max(fallback[loc][letter], fallbackPos + 1);
            }
        }
    }

    // overlap
    int overlapLen = 0;
    for (int prefLen = 1; prefLen < wsz; prefLen++)
    {
        bool overlap = true;
        for (int i = 0; i < prefLen; i++)
        {
            if (w[i] != w[wsz - prefLen + i])
            {
                overlap = false;
                break;
            }
        }
        if (overlap)
        {
            overlapLen = prefLen;
        }
    }

    // calculate l
    double prob;
    for (int i = 0; i < 26; i++)
    {
        cin >> prob;
        p[i] = int(100 * prob);
    }
    ll num = 1, den = 1;
    for (int i = 0; i < wsz; i++)
    {
        num *= p[numStr[i]];
        den *= 100;
    }
    ll l = ceil((1.0 * n * den) / num) + wsz - 1;

    // type 1
    if (t == 1)
    {
        cout << l;
        exit(0);
    }

    // type 2
    int totalLetters = (n + 2) * wsz;
    bool state = 1;
    dp[0][0] = 1;
    for (int i = 0; i < l; i++)
    {
        memset(dp[state], 0, sizeof(dp[state]));
        for (int j = 0; j < totalLetters; j++)
        {
            if (dp[!state][j] == 0)
            {
                continue;
            }
            int next = numStr[j % wsz];

            // next letter is good
            if (j % wsz == wsz - 1)
            {
                // check overlap
                if (j + 1 + overlapLen < totalLetters)
                {
                    dp[state][j + 1 + overlapLen] += (dp[!state][j] * p[next]) / 100;
                }
            }
            else
            {
                if (j + 1 < totalLetters)
                {
                    dp[state][j + 1] += (dp[!state][j] * p[next]) / 100;
                }
            }

            // next letter is bad
            for (int k = 0; k < 26; k++)
            {
                if (k == next)
                {
                    continue;
                }
                int fallbackLoc = fallback[j % wsz][k];
                double add = (dp[!state][j] * p[k]) / 100;
                int idx = wsz * (j / wsz) + fallbackLoc;
                dp[state][idx] += add;
            }
        }
        state = !state;
    }

    double ans = 0;
    for (int i = 0; i < wsz; i++)
    {
        ans += dp[!state][n * wsz + i];
    }
    cout << fixed << setprecision(9) << ans;
}