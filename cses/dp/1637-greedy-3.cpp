#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define INF 0x3f3f3f3f

typedef long long ll;

const int mxN = 2e5, mxX = 1e6, M = 1e9 + 7;

int main()
{
    int n, ans = 0;
    cin >> n;
    while (n)
    {
        string s = to_string(n);
        int md = 0;
        for (char c : s)
        {
            md = max(md, c - '0');
        }
        n -= md;
        ans++;
    }
    cout << ans;
}