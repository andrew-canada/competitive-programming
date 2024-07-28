#include <bits/stdc++.h>

using namespace std;

#define pb push_back

typedef long long ll;

const int mxN = 2e5;

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
    sort(arr, arr + n);
    if (2 * arr[n - 2] < arr[n - 1])
    {
        cout << arr[n - 1] * 2;
    }
    else
    {
        cout << sum;
    }
}