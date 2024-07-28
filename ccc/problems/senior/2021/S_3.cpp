#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mxN = 2e5;

int n;
int p[mxN + 1], w[mxN + 1], d[mxN + 1];

ll totTime(ll pos)
{
    ll time = 0;
    for (int i = 0; i < n; i++)
    {
        if (p[i] < pos - d[i])
        {
            time += (pos - d[i] - p[i]) * w[i];
        }
        else if (p[i] > pos + d[i])
        {
            time += (p[i] - pos - d[i]) * w[i];
        }
    }
    return time;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i] >> w[i] >> d[i];
    }
    ll low = 0, high = 1e9, mid;
    while (low < high)
    {
        mid = (low + high) / 2;
        if (totTime(mid) <= totTime(mid + 1))
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    cout << totTime(high);
}