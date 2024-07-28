#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f
#define pb push_back

typedef long long ll;
typedef array<ll, 2> all;

const int mxN = 2e3;

int n;
vector<int> ans;
map<int, bool> vis;

void filter(double l = 0, double r = n)
{
    double len = (r - l) / 3;
    if (len <= 1)
    {
        for (int i = ceil(l); i <= floor(r); i++)
        {
            ans.pb(i);
        }
    }
    else
    {
        filter(l, l + len);
        filter(r - len, r);
    }
}

bool cantor(ll i)
{
    if (3 * i > n && 3 * i < 2 * n)
    {
        return false;
    }
    if (3 * i <= n)
    {
        i *= 3;
    }
    else
    {
        i = 3 * i - 2 * n;
    }
    if (vis[i])
    {
        return true;
    }
    vis[i] = true;
    return cantor(i);
}

int main()
{
    cin >> n;
    filter();
    for (int i : ans)
    {
        if (cantor(i))
        {
            cout << i << '\n';
        }
        vis.clear();
    }
}

/*
in:
12

out:
0
1
3
4
8
9
11
12
*/