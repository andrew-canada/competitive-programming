#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e3, mxX = 1e6;

int grid[mxN + 1][mxN + 1], vis[mxX + 1];

int main()
{
    int r, c;
    cin >> r >> c;
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            cin >> grid[i][j];
        }
    }
    queue<int> q;
    q.push(grid[1][1]);
    int cur;
    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        for (int i = 1; i * i <= cur; i++)
        {
            if (cur % i == 0)
            {
                int j = cur / i;
                if (i == r && j == c || i == c && j == r)
                {
                    cout << "yes";
                    return 0;
                }
                if (i <= r && j <= c && !vis[grid[i][j]])
                {
                    q.push(grid[i][j]);
                    vis[grid[i][j]] = true;
                }
                if (i <= c && j <= r && !vis[grid[j][i]])
                {
                    q.push(grid[j][i]);
                    vis[grid[j][i]] = true;
                }
            }
        }
    }
    cout << "no";
}