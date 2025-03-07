#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, t;
    string w;
    cin >> n >> w >> t;
    int lw = w.length();
    // convert the letters into indices from 0 to 25
    int letter_indices[lw];
    for (int i = 0; i < lw; ++i)
    {
        letter_indices[i] = (int)w[i] - 65;
    }
    // Do some precomputation here to build a "fallback table":
    // If we get a letter other than what we want, how far back do we get sent?
    //   e.g. if the target word is ABACUS and we type ABAB, we should be sent
    //   back as if we just finished AB, not to the beginning of the word
    // The following means: we were just expecting the letter at position X in
    //   the word and instead saw letter Y (we expected some other letter)
    int fall_back_to[lw][26];
    for (int where_in_word = 0; where_in_word < lw; ++where_in_word)
    {
        for (int unwanted_letter = 0; unwanted_letter < 26; ++unwanted_letter)
        {
            fall_back_to[where_in_word][unwanted_letter] = 0;
            if (unwanted_letter == letter_indices[where_in_word])
            {
                // this is the actually wanted letter, so ignore it. We will never
                // try to look this up in the table, so it's fine if there's garbage
                // here
                continue;
            }
            // find common prefix in kind of an inefficient way, but it's fine since
            //   we're only doing it once
            for (int possible_start = 0; possible_start <= where_in_word; ++possible_start)
            {
                bool ok = true;
                int i = 0;
                while (possible_start + i < where_in_word)
                {
                    if (letter_indices[possible_start + i] != letter_indices[i])
                    {
                        ok = false;
                        break;
                    }
                    i++;
                }
                if ((!ok) || (unwanted_letter != letter_indices[i]))
                {
                    continue;
                }
                fall_back_to[where_in_word][unwanted_letter] = max(fall_back_to[where_in_word][unwanted_letter], i + 1);
            }
        }
    }
    // Also calculate the max amount of self-overlap among a prefix and suffix.
    int self_overlap = 0;
    for (int i = 1; i < lw; ++i)
    {
        bool ok = true;
        for (int j = 0; j < i; ++j)
        {
            if (w[j] != w[lw - i + j])
            {
                ok = false;
                break;
            }
        }
        if (ok)
        {
            self_overlap = i;
        }
    }
    // OK, now we can get started!
    int numerators[26];
    double p;
    for (int i = 0; i < 26; ++i)
    {
        cin >> p;
        numerators[i] = (int)(100 * p);
    }
    // expected instances in l letters = (l - len(W) + 1) * P(word)
    // so we want (l - len(W) + 1) * P(word) >= N
    // l >= (N / P(word)) + len(W) - 1
    ll p_word_numerator = 1;
    ll p_word_denominator = 1;
    for (int i = 0; i < lw; ++i)
    {
        p_word_numerator *= numerators[letter_indices[i]];
        p_word_denominator *= 100;
    }
    ll l = ceil((((double)n * p_word_denominator) / p_word_numerator)) + lw - 1;
    // for cases of type 1, this is all we need to do!
    if (t == 1)
    {
        cout << l << '\n';
        exit(0);
    }
    // otherwise, go on to use l in a type 2 case
    // first axis = old/new dp
    // second axis = how many total letters we've gotten (we want n * lw)
    int dim = (n + 2) * lw; // the n + 2 is just for extra padding
    double dp[2][dim];
    dp[0][0] = 1.0; // starting state
    for (int j = 1; j < dim; ++j)
    {
        dp[0][j] = 0.0;
    }
    int which_next = 1;
    // go for exactly l rounds
    for (int i = 0; i < l; ++i)
    {
        // clean new dp
        for (int j = 0; j < dim; ++j)
        {
            dp[which_next][j] = 0.0;
        }
        for (int j = 0; j < dim; ++j)
        {
            if (dp[1 - which_next][j] == 0.0)
            {
                continue;
            }
            int next_wanted_letter = letter_indices[j % lw];
            // case 1: next letter is what we want, and advances us
            if (j % lw == lw - 1)
            { // last letter we need to complete an instance
                // so we may have a head start on the next word...
                if (j + 1 + self_overlap < dim)
                {
                    dp[which_next][j + 1 + self_overlap] += ((dp[1 - which_next][j] * numerators[next_wanted_letter]) / 100);
                }
            }
            else
            {
                if (j + 1 < dim)
                {
                    dp[which_next][j + 1] += ((dp[1 - which_next][j] * numerators[next_wanted_letter]) / 100);
                }
            }
            // case 2: next letter resets us back a ways, usually to the beginning
            for (int k = 0; k < 26; ++k)
            {
                if (k == next_wanted_letter)
                {
                    continue;
                }
                int fbt = fall_back_to[j % lw][k];
                double to_add = (dp[1 - which_next][j] * numerators[k]) / 100;
                int idx = (lw * (j / lw)) + fbt;
                dp[which_next][idx] += to_add;
            }
        }
        which_next = 1 - which_next;
    }
    double answer = 0.0;
    // Make sure to count all states that count as having completed exactly n
    // copies of the word, even those that have made some incomplete headway on
    // the next word!
    for (int j = 0; j < lw; ++j)
    {
        answer += dp[1 - which_next][n * lw + j];
    }
    cout << fixed << setprecision(9) << answer << '\n';
}