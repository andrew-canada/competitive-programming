#include <bits/stdc++.h>

using namespace std;

bool isOn[26];
unordered_map<int, bool> vis;

int bfs(int start, int k)
{
    queue<array<int, 2>> q;
    array<int, 2> cur;
    q.push({start, 0});
    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        if (cur[0] == 0)
        {
            return cur[1];
        }
        if (vis[cur[0]])
        {
            continue;
        }
        vis[cur[0]] = true;
        for (int i = 0; i < k; i++)
        {
            if (cur[0] ^ (1 << i))
            {
                int nxt = cur[0] | (1 << i);
                int numOn = 1;
                for (int j = i + 1; j < k; j++)
                {
                    if (nxt & (1 << j))
                    {
                        numOn++;
                    }
                    else
                    {
                        break;
                    }
                }
                int left = i;
                for (int j = i - 1; j >= 0; j--)
                {
                    if (nxt & (1 << j))
                    {
                        numOn++;
                        left = j;
                    }
                    else
                    {
                        break;
                    }
                }
                if (numOn >= 4)
                {
                    nxt &= nxt + (1 << left);
                }
                q.push({nxt, cur[1] + 1});
            }
        }
    }
}

int main()
{
    int k;
    scanf("%d", &k);
    int start = 0;
    for (int i = 0; i < k; i++)
    {
        scanf("%d", &isOn[i]);
        start |= (isOn[i] << i);
    }
    printf("%d", bfs(start, k));
}