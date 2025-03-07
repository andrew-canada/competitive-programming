#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f

typedef long long ll;

const int mxS = 1e5;

int arr[101], dp[mxS + 1];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = mxS; j >= arr[i]; j--)
        {
            dp[j] |= dp[j - arr[i]];
        }
    }

    vector<int> ans;
    for (int i = 1; i <= mxS; i++)
    {
        if (dp[i])
        {
            ans.push_back(i);
        }
    }
    cout << ans.size() << '\n';
    for (int i : ans)
    {
        cout << i << " ";
    }
}