#include <stdio.h>
#include <unordered_map>
#include <string>

//#define LOCAL

int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif
    int cactiDimensions;
    int numEvents;
    int instructionNumber, row, column;
    std::unordered_map<int, int> rowVisitsMap;
    std::unordered_map<int, int> columnVisitsMap;
    std::unordered_map<std::string, int> pointVisitsMap;
    scanf("%d %d", &cactiDimensions, &numEvents);

    for (int i = 0; i < numEvents; i++)
    {
        scanf("%d %d %d", &instructionNumber, &row, &column);
        if (instructionNumber == 1)
        {
            rowVisitsMap[row] += 1;
            columnVisitsMap[column] += 1;
            pointVisitsMap[std::to_string(row) + "|" + std::to_string(column)] += 1;
        }
        else
        {
            printf("%d\n", (rowVisitsMap[row] + columnVisitsMap[column] -
                            pointVisitsMap[std::to_string(row) + "|" + std::to_string(column)]) %
                               2);
        }
    }
}