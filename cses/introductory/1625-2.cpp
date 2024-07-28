#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

string s;
int ans;
bool vis[7][7];

bool safe(int r, int c)
{
    return r >= 0 && r < 7 && c >= 0 && c < 7 && !vis[r][c];
}

void dfs(int r, int c, int steps)
{
    if (r == 6 && c == 0)
    {
        if (steps == 48)
        {
            ans++;
        }
        return;
    }
    vis[r][c] = true;
    if (s[steps] == '?' || s[steps] == 'L')
    {
        if (c && !vis[r][c - 1])
        {
            if (!(!safe(r, c - 2) && safe(r + 1, c - 1) && safe(r - 1, c - 1)))
            {
                dfs(r, c - 1, steps + 1);
            }
        }
    }
    if (s[steps] == '?' || s[steps] == 'R')
    {
        if (c < 6 && !vis[r][c + 1])
        {
            if (!(!safe(r, c + 2) && safe(r + 1, c + 1) && safe(r - 1, c + 1)))
            {
                dfs(r, c + 1, steps + 1);
            }
        }
    }
    if (s[steps] == '?' || s[steps] == 'U')
    {
        if (r && !vis[r - 1][c])
        {
            if (!(!safe(r - 2, c) && safe(r - 1, c - 1) && safe(r - 1, c + 1)))
            {
                dfs(r - 1, c, steps + 1);
            }
        }
    }
    if (s[steps] == '?' || s[steps] == 'D')
    {
        if (r < 6 && !vis[r + 1][c])
        {
            if (!(!safe(r + 2, c) && safe(r + 1, c - 1) && safe(r + 1, c + 1)))
            {
                dfs(r + 1, c, steps + 1);
            }
        }
    }
    vis[r][c] = false;
}

int main()
{
    cin >> s;
    dfs(0, 0, 0);
    cout << ans;
}