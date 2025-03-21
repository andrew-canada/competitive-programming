#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f3f
#define pb push_back

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    vector<int> freq(26, 0);
    for (char c : s)
    {
        freq[c - 'a']++;
    }
    cout << max(n % 2, 2 * *max_element(freq.begin(), freq.end()) - n) << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}