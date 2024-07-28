#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
#define INF 0x3f3f3f3f
#define pb push_back

int n;
unordered_map<ll, ll> numTree;

void findTree(int w);

int main()
{
    scanf("%d", &n);
    numTree[1] = 1, numTree[2] = 1;
    if (n > 2)
    {
        findTree(n);
    }
    printf("%lld", numTree[n]);
}

void findTree(int w)
{
    ll nt = 0;
    ll nst = w;
    ll stw;
    ll nst1;
    while (nst > 1)
    {
        stw = w / nst;
        nst1 = w / (stw + 1);
        if (!numTree[stw])
        {
            findTree(stw);
        }
        nt += numTree[stw] * (nst - nst1);
        nst = nst1;
    }
    numTree[w] = nt;
}