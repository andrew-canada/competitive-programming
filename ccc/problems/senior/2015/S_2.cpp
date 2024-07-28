#include <bits/stdc++.h>

using namespace std;

const int mxJ = 1e6;

char sz[mxJ + 1];

int main()
{
    int j, a;
    scanf("%d%d", &j, &a);
    for (int i = 1; i <= j; i++)
    {
        scanf(" %c", &sz[i]);
    }
    char curSz;
    int curN;
    int n = 0;
    for (int i = 0; i < a; i++)
    {
        scanf(" %c%d", &curSz, &curN);
        if (sz[curN] <= curSz)
        {
            n++;
            sz[curN] = 'a';
        }
    }
    printf("%d\n", n);
}