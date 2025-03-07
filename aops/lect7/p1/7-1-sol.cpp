#include <bits/stdc++.h>
using namespace std;

#define MAX_N 524288
int arr[MAX_N];
int new_arr[MAX_N];
typedef long long ll;

ll merge(const int left_start, const int right_start, const int right_end)
{
    int left = left_start;
    const int left_end = right_start;
    int right = right_start;
    int output = left_start;
    ll invs = 0;
    while ((left < left_end) && (right < right_end))
    {
        if (arr[left] < arr[right])
        {
            new_arr[output] = arr[left];
            left++;
        }
        else
        {
            new_arr[output] = arr[right];
            right++;
            // Everything from here onward in the left list is an inversion.
            invs += (left_end - left);
        }
        output++;
    }
    if (left == left_end)
    {
        while (right < right_end)
        {
            new_arr[output] = arr[right];
            right++;
            output++;
        }
    }
    else
    {
        while (left < left_end)
        {
            new_arr[output] = arr[left];
            left++;
            output++;
        }
    }
    // This is wasteful, but here just for simplicity.
    for (int i = left_start; i < right_end; ++i)
    {
        arr[i] = new_arr[i];
    }
    return invs;
}

ll merge_sort(int start, int stop)
{ // stop is exclusive
    ll invs = 0;
    if (start + 1 == stop)
    {
        return invs; // base case, no inversions possible for a single element
    }
    int mid = (start + stop) / 2;
    invs += merge_sort(start, mid);
    invs += merge_sort(mid, stop);
    invs += merge(start, mid, stop);
    return invs;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    // find smallest power of 2 that is equal to or larger than n
    int fake_n = 1;
    while (fake_n < n)
    {
        fake_n <<= 1;
    }
    // pad with fake values that are all larger than n
    for (int i = n; i < fake_n; ++i)
    {
        arr[i] = i + 1;
    }
    ll possible_inversions = ((ll)n * (ll)(n - 1)) / 2;
    cout << possible_inversions - merge_sort(0, fake_n) << '\n';
}