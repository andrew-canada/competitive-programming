#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mxN = 2e5;

struct task
{
    int dur, dl;
    bool operator<(const task &t)
    {
        return dur == t.dur ? dl > t.dl : dur < t.dur;
    }
};

task arr[mxN + 1];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].dur >> arr[i].dl;
    }
    sort(arr, arr + n);
    ll ans = 0, ct = 0;
    for (int i = 0; i < n; i++)
    {
        ct += arr[i].dur;
        ans += arr[i].dl - ct;
    }
    cout << ans;
}