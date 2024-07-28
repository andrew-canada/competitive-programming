#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define INF 0x3f3f3f3f

typedef long long ll;

const int mxN = 2e5, mxX = 1e6, M = 1e9 + 7;

// end, start, num
array<int, 3> arr[mxN];
int setn[mxN];

int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i][1] >> arr[i][0];
        arr[i][2] = i;
    }
    sort(arr, arr + n);
    int ans = 0;
    // end, pos
    set<array<int, 2>> s;
    for (int i = 0; i < n; i++)
    {
        auto it = s.lower_bound({arr[i][1] + 1});
        if (it == s.begin())
        {
            setn[arr[i][2]] = s.size();
        }
        else
        {
            --it;
            s.erase(it);
            setn[arr[i][2]] = (*it)[1];
        }
        if (s.size() < k)
        {
            ans++;
            s.insert({arr[i][0], setn[arr[i][2]]});
        }
    }
    cout << ans;
}