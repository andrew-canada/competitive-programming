#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define INF 0x3f3f3f3f

typedef long long ll;

const int mxN = 1e2, mxX = 1e6, M = 1e9 + 7;

double prob[mxN + 1];

int main()
{
    int n, k;
    cin >> n >> k;
    double ans = 0;
    for (int i = 1; i <= k; i++)
    {
        prob[i] = 1;
        for (int j = 0; j < n; j++)
        {
            prob[i] *= 1.0 * i / k;
        }
    }
    for (int i = k; i > 0; i--)
    {
        prob[i] -= prob[i - 1];
        ans += i * prob[i];
    }
    cout << fixed << setprecision(6) << ans;
}