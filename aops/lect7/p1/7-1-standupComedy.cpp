#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mxN = 5e5;

int seats[mxN + 1];

ll merge(int l, int mid, int r)
{
    int ls = mid - l + 1, rs = r - mid;
    ll pairs = 0;
    vector<int> la(ls), ra(rs);
    for (int i = 0; i < ls; i++)
    {
        la[i] = seats[l + i];
    }
    for (int i = 0; i < rs; i++)
    {
        ra[i] = seats[mid + 1 + i];
    }
    int li = 0, ri = 0, si = l;
    while (li < ls && ri < rs)
    {
        if (la[li] < ra[ri])
        {
            seats[si] = la[li];
            li++;
        }
        else
        {
            seats[si] = ra[ri];
            ri++;
            pairs += ls - li;
        }
        si++;
    }
    while (li < ls)
    {
        seats[si] = la[li];
        si++, li++;
    }
    while (ri < rs)
    {
        seats[si] = ra[ri];
        si++, ri++;
    }
    return pairs;
}

ll mergeSort(int l, int r)
{
    if (l >= r)
    {
        return 0;
    }
    int mid = (l + r) / 2;
    ll lp = mergeSort(l, mid), rp = mergeSort(mid + 1, r);
    ll mp = merge(l, mid, r);
    return lp + rp + mp;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> seats[i];
    }
    cout << n * (n - 1) / 2 - mergeSort(0, n - 1);
}

/*
order: sorting
ranges: tree
*/