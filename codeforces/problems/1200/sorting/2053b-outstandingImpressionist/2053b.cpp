#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f3f

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<int> l(2 * n + 1), r(2 * n + 1), sum(2 * n + 1), num(2 * n + 1);
        for (int i = 1; i <= 2 * n; i++)
        {
            sum[i] = 0, num[i] = 0;
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> l[i] >> r[i];
            if (l[i] == r[i])
            {
                sum[l[i]] = 1;
                num[l[i]]++;
            }
        }
        for (int i = 2; i <= 2 * n; i++)
        {
            sum[i] += sum[i - 1];
        }
        for (int i = 1; i <= n; i++)
        {
            if (l[i] == r[i])
            {
                cout << (num[l[i]] <= 1 ? "1" : "0");
            }
            else
            {
                cout << (sum[r[i]] - sum[l[i] - 1] < r[i] - l[i] + 1 ? "1" : "0");
            }
        }
        cout << '\n';
    }
}