#include <bits/stdc++.h>

using namespace std;

#define pb push_back

const int mxN = 2e5;

array<int, 3> arr[mxN + 1];
int ans[mxN + 1];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i][1] >> arr[i][0];
        arr[i][2] = i;
    }
    sort(arr, arr + n);
    set<array<int, 2>> s;
    for (int i = 0; i < n; i++)
    {
        auto it = s.lower_bound({arr[i][1]});
        if (it == s.begin())
        {
            ans[arr[i][2]] = s.size();
        }
        else
        {
            --it;
            ans[arr[i][2]] = (*it)[1];
            s.erase(it);
        }
        s.insert({arr[i][0], ans[arr[i][2]]});
    }
    cout << s.size() << '\n';
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] + 1 << " ";
    }
}