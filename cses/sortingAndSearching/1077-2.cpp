#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mxN = 2e5;

int n, k;
int arr[mxN + 1];
array<int, 2> med = {-1};
set<array<int, 2>> low, high;
ll bs, ts;

void fix()
{
    ll te = low.size() + high.size() + 1;
    if (low.size() > (te - 1) / 2)
    {
        high.insert(med);
        ts += med[0];
        med = *--low.end();
        low.erase(med);
        bs -= med[0];
    }
    if (low.size() < (te - 1) / 2)
    {
        low.insert(med);
        bs += med[0];
        med = *high.begin();
        high.erase(med);
        ts -= med[0];
    }
}

void add(array<int, 2> cur)
{
    if (med[0] == -1)
    {
        med = cur;
        return;
    }
    if (cur >= med)
    {
        high.insert(cur);
        ts += cur[0];
    }
    else
    {
        low.insert(cur);
        bs += cur[0];
    }
    fix();
}

void rem(array<int, 2> cur)
{
    if (cur == med)
    {
        med = *high.begin();
        high.erase(med);
        ts -= med[0];
    }
    else if (cur > med)
    {
        high.erase(cur);
        ts -= cur[0];
    }
    else
    {
        low.erase(cur);
        bs -= cur[0];
    }
    fix();
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    if (k == 1)
    {
        for (int i = 0; i < n; i++)
        {
            cout << "0 ";
        }
        return 0;
    }
    for (int i = 0; i < k - 1; i++)
    {
        add({arr[i], i});
    }
    for (int i = k - 1; i < n; i++)
    {
        add({arr[i], i});
        cout << ts - (ll)high.size() * med[0] + (ll)low.size() * med[0] - bs << " ";
        rem({arr[i - k + 1], i - k + 1});
    }
}