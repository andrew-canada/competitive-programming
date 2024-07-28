#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mxN = 2e5;

int arr[mxN + 1];
int idx[mxN + 1];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    arr[0] = -1;
    idx[1] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (arr[i] > arr[i - 1])
        {
            cout << i - 1 << " ";
            idx[i] = i - 1;
        }
        else
        {
            int cur = i - 1;
            while (arr[idx[cur]] >= arr[i])
            {
                cur = idx[cur];
            }
            if (cur == 0)
            {
                cout << "0 ";
                idx[i] = 0;
            }
            else
            {
                cout << idx[cur] << " ";
                idx[i] = idx[cur];
            }
        }
    }
}