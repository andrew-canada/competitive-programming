#include <bits/stdc++.h>

using namespace std;

const int mxN = 2e5;

int w[mxN + 1];

int main()
{
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }
    sort(w, w + n);
    int i = 0, j = n - 1;
    int ans = 0;
    while (i <= j)
    {
        if (w[i] + w[j] <= x)
        {
            ans++, i++, j--;
        }
        else
        {
            ans++, j--;
        }
    }
    cout << ans;
}