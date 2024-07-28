#include <bits/stdc++.h>

using namespace std;

unordered_map<int, bool> vis;
unordered_map<int, int> numMove;
bool occupied[9];

int bfs(string start, string end)
{
    queue<string> q;
    vis.clear();
    numMove.clear();
    vis[stoi(start)] = true;
    numMove[stoi(start)] = 0;
    string cur;
    q.push(start);
    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        if (cur == end)
        {
            return numMove[stoi(end)];
        }
        memset(occupied, 0, sizeof(occupied));
        for (int i = 0; i < cur.size(); i++)
        {
            int curPos = cur[i] - '0';
            if (occupied[curPos])
            {
                continue;
            }
            occupied[curPos] = true;
            if (curPos > 1)
            {
                auto it = cur.find(curPos - 1 + '0');
            }
            else if (curPos < cur.size())
            {
                auto it = cur.find(curPos + 1 + '0');
            }
        }
    }
    return -1;
}

int main()
{
    int n;
    while (true)
    {
        cin >> n;
        if (!n)
        {
            return 0;
        }
        int val;
        string startPos(n, 'a');
        string finalPos;
        for (int i = 0; i < n; i++)
        {
            cin >> val;
            startPos[val - 1] = i + 1 + '0';
            finalPos += to_string(i + 1);
        }
        int numMove = bfs(startPos, finalPos);
        if (numMove == -1)
        {
            cout << "IMPOSSIBLE";
        }
        else
        {
            cout << numMove;
        }
    }
}