#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f

const int mxN = 2e3;

char arr[mxN + 1][mxN + 1];

int main()
{
    int r, c, pr, pc;
    cin >> r >> c >> pr >> pc;
    memset(arr, 'a', sizeof(arr));
    int npr = r - pr, npc = c - pc;
    if (pr == r && pc != c)
    {
        if (c & 1 ^ 1 && npc & 1)
        {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
        else
        {
            for (int i = 0; i < npc / 2; i++)
            {
                arr[0][i] = arr[0][c - 1 - i] = 'b';
            }
            if (npc & 1)
            {
                arr[0][c / 2] = 'b';
            }
        }
    }
    else if (pc == c && pr != r)
    {
        if (r & 1 ^ 1 && npr & 1)
        {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
        else
        {
            for (int i = 0; i < npr / 2; i++)
            {
                arr[i][0] = arr[r - 1 - i][0] = 'b';
            }
            if (npr & 1)
            {
                arr[r / 2][0] = 'b';
            }
        }
    }
    else if (pr != r && pc != c)
    {
        for (int i = 0; i < npc; i++)
        {
            arr[0][i] = 'b';
        }
        for (int i = 0; i < npr; i++)
        {
            arr[i][0] = 'b';
        }
        arr[0][0] = 'c';
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << arr[i][j];
        }
        cout << '\n';
    }
}

/*
4 5 1 2

2 2 2 1
*/