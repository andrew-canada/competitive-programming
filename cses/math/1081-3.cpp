#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mxX = 1e6, M = 1e9 + 7;

int freq[mxX + 1];

int main()
{
    int n;
    cin >> n;
    for (int i = 0, x; i < n; i++)
    {
        cin >> x;
        freq[x]++;
    }
    for (int i = mxX; i >= 1; i--)
    {
        int cur = 0;
        for (int j = i; j <= mxX; j += i)
        {
            cur += freq[j];
        }
        if (cur >= 2)
        {
            cout << i << '\n';
            break;
        }
    }
}