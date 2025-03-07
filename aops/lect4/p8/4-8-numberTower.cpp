#include <bits/stdc++.h>
using namespace std;

const int MAX_H = 50;
const int MAX_V = 50;

int H, V, T;
map<vector<vector<int>>, int> memo;

bool isValid(const vector<vector<int>> &grid, int r, int c, int n)
{
    int count = 0;
    if (r > 0 && grid[r - 1][c] == n)
        count++;
    if (r < H - 1 && grid[r + 1][c] == n)
        count++;
    if (c > 0 && grid[r][c - 1] == n)
        count++;
    if (c < V - 1 && grid[r][c + 1] == n)
        count++;
    if (c == 0 && grid[r][V - 1] == n)
        count++;
    if (c == V - 1 && grid[r][0] == n)
        count++;
    return count == n;
}

int countWays(vector<vector<int>> &grid, int r, int c)
{
    if (r == H)
        return 1;
    if (c == V)
        return countWays(grid, r + 1, 0);
    if (memo.count(grid))
        return memo[grid];

    int ways = 0;
    for (int n = 1; n <= 4; n++)
    {
        grid[r][c] = n;
        if (isValid(grid, r, c, n))
        {
            ways += countWays(grid, r, c + 1);
        }
        grid[r][c] = 0;
    }

    return memo[grid] = ways;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> H >> V >> T;
    vector<vector<int>> grid(H, vector<int>(V, 0));

    int result = countWays(grid, 0, 0);

    if (T == 1)
    {
        set<vector<vector<int>>> uniqueConfigs;
        for (int i = 0; i < V; i++)
        {
            vector<vector<int>> rotatedGrid(H, vector<int>(V, 0));
            for (int r = 0; r < H; r++)
            {
                for (int c = 0; c < V; c++)
                {
                    rotatedGrid[r][(c + i) % V] = grid[r][c];
                }
            }
            uniqueConfigs.insert(rotatedGrid);
        }
        result = uniqueConfigs.size();
    }

    cout << result << '\n';

    return 0;
}