#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e5;

int car[mxN + 5];

int main()
{
    int w, n;
    scanf("%d%d", &w, &n);
    int totW = 0;
    bool found = false;
    for (int i = 4; i < n + 4; i++)
    {
        scanf("%d", &car[i]);
        if (found)
        {
            continue;
        }
        totW = totW + car[i] - car[i - 4];
        if (totW > w)
        {
            printf("%d\n", i - 4);
            found = true;
        }
    }
    if (!found)
    {
        printf("%d\n", n);
    }
}