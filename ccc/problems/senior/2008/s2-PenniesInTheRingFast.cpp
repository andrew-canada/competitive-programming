#include <stdio.h>
#include <math.h>

int main()
{
    int radius = 0;
    int penniesInside = 0;
    scanf("%d", &radius);
    while (radius != 0)
    {
        for (int i = 1; i < radius; i++)
        {
            penniesInside += sqrt(radius * radius - i * i);
        }
        penniesInside += radius;
        printf("%d\n", 4 * penniesInside + 1);
        penniesInside = 0;
        scanf("%d", &radius);
    }
}