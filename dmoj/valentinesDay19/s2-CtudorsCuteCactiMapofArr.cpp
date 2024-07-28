#include <stdio.h>
#include <map>
#include <vector>

#define max(n1, n2) ((n1 > n2) ? n1 : n2)
#define LOCAL

int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif
    int cactiDimensions;
    int numEvents;
    int instructionNumber, row, column;
    std::map<int, std::vector<bool>> rowParityMap;
    std::map<int, std::vector<bool>> columnParityMap;
    scanf("%d %d", &cactiDimensions, &numEvents);

    std::vector<bool> defaultValue = {};
    for (int i = 0; i < cactiDimensions; i++)
    {
        defaultValue.push_back(false);
    }

    for (int i = 0; i < cactiDimensions; i++)
    {
        rowParityMap.insert({i, defaultValue});
        columnParityMap.insert({i, defaultValue});
    }

    for (int i = 0; i < numEvents; i++)
    {
        scanf("%d %d %d", &instructionNumber, &row, &column);
        if (instructionNumber == 1)
        {
            for (int j = 0; j < cactiDimensions; j++)
            {
                rowParityMap.at(row).at(j) = !rowParityMap.at(row).at(j);
                columnParityMap.at(column).at(j) = !columnParityMap.at(column).at(j);
            }
        }
        else
        {
            printf("%d\n", rowParityMap.at(row).at(column));
        }
    }
}