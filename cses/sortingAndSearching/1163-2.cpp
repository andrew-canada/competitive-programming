#include <bits/stdc++.h>

using namespace std;

#define pb push_back

const int mxN = 2e5;

int main()
{
    int x, n;
    cin >> x >> n;
    set<int> s;
    s.insert(0), s.insert(x);
    map<int, int> psg;
    psg[x] = 1;
    for (int i = 0; i < n; i++)
    {
        int pos;
        cin >> pos;
        auto it = s.lower_bound(pos);
        int r = *it;
        --it;
        int l = *it;
        psg[r - l]--;
        if (!psg[r - l])
        {
            psg.erase(r - l);
        }
        s.insert(pos);
        psg[r - pos]++, psg[pos - l]++;
        cout << (--psg.end())->first << " ";
    }
}