#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define INF 2e18

typedef long long ll;

const int mxK = 100, mxN = 1e6;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x, ans = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            if (i & 1)
            {
                ans ^= x;
            }
        }
        cout << (ans ? "first" : "second") << '\n';
    }
}