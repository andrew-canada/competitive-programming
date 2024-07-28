#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mxN = 2e5;

int arr[mxN + 1];

int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    ll l = *max_element(arr, arr + n), h = 2e14, mid;
    while (l < h)
    {
        mid = (l + h) / 2;
        ll div = 0, cs = 0;
        for (int i = 0; i < n; i++)
        {
            if (cs + arr[i] > mid)
            {
                cs = 0;
                div++;
            }
            cs += arr[i];
        }
        div++;
        if (div > k)
        {
            l = mid + 1;
        }
        else
        {
            h = mid;
        }
    }
    cout << h;
}