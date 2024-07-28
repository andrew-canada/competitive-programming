#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mxN = 20;

int arr[mxN + 1];

int main()
{
    int n;
    cin >> n;
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    ll ans = 0;
    for (int i = 0; i < (1 << n); i++)
    {
        ll cur = 0;
        for (int j = 0; j < n; j++)
        {
            if ((i >> j) & 1)
            {
                cur += arr[j];
            }
        }
        if (cur <= sum / 2)
        {
            ans = max(ans, cur);
        }
    }
    cout << sum - 2 * ans;
}