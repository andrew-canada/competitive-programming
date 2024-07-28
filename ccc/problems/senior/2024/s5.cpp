#include <bits/stdc++.h>

using namespace std;

const int mxN = 10;

double arr[mxN + 1][mxN + 1];

int main()
{
    int n;
    cin >> n;
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
            sum += arr[i][j];
        }
    }
    if (arr[0][0] == arr[0][1] == arr[1][0] == arr[1][1])
    {
        cout << 4;
        return 0;
    }
    bool two = false;
    for (int i = 0; i < n; i++)
    {
        if ((arr[i][0] + arr[i][1]) / 2 == (sum - arr[i][0] - arr[i][1]) / 2)
        {
            two = true;
            if (arr[i][0] == arr[i][1])
            {
                cout << 3;
                return 0;
            }
            // else
            // {
            //     cout << 2;
            //     return 0;
            // }
        }
        if ((arr[0][i] + arr[1][i]) / 2 == (sum - arr[0][i] - arr[1][i]) / 2)
        {
            two = true;
            if (arr[0][i] == arr[1][i])
            {
                cout << 3;
                return 0;
            }
            // else
            // {
            //     cout << 2;
            //     return 0;
            // }
        }
    }
    if (two)
    {
        cout << 2;
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == (sum - arr[i][j]) / 3)
            {
                cout << 2;
                return 0;
            }
        }
    }
    cout << 1;
}