#include <bits/stdc++.h>

using namespace std;

const int mxN = 2e5;

array<int, 2> arr[mxN + 1];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i][0] >> arr[i][1];
        }

        for (int i = 0; i < n; i++)
        {
            bool ok = true;
            set<int> s;
            for (int j = 0; j < n; j++)
            {
                if (i != j)
                {
                    if (arr[j][0] == arr[j][1] && arr[j][0] >= arr[i][0] && arr[j][0] <= arr[i][1])
                    {
                        s.insert(arr[j][0]);
                    }
                    if (!s.empty() && s.size() == arr[i][1] - arr[i][0] + 1 || !(arr[i][0] != arr[j][0] || arr[i][1] != arr[j][1] || arr[i][1] - arr[i][0] > 1))
                    {
                        ok = false;
                        break;
                    }
                }
            }
            cout << (ok == true ? 1 : 0);
        }
        cout << '\n';
    }
}