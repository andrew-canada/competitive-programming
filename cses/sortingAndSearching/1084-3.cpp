#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define INF 0x3f3f3f3f

typedef long long ll;

const int mxN = 2e5, mxM = 1e3, M = 1e9 + 7;

int arr[mxN + 1], apt[mxN + 1];

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> apt[i];
    }
    sort(arr, arr + n), sort(apt, apt + m);
    int i = 0, j = 0, ans = 0;
    while (i < n && j < m)
    {
        if (abs(arr[i] - apt[j]) <= k)
        {
            ans++;
            i++, j++;
        }
        else if (arr[i] > apt[j])
        {
            j++;
        }
        else
        {
            i++;
        }
    }
    cout << ans;
}