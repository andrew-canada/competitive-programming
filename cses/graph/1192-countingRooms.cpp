#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int n, m;
string grid[1005];
int rooms;

bool isValid(int r, int c)
{
    return r >= 0 && r < n && c >= 0 && c < m && grid[r][c] == '.';
}

void dfs(int r, int c)
{
    grid[r][c] = '#';
    if (isValid(r - 1, c))
    {
        dfs(r - 1, c);
    }
    if (isValid(r + 1, c))
    {
        dfs(r + 1, c);
    }
    if (isValid(r, c - 1))
    {
        dfs(r, c - 1);
    }
    if (isValid(r, c + 1))
    {
        dfs(r, c + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '.')
            {
                dfs(i, j);
                rooms++;
            }
        }
    }
    cout << rooms;
}