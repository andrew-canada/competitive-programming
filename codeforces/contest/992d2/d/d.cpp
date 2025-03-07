#include <bits/stdc++.h>
using namespace std;

const int mxN = 2e5;

vector<int> adjL[mxN + 1];
bool prime[2 * mxN + 1];

void sieve(int n)
{
    fill(prime, prime + n + 1, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i * i <= n; ++i)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                prime[j] = false;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    sieve(2 * mxN);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i)
        {
            adjL[i].clear();
        }
        for (int i = 0; i < n - 1; ++i)
        {
            int u, v;
            cin >> u >> v;
            adjL[u].push_back(v);
            adjL[v].push_back(u);
        }

        vector<int> a(n + 1, 0);
        vector<bool> used(2 * n + 1, false);
        queue<int> q;
        q.push(1);
        a[1] = 1;
        used[1] = true;

        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            int val = a[u];
            for (int v : adjL[u])
            {
                if (a[v] == 0)
                {
                    for (int i = 1; i <= 2 * n; ++i)
                    {
                        if (!used[i] && !prime[abs(val - i)])
                        {
                            a[v] = i;
                            used[i] = true;
                            q.push(v);
                            break;
                        }
                    }
                }
            }
        }

        bool valid = true;
        for (int i = 1; i <= n; ++i)
        {
            if (a[i] == 0)
            {
                valid = false;
                break;
            }
        }

        if (valid)
        {
            for (int i = 1; i <= n; ++i)
            {
                cout << a[i] << " ";
            }
            cout << '\n';
        }
        else
        {
            cout << "-1\n";
        }
    }

    return 0;
}