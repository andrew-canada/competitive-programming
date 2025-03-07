#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
using ll = long long;

void solve()
{
    int N;
    cin >> N;
    vector<int> P(N);
    vector<int> E(N, 0);
    rep(i, N)
    {
        cin >> P[i];
        P[i]--;
        E[P[i]]++;
    }
    vector<int> D(N, 0);
    queue<int> Q;
    for (int i = 0; i < N; i++)
    {
        if (E[i] == 0)
            Q.push(i);
    }
    int an = 0;
    while (!Q.empty())
    {
        int p = Q.front();
        Q.pop();
        E[P[p]]--;
        D[P[p]] = max(D[P[p]], D[p] + 1);
        an = max(an, D[P[p]]);
        if (E[P[p]] == 0)
        {
            Q.push(P[p]);
        }
    }
    cout << an + 2 << "\n";
}

int main()
{

    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int T = 1;
    cin >> T;
    while (T--)
        solve();
}