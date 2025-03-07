#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Convert a string to a vector of ints with the least significant digit FIRST.
void convert(string s, vector<int> *result)
{
    for (int i = s.length() - 1; i >= 0; --i)
    {
        result->push_back((int)(s[i] - 48));
    }
}

// Shift in place by x (i.e., multiply by 10^x)
void shift(int x, vector<int> *v, vector<int> *result)
{
    for (int i = 0; i < x; ++i)
    {
        result->push_back(0);
    }
    for (int i = 0; i < v->size(); ++i)
    {
        result->push_back(v->at(i));
    }
}

void add(vector<int> *v1, vector<int> *v2, vector<int> *result)
{
    // Pad the smaller vector (if any)
    int l1 = v1->size();
    int l2 = v2->size();
    int max_l = max(l1, l2);
    if (l1 < max_l)
    {
        for (int i = 0; i < max_l - l1; ++i)
        {
            v1->push_back(0);
        }
    }
    else if (l2 < max_l)
    {
        for (int i = 0; i < max_l - l2; ++i)
        {
            v2->push_back(0);
        }
    }
    int carry = 0;
    for (int i = 0; i < max_l; ++i)
    {
        int res = v1->at(i) + v2->at(i) + carry;
        if (res > 9)
        {
            res %= 10;
            carry = 1;
        }
        else
        {
            carry = 0;
        }
        result->push_back(res);
    }
    if (carry)
    {
        result->push_back(carry);
    }
}

// Assumes v1 >= v2.
void subtract(vector<int> *v1, vector<int> *v2, vector<int> *result)
{
    int l1 = v1->size();
    int l2 = v2->size();
    if (l2 < l1)
    {
        for (int i = 0; i < l1 - l2; ++i)
        {
            v2->push_back(0);
        }
    }
    int carry = 0;
    for (int i = 0; i < l1; ++i)
    {
        int d1 = v1->at(i) - carry;
        int d2 = v2->at(i);
        if (d1 < d2)
        {
            carry = 1;
            d1 += 10;
        }
        else
        {
            carry = 0;
        }
        result->push_back(d1 - d2);
    }
    // There can't be a leftover carry as long as v1 >= v2.
    return;
}

void square(vector<int> *n, vector<int> *result)
{
    int l = n->size();
    // base case: default to built-in multiplication
    if (l <= 9)
    {
        ll v = 0;
        ll b = 1;
        for (int i = 0; i < l; ++i)
        {
            v += b * n->at(i);
            b *= 10;
        }
        ll v2 = v * v;
        while (v2 > 0)
        {
            result->push_back(v2 % 10);
            v2 /= 10;
        }
        if (result->size() == 0)
        {
            result->push_back(0);
        }
        return;
    }
    int first_size = l / 2;
    vector<int> first;
    vector<int> second;
    for (int i = 0; i < first_size; ++i)
    {
        first.push_back(n->at(i));
    }
    for (int i = first_size; i < l; ++i)
    {
        second.push_back(n->at(i));
    }
    // N = first + second * 10^(first_size)
    // N^2 = first^2 + second^2 * 10^(2*first_size) + 2*first*second*10^(first_size)
    // but 2*first*second = (first + second)^2 - first^2 - second^2
    // so N^2 = first^2 + second^2 * 10^(2*first_size) + [(first + second)^2 - first^2 - second^2] * 10^(first_size)
    vector<int> first_squared;
    square(&first, &first_squared);
    vector<int> second_squared;
    square(&second, &second_squared);
    vector<int> shifted_second_squared;
    shift(2 * first_size, &second_squared, &shifted_second_squared);
    vector<int> temp0;
    add(&first_squared, &shifted_second_squared, &temp0);
    vector<int> first_plus_second;
    add(&first, &second, &first_plus_second);
    vector<int> first_plus_second_squared;
    square(&first_plus_second, &first_plus_second_squared);
    vector<int> temp1;
    subtract(&first_plus_second_squared, &first_squared, &temp1);
    vector<int> temp2;
    subtract(&temp1, &second_squared, &temp2);
    vector<int> temp3;
    shift(first_size, &temp2, &temp3);
    add(&temp0, &temp3, result);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int unused_d;
    string n_str;
    cin >> unused_d >> n_str;
    vector<int> n_vec;
    convert(n_str, &n_vec);
    vector<int> result;
    square(&n_vec, &result);
    reverse(result.begin(), result.end());
    for (int i = 0; i < result.size(); ++i)
    {
        cout << result[i];
    }
    cout << '\n';
}