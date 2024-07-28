#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define INF 0x3f3f3f3f

typedef long long ll;

const int mxN = 500, mxM = 1e3, M = 1e9 + 7;

set<int> s;

int main()
{
    int n;
    cin >> n;
    for (int i = 0, x; i < n; i++)
    {
        cin >> x;
        s.insert(x);
    }
    cout << s.size();
}