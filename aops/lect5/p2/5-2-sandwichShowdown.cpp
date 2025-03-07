#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mxN = 2e4;

int arr[mxN + 1];
array<ll, 2> current[mxN + 1], previous[mxN + 1];

int main()
{
    int n, c;
    cin >> n >> c;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i; j < n; j++)
        {
            if (i == j)
            {
                current[j] = {arr[i], 0};
                continue;
            }
            if (previous[j][1] + arr[i] > current[j - 1][1] + arr[j])
            {
                current[j] = {previous[j][1] + arr[i], previous[j][0]};
            }
            else
            {
                current[j] = {current[j - 1][1] + arr[j], current[j - 1][0]};
            }
        }
        swap(current, previous);
    }

    cout << previous[n - 1][c - 1];
}