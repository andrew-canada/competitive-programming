#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define INF 0x3f3f3f3f

int triangle[3005][3005];
int n, k;
ll ans;

void getMax(int curK);

int main()
{
    scanf("%d%d", &n, &k);
    REP(i, 0, n - 1)
    {
        REP(j, 0, i)
        {
            scanf("%d", &triangle[i][j]);
        }
    }
    getMax(k);
    REP(i, 0, n - k)
    {
        REP(j, 0, i)
        {
            ans += triangle[i][j];
        }
    }
    printf("%lld", ans);
}

void getMax(int curK)
{
    int nxtK;
    if (curK == 1)
    {
        return;
    }
    else if (curK == 2)
    {
        nxtK = 1;
    }
    else
    {
        nxtK = ceil(curK * 2.0 / 3.0);
    }
    getMax(nxtK);
    REP(i, 0, n - curK)
    {
        REP(j, 0, i)
        {
            triangle[i][j] = max({triangle[i][j], triangle[i + curK - nxtK][j], triangle[i + curK - nxtK][j + curK - nxtK]});
        }
    }
}