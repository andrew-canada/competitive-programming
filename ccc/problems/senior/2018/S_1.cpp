#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
#define INF 0x3f3f3f3f

int vil[105];

int main()
{
    int n;
    scanf("%d", &n);
    REP(i, 0, n)
    {
        scanf("%d", &vil[i]);
    }
    sort(vil, vil + n);
    double minSz = INF;
    REP(i, 1, n - 1)
    {
        minSz = min(minSz, (1.0 * vil[i + 1] + vil[i]) / 2 - (1.0 * vil[i] + vil[i - 1]) / 2);
    }
    printf("%.1lf", minSz);
}