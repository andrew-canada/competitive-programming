#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f

const int mxN = 5e3;

int arr[mxN + 1];
int md[mxN + 1];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    memset(md, INF, sizeof(md));
    for (int i = 0; i < n; i++)
    {
        int cur = 0;
        for (int j = 0; i + j < n && i - j >= 0; j++)
        {
            cur += abs(arr[i + j] - arr[i - j]);
            md[2 * j + 1] = min(md[2 * j + 1], cur);
        }
        cur = 0;
        for (int j = 0; i + j + 1 < n && i - j >= 0; j++)
        {
            cur += abs(arr[i + j + 1] - arr[i - j]);
            md[2 * (j + 1)] = min(md[2 * (j + 1)], cur);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << md[i] << " ";
    }
}

/*
in:
7
3 1 4 1 5 9 2

out:
0 2 0 5 2 10 10
*/