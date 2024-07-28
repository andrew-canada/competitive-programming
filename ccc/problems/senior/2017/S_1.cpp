#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

const int mxN = 1e5;

int psa1[mxN + 1], psa2[mxN + 1];

int main()
{
    int n;
    scanf("%d", &n);
    REP(i, 0, n)
    {
        scanf("%d", &psa1[i]);
        psa1[i] += psa1[i - 1];
    }
    REP(i, 0, n)
    {
        scanf("%d", &psa2[i]);
        psa2[i] += psa2[i - 1];
    }
    for (int i = n; i > 0; i--)
    {
        if (psa1[i - 1] == psa2[i - 1])
        {
            printf("%d\n", i);
            return 0;
        }
    }
    printf("%d\n", 0);
}