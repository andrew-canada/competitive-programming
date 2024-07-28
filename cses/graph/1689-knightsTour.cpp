#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define INF 0x3f3f3f3f

typedef long long ll;

const int mxN = 20, mxX = 1e6, M = 1e9 + 7;

int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1}, dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int vis[8][8];

bool free(int nx, int ny)
{
    return nx >= 0 && nx < 8 && ny >= 0 && ny < 8 && !vis[nx][ny];
}

int deg(array<int, 2> ar)
{
    int d = 0;
    for (int i = 0; i < 8; i++)
    {
        d += free(ar[0] + dx[i], ar[1] + dy[i]);
    }
    return d;
}

void dfs(int x, int y, int nm)
{
    vis[x][y] = nm;
    if (nm == 64)
    {
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                cout << vis[i][j] << " ";
            }
            cout << '\n';
        }
        exit(0);
    }
    vector<array<int, 2>> p;
    for (int i = 0; i < 8; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (free(nx, ny))
        {
            p.pb({nx, ny});
        }
    }
    sort(p.begin(), p.end(), [](const array<int, 2> &a, array<int, 2> &b)
         { return deg(a) < deg(b); });
    for (array<int, 2> b : p)
    {
        dfs(b[0], b[1], nm + 1);
    }
    vis[x][y] = false;
}

int main()
{
    int x, y;
    cin >> y >> x, --y, --x;
    dfs(x, y, 1);
}