#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mxN = 2e5;

int main()
{
    int n;
    cin >> n;
    vector<int> s;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        int idx = lower_bound(s.begin(), s.end(), x) - s.begin();
        if (idx < s.size())
        {
            s[idx] = x;
        }
        else
        {
            s.push_back(x);
        }
    }
    cout << s.size() << "\n";
}