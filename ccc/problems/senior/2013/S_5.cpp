#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int cost = 0;
    while (n > 1)
    {
        if (n % 2 == 0)
        {
            n /= 2;
            cost++;
        }
        else
        {
            int a = n / 2;
            if (a % 2 == 0)
            {
                a++;
            }
            while (a >= 1)
            {
                int prevN = n - a;
                if (prevN % a == 0)
                {
                    int b = prevN / a;
                    cost += b;
                    n = prevN;
                    break;
                }
                a -= 2;
            }
        }
    }
    cout << cost;
}