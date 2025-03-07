#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e6;
const int mxQ = 1e5;

int arr[mxQ + 1];
int minScore[mxN + 1];
int largestPrimeFactor[mxN + 1];

void sieve(int n)
{
    for (int i = 2; i <= n; ++i)
    {
        if (largestPrimeFactor[i] == 0)
        { // i is a prime number
            for (int j = i; j <= n; j += i)
            {
                largestPrimeFactor[j] = i;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> arr[i];
    }

    // Precompute largest prime factors up to N using the Sieve of Eratosthenes
    sieve(n);

    // Precompute the minimum scores for each subset size B
    for (int B = 2; B <= n; B++)
    {
        minScore[B] = INT_MAX;
        for (int i = 1; i <= n / B; i++)
        {
            minScore[B] = min(minScore[B], largestPrimeFactor[i * B]);
        }
    }

    // Answer each query
    for (int i = 0; i < q; i++)
    {
        int B = arr[i];
        cout << minScore[B] << " ";
    }
    cout << endl;

    return 0;
}