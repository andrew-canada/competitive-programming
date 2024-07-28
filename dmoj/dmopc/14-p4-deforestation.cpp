#include <stdio.h>

// #define LOCAL
#define REP(i, a, b) for (int i = int(a); i <= int(b - 1); i++)

int n;
int q;
int b, e;
int w[1000005];

int main()
{
#ifdef LOCAL
    freopen("14p4.in", "r", stdin);
#endif
    scanf("%d", &n);
    REP(i, 0, n)
    {
        scanf("%d", &w[i]);
        w[i] += w[i - 1];
    }
    scanf("%d", &q);
    REP(i, 0, q)
    {
        scanf("%d %d", &b, &e);
        printf("%d\n", w[e] - w[b - 1]);
    }
}