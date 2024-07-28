#include <stdio.h>
#include <queue>

using namespace std;

int wl, n;
int tw, nt;
int w;
queue<int> bridge;

int main()
{
    scanf("%d%d", &wl, &n);
    while (n--)
    {
        scanf("%d", &w);
        nt++;
        if (nt > 4)
        {
            tw -= bridge.front();
            bridge.pop();
        }
        tw += w;
        bridge.push(w);
        if (tw > wl)
        {
            printf("%d", nt - 1);
            return 0;
        }
    }
    printf("%d", nt);
}