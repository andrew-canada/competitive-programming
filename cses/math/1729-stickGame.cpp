#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define INF 2e18

const int mxK = 100, mxN = 1e6;

int s[mxK + 1];
bool ans[mxN + 1];

int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> s[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            if (i >= s[j])
            {
                ans[i] |= !ans[i - s[j]];
            }
        }
        cout << (ans[i] ? 'W' : 'L');
    }
}