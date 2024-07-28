#include <stdio.h>

int main()
{
    int s, r;
    scanf("%d%d", &s, &r);
    puts((100LL * s * s > 314LL * r * r) ? "SQUARE" : "CIRCLE");
    return 0;
}