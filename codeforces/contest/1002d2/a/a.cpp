#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f3f
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        set<int> a, b;
        vector<int> v1(n), v2(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v1[i];
            a.insert(v1[i]);
        }
        for (int i = 0; i < n; i++)
        {
            cin >> v2[i];
            b.insert(v2[i]);
        }
        sort(v1.begin(), v1.end()), sort(v2.begin(), v2.end());
        int freq1 = 1, freq2 = 1;
        for (int i = 1; i < n; i++)
        {
            if (v1[i] != v1[i - 1])
            {
                break;
            }
            freq1++;
        }
        for (int i = 1; i < n; i++)
        {
            if (v2[i] != v2[i - 1])
            {
                break;
            }
            freq2++;
        }
        set<int> s({v1[0], v1[n - 1], v2[0], v2[n - 1]});
        if (b.size() >= 3 ||
            a.size() >= 3 ||
            b.size() == 2 && a.size() == 2 && (s.size() >= 3 || freq1 != freq2 || (freq1 > 1 && n - freq1 > 1)))
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}