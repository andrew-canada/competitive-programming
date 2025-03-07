#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cctype>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <sstream>
#include <iterator>
#include <map>
#include <unordered_set>
#include <bitset>
#include <utility>
#include <iomanip>
// #include <bits/stdc++.h>
#define FAST                 \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
using namespace std;
long long calcsum(long long n)
{
    long long sum = 0;
    while (n != 0)
    {
        long long temp = n % 10;
        n /= 10;
        sum += temp;
    }
    return sum;
}

int main()
{
    FAST long long n, s;
    cin >> n >> s;
    long long l = 0, r = n, mid = 0;
    long long ans = 0;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        if ((mid - (calcsum(mid))) >= s)
        {
            if (ans == 0)
                ans = mid;
            else
                ans = min(ans, mid);
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    if (ans != 0)
        cout << (n + 1) - ans;
    else
        cout << 0;
}
