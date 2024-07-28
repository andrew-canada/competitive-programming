#include <bits/stdc++.h>

using namespace std;

#define pb push_back

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> mat;

const int mxN = 2e5;
const ll INF = 5e13, NINF = -5e13, M = 1e9 + 7;

int arr[mxN + 1], med = -1;
multiset<int> low, high;

void fix()
{
    int ne = low.size() + high.size() + 1;
    if (low.size() < (ne - 1) / 2)
    {
        low.insert(med);
        med = *high.begin();
        high.erase(high.find(med));
    }
    if (low.size() > (ne - 1) / 2)
    {
        high.insert(med);
        med = *--low.end();
        low.erase(low.find(med));
    }
}

void add(int cur)
{
    if (med == -1)
    {
        med = cur;
        return;
    }
    cur >= med ? high.insert(cur) : low.insert(cur);
    fix();
}

void rem(int cur)
{
    if (cur == med)
    {
        med = *high.begin();
        high.erase(high.find(med));
    }
    else if (cur > med)
    {
        high.erase(high.find(cur));
    }
    else
    {
        low.erase(low.find(cur));
    }
    fix();
}

int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    if (k == 1)
    {
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        return 0;
    }
    for (int i = 0; i < k - 1; i++)
    {
        add(arr[i]);
    }
    for (int i = k - 1; i < n; i++)
    {
        add(arr[i]);
        cout << med << " ";
        rem(arr[i - k + 1]);
    }
}