#include <bits/stdc++.h>

using namespace std;

// Function to calculate power in O(log n) time
int power(int x, unsigned int y, unsigned int m)
{
    if (y == 0)
        return 1;
    int p = power(x, y / 2, m) % m;
    p = (p * p) % m;
    return (y % 2 == 0) ? p : (x * p) % m;
}

// Function to find modular inverse of a under modulo m
// using binary exponentiation.
int modInverse(int a, int m)
{
    return power(a, m - 2, m);
}

int main()
{
    printf("%d\n", modInverse(17, 43));
}