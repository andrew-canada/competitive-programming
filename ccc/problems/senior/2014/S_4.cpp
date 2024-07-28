#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define INF 0x3f3f3f3f

ll tint[1005][1005];

int main()
{
    ll n, t;
    cin >> n >> t;
    int area = 0;
    int tx, ty, bx, by, tf;
    for (int i = 0; i < n; i++)
    {
        cin >> tx >> ty >> bx >> by >> tf;
        for (int i = tx; i <= bx; i++)
        {
            for (int j = ty; j <= by; j++)
            {
                tint[i][j] += tf;
            }
        }
    }
    for (int i = 0; i < 1001; i++)
    {
        for (int j = 0; j < 1001; j++)
        {
            if (tint[i][j] >= t)
            {
                area++;
            }
        }
    }
    cout << area;
}