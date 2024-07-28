#include <stdio.h>
#include <algorithm>

using namespace std;

typedef long long ll;

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

int n;
ll sz;
int c, v;

int main()
{
    scanf("%d", &n);
    REP(i, 0, n)
    {
        scanf("%d%d", &c, &v);
        if (v > 0)
        {
            sz += c;
        }
    }
    printf("%ld", sz);
}