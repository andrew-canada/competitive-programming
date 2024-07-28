#include <bits/stdc++.h>

using namespace std;

stack<int> s;

int main()
{
    int k;
    scanf("%d", &k);
    int n;
    while (k--)
    {
        scanf("%d", &n);
        if (n)
        {
            s.push(n);
        }
        else
        {
            s.pop();
        }
    }
    int sum = 0;
    while (!s.empty())
    {
        sum += s.top();
        s.pop();
    }
    printf("%d\n", sum);
}