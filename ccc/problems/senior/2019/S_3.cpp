#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
#define INF 0x3f3f3f3f

int grid[3][3];
string s;
int totX;
int rowX[3], colX[3];

int main()
{
    ios_base::sync_with_stdio(false);
    REP(i, 0, 3)
    {
        REP(j, 0, 3)
        {
            cin >> s;
            if (s == "X")
            {
                grid[i][j] = INF;
                rowX[i]++;
                colX[j]++;
                totX++;
            }
            else
            {
                grid[i][j] = stoi(s);
            }
        }
    }
    bool change = false;
    while (totX > 0)
    {
        REP(i, 0, 3)
        {
            if (rowX[i] == 1)
            {
                change = true;
                rowX[i]--;
                totX--;
                if (grid[i][0] == INF)
                {
                    colX[0]--;
                    grid[i][0] = grid[i][1] - (grid[i][2] - grid[i][1]);
                }
                else if (grid[i][1] == INF)
                {
                    colX[1]--;
                    grid[i][1] = (grid[i][0] + grid[i][2]) / 2;
                }
                else
                {
                    colX[2]--;
                    grid[i][2] = grid[i][1] + (grid[i][1] - grid[i][0]);
                }
            }
            if (colX[i] == 1)
            {
                change = true;
                colX[i]--;
                totX--;
                if (grid[0][i] == INF)
                {
                    rowX[0]--;
                    grid[0][i] = grid[1][i] - (grid[2][i] - grid[1][i]);
                }
                else if (grid[1][i] == INF)
                {
                    rowX[1]--;
                    grid[1][i] = (grid[0][i] + grid[2][i]) / 2;
                }
                else
                {
                    rowX[2]--;
                    grid[2][i] = grid[1][i] + (grid[1][i] - grid[0][i]);
                }
            }
        }
        if (change)
        {
            change = false;
            continue;
        }
        if (grid[1][1] == INF)
        {
            grid[1][1] = 0;
            totX--;
            rowX[1]--, colX[1]--;
            continue;
        }
        if (grid[0][1] == INF)
        {
            grid[0][1] = 0;
            totX--;
            rowX[0]--, colX[1]--;
            continue;
        }
        if (grid[2][1] == INF)
        {
            grid[2][1] = 0;
            totX--;
            rowX[2]--, colX[1]--;
            continue;
        }
        if (grid[1][0] == INF)
        {
            grid[1][0] = 0;
            totX--;
            rowX[1]--, colX[0]--;
            continue;
        }
        if (grid[1][2] == INF)
        {
            grid[1][2] = 0;
            totX--;
            rowX[1]--, colX[2]--;
            continue;
        }
        if (grid[0][0] == INF)
        {
            grid[0][0] = 0;
            totX--;
            rowX[0]--, colX[0]--;
            continue;
        }
    }
    REP(i, 0, 3)
    {
        REP(j, 0, 3)
        {
            cout << grid[i][j] << " ";
        }
        cout << '\n';
    }
}