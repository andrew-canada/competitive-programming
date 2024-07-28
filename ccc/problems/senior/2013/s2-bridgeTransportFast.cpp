#include <stdio.h>

int w, n;
int nt, tw;
int bridge[100005];

int main()
{
    scanf("%d%d", &w, &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &bridge[i]);
        tw += bridge[i];
        if (i > 3)
        {
            tw -= bridge[i - 4];
        }
        if (tw > w)
        {
            printf("%d", nt);
            return 0;
        }
        nt++;
    }
    printf("%d", nt);
}