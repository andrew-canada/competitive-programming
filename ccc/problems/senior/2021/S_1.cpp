#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e4;

int h[mxN + 1];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i <= n; i++)
    {
        scanf("%d", &h[i]);
    }
    int w;
    double ans = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &w);
        ans += (1.0 * h[i] + h[i + 1]) * w;
    }
    printf("%.1lf", ans / 2);
}