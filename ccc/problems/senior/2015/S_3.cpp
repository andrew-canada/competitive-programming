#include <bits/stdc++.h>

using namespace std;

const int mxP = 1e5;

bool used[mxP + 1];

int main()
{
    int g, p;
    scanf("%d%d", &g, &p);
    int cur;
    int n = 0;
    int j;
    bool done = false;
    for (int i = 0; i < p; i++)
    {
        scanf("%d", &cur);
        if (done)
        {
            continue;
        }
        for (j = cur; j >= 1; j--)
        {
            if (!used[j])
            {
                used[j] = true;
                n++;
                break;
            }
        }
        if (j == 0)
        {
            done = true;
        }
    }
    printf("%d\n", n);
}

/*
4
6
2
2
3
3
4
4
*/