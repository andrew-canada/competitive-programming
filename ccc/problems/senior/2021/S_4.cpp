#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f
#define pb push_back

typedef long long ll;

const int mxN = 2e5;

vector<int> ww[mxN + 1];
int stn[mxN + 1], wt[mxN + 1], stnPos[mxN + 1];
bool vis[mxN + 1];
multiset<int> ans;

int main()
{
    freopen("S_4-2.in", "r", stdin);
    int n, w, d;
    cin >> n >> w >> d;
    int a, b;
    for (int i = 0; i < w; i++)
    {
        cin >> a >> b;
        ww[b].pb(a);
    }
    // only walk or train+walk
    memset(wt, INF, sizeof(wt));
    queue<int> q;
    q.push(n);
    vis[n] = true;
    wt[n] = 0;
    int cur;
    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        for (int i : ww[cur])
        {
            if (!vis[i])
            {
                q.push(i);
                vis[i] = true;
                wt[i] = wt[cur] + 1;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> stn[i];
        stnPos[stn[i]] = i - 1;
    }
    for (int i = 1; i <= n; i++)
    {
        ans.insert(wt[i] + stnPos[i]);
    }
    int stn1, stn2;
    for (int i = 0; i < d; i++)
    {
        cin >> a >> b;
        stn1 = stn[a], stn2 = stn[b];
        // erase old
        ans.erase(ans.find(stnPos[stn1] + wt[stn1])), ans.erase(ans.find(stnPos[stn2] + wt[stn2]));
        // swap
        swap(stn[a], stn[b]), swap(stnPos[stn1], stnPos[stn2]);
        // calculate new
        ans.insert(stnPos[stn1] + wt[stn1]), ans.insert(stnPos[stn2] + wt[stn2]);
        cout << *ans.begin() << '\n';
    }
}