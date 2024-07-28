#include <stdio.h>

//#define LOCAL

bool cactiParityMatrix[10000][10000];

int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif
    int cactiDimensions;
    int numEvents;
    int instructionNumber, row, column;
    scanf("%d %d", &cactiDimensions, &numEvents);

    for (int i = 1; i <= numEvents; i++)
    {
        scanf("%d %d %d", &instructionNumber, &row, &column);
        if (instructionNumber == 1)
        {
            for (int i = 1; i <= cactiDimensions; i++)
            {
                cactiParityMatrix[row][i] = !cactiParityMatrix[row][i];
                cactiParityMatrix[i][column] = !cactiParityMatrix[i][column];
            }
            cactiParityMatrix[row][column] = !cactiParityMatrix[row][column];
        }
        else
        {
            printf("%d\n", cactiParityMatrix[row][column]);
        }
    }
}