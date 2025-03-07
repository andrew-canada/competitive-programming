#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

typedef long long ll;

const int mxN = 1e5;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, num = 0;
    cin >> n;
    vector<int> x(n + 1), y(n + 1), c(n + 1), r(n + 1);

    for (int i = 1; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }
    for (int i = 1; i < n; i++)
    {
        if (c[x[i]] != c[y[i]])
        {
            r[x[i]]++;
            r[y[i]]++;
            num++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (r[i] == num)
        {
            cout << "YES\n"
                 << i;
            return 0;
        }
    }
    cout << "NO";
}