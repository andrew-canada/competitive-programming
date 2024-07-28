#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define INF 2e18

const int mxN = 100;

int r[mxN + 1];

double gr(double n, int d)
{
    int f = pow(10, d);
    double n2 = n * (f * 10);
    n2 = floor(n2);
    n2 /= 10;
    n *= f;
    if (floor(n) + 0.5 == n2 && static_cast<int>(n) % 2 == 0)
    {
        n = floor(n);
    }
    else
    {
        n = round(n);
    }
    return n / f;
}

int main()
{
    int n;
    cin >> n;
    double ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> r[i];
        for (int j = 0; j < i; j++)
        {
            int c = min(r[i], r[j]) * (min(r[i], r[j]) - 1) / 2;
            if (r[j] > r[i])
            {
                c += (r[j] - r[i]) * r[i];
            }
            ans += (double)c / (r[i] * r[j]);
        }
    }
    cout << fixed << setprecision(6) << gr(ans, 7);
}