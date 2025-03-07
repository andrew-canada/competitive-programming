#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    for (ll i = 1; i < 100000000; i++)
    {
        ll val = pow(2, i) + i * i;
        if (sqrt(val) == floor(sqrt(val)))
        {
            cout << i << '\n';
        }
    }
}