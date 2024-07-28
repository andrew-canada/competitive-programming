#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mxN = 1e6;

int n;
int seat[3] = {0, 1, 2};
int psa[3][mxN + 1];
int ans = 1e9;

int calcPpl(int s0, int num, int g)
{
    return psa[g][s0 + num] - psa[g][s0];
}

void calcSwap(int a, int b, int c)
{
    int totA = psa[a][n], totB = psa[b][n];
    int numA, numB, numC, AiA, BiB, CiA, CiB, wA, wB;
    for (int i = 0; i <= n - totA - totB; i++)
    {
        numA = calcPpl(i, totA + totB, a);
        numB = calcPpl(i, totA + totB, b);
        numC = calcPpl(i, totA + totB, c);
        AiA = calcPpl(i, totA, a), BiB = calcPpl(i, totB, b);
        CiA = calcPpl(i, totA, c), CiB = calcPpl(i, totB, c);
        wA = totA - numA, wB = totB - numB;
        ans = min(ans, numC + min(totA - AiA - min(wA, CiA), totB - BiB - min(wB, CiB)));
    }
}

int main()
{
    string s;
    cin >> s;
    n = s.size();
    for (int i = 0; i <= 2; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            psa[i][j] = psa[i][j - 1] + (s[j - 1] - 'A' == i);
        }
    }
    do
    {
        calcSwap(seat[0], seat[1], seat[2]);
    } while (next_permutation(seat, seat + 3));
    cout << ans;
}