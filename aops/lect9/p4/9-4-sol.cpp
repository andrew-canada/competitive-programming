#include <bits/stdc++.h>
using namespace std;

int biggest_factor[1000001];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n;
    cin >> q;

    for (int i = 1; i <= n; i++)
    {
        for (int v = i * 2; v <= n; v += i)
        {
            biggest_factor[v] = i;
        }
    }
    sort(biggest_factor + 1, biggest_factor + n + 1);

    int b;
    for (int query = 0; query < q; query++)
    {
        cin >> b;
        cout << biggest_factor[b];
        if (query + 1 < q)
        {
            cout << " ";
        }
    }
}