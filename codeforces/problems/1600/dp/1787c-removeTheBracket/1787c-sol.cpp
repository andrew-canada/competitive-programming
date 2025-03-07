#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
long long f[N][2], x[N], y[N];
void get()
{
    int i, n, s, j;
    cin >> n >> s;
    for (i = 1; i <= n; i++)
    {
        cin >> j;
        if (i == 1 || i == n)
            x[i] = y[i] = j;
        else if (j <= s)
            x[i] = 0, y[i] = j;
        else
            x[i] = s, y[i] = j - s;
    }
    f[1][0] = f[1][1] = 0;
    for (i = 2; i <= n; i++)
    {
        f[i][0] = min(f[i - 1][0] + y[i - 1] * x[i], f[i - 1][1] + x[i - 1] * x[i]);
        f[i][1] = min(f[i - 1][0] + y[i - 1] * y[i], f[i - 1][1] + x[i - 1] * y[i]);
    }
    cout << f[n][0] << endl;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
        get();
    return 0;
}