#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mxN = 2e5;

int arr[mxN + 1];

int main()
{
    int n, t;
    cin >> n >> t;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    ll low = 0, high = 1e18;
    ll mid = 0;
    ll ans = 0;
    while (low <= high)
    {
        mid = (low + high) / 2;
        ll ct = 0;
        for (int i = 0; i < n; i++)
        {
            ct += mid / arr[i];
            if (ct >= t)
            {
                break;
            }
        }
        if (ct >= t)
        {
            high = mid - 1;
            ans = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    cout << ans;
}