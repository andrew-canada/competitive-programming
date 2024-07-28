#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e3;
const int rDir[4] = {1, 0, -1, 0}, cDir[4] = {0, 1, 0, -1};
const int dirCh[4] = {'D', 'R', 'U', 'L'};

int r, c, dirN[mxN + 1][mxN + 1];
string s[mxN + 1], path[mxN + 1];

int main()
{
    cin >> r >> c;
    int sr, sc, er, ec;
    for (int i = 0; i < r; i++)
    {
        cin >> s[i];
        for (int j = 0; j < c; j++)
        {
            if (s[i][j] == 'A')
            {
                sr = i, sc = j;
            }
            if (s[i][j] == 'B')
            {
                er = i, ec = j;
                s[i][j] = '.';
            }
        }
        path[i] = string(c, 0);
    }

    queue<array<int, 2>> q;
    q.push({sr, sc});
    array<int, 2> cur;
    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        if (cur[0] == er && cur[1] == ec)
        {
            break;
        }
        for (int i = 0; i < 4; i++)
        {
            int nr = cur[0] + rDir[i], nc = cur[1] + cDir[i];
            if (nr >= 0 && nr < r && nc >= 0 && nc < c && s[nr][nc] == '.')
            {
                q.push({nr, nc});
                s[nr][nc] = '#';
                dirN[nr][nc] = i;
                path[nr][nc] = dirCh[i];
            }
        }
    }

    if (path[er][ec])
    {
        cout << "YES\n";
        string ans;
        while (sr ^ er || sc ^ ec)
        {
            ans += path[er][ec];
            int d = dirN[er][ec] ^ 2;
            er += rDir[d], ec += cDir[d];
        }
        reverse(ans.begin(), ans.end());
        cout << ans.size() << '\n';
        cout << ans;
    }
    else
    {
        cout << "NO\n";
    }
}