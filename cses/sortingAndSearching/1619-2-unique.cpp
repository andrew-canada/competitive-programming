#include <bits/stdc++.h>

using namespace std;

const int mxN = 2e5;

int a[mxN + 1], l[mxN + 1];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> l[i];
    }
    sort(a, a + n), sort(l, l + n);
    int i = 0, j = 0, ans = 0, cur = 0;
    while (i < n && j < n)
    {
        if (a[i] < l[j])
        {
            cur++;
            i++;
        }
        else
        {
            cur--;
            j++;
        }
        ans = max(ans, cur);
    }
    cout << ans;
}