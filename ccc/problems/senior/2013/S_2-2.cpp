#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mxN = 1e5;

int cars[mxN + 1];

int main()
{
    int w, n;
    cin >> w >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> cars[i];
    }
    ll weight = 0;
    int ans = -1;
    for (int i = 0; i < n; i++)
    {
        weight += cars[i];
        ans++;
        if (weight > w)
        {
            cout << ans;
            return 0;
        }
        if (i >= 3)
        {
            weight -= cars[i - 3];
        }
    }
    cout << n;
}