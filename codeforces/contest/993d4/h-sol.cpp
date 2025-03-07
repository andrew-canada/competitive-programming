#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
using namespace std;

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template <class Fun>
class y_combinator_result
{
    Fun fun_;

public:
    template <class T>
    explicit y_combinator_result(T &&fun) : fun_(std::forward<T>(fun)) {}
    template <class... Args>
    decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template <class Fun>
decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }

template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template <typename... Args>
ostream &operator<<(ostream &os, const tuple<Args...> &t)
{
    os << '(';
    apply([&os](const Args &...args)
          { size_t n = 0; ((os << args << (++n != sizeof...(Args) ? ", " : "")), ...); }, t);
    return os << ')';
}
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v)
{
    os << '{';
    string sep;
    for (const T &x : v)
        os << sep << x, sep = ", ";
    return os << '}';
}

void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T)
{
    cerr << ' ' << H;
    dbg_out(T...);
}
#ifdef NEAL_DEBUG
#define dbg(...) cerr << '[' << __FILE__ << ':' << __LINE__ << "] (" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

namespace IO
{
    const int BUFFER_SIZE = 1 << 15;

    char input_buffer[BUFFER_SIZE];
    size_t input_pos = 0, input_len = 0;

    char output_buffer[BUFFER_SIZE];
    int output_pos = 0;

    char number_buffer[100];
    uint8_t lookup[100];

    void _update_input_buffer()
    {
        input_len = fread(input_buffer, sizeof(char), BUFFER_SIZE, stdin);
        input_pos = 0;

        if (input_len == 0)
            input_buffer[0] = EOF;
    }

    inline char next_char(bool advance = true)
    {
        if (input_pos >= input_len)
            _update_input_buffer();

        return input_buffer[advance ? input_pos++ : input_pos];
    }

    template <typename T>
    inline void read_int(T &number)
    {
        bool negative = false;
        number = 0;

        while (!isdigit(next_char(false)))
            if (next_char() == '-')
                negative = true;

        do
        {
            number = 10 * number + (next_char() - '0');
        } while (isdigit(next_char(false)));

        if (negative)
            number = -number;
    }

    template <typename T, typename... Args>
    inline void read_int(T &number, Args &...args)
    {
        read_int(number);
        read_int(args...);
    }

    void _flush_output()
    {
        fwrite(output_buffer, sizeof(char), output_pos, stdout);
        output_pos = 0;
    }

    inline void write_char(char c)
    {
        if (output_pos == BUFFER_SIZE)
            _flush_output();

        output_buffer[output_pos++] = c;
    }

    template <typename T>
    inline void write_int(T number, char after = '\0')
    {
        if (number < 0)
        {
            write_char('-');
            number = -number;
        }

        int length = 0;

        while (number >= 10)
        {
            uint8_t lookup_value = lookup[number % 100];
            number /= 100;
            number_buffer[length++] = char((lookup_value & 15) + '0');
            number_buffer[length++] = char((lookup_value >> 4) + '0');
        }

        if (number != 0 || length == 0)
            write_char(char(number + '0'));

        for (int i = length - 1; i >= 0; i--)
            write_char(number_buffer[i]);

        if (after)
            write_char(after);
    }

    void init()
    {
        // Ensures that _flush_output() is called at the end of the program.
        bool exit_success = atexit(_flush_output) == 0;
        assert(exit_success);

        for (int i = 0; i < 100; i++)
            lookup[i] = uint8_t((i / 10 << 4) + i % 10);
    }
}

void run_case()
{
    int N, Q;
    IO::read_int(N, Q);
    vector<vector<int64_t>> rect_sum(N + 1, vector<int64_t>(N + 1, 0));
    vector<vector<int64_t>> row_asc_sum(N + 1, vector<int64_t>(N + 1, 0));
    vector<vector<int64_t>> col_asc_sum(N + 1, vector<int64_t>(N + 1, 0));

    for (int r = 0; r < N; r++)
        for (int c = 0; c < N; c++)
        {
            int m;
            IO::read_int(m);
            rect_sum[r + 1][c + 1] = rect_sum[r + 1][c] + rect_sum[r][c + 1] - rect_sum[r][c] + m;
            row_asc_sum[r + 1][c + 1] = row_asc_sum[r + 1][c] + row_asc_sum[r][c + 1] - row_asc_sum[r][c] + m * r;
            col_asc_sum[r + 1][c + 1] = col_asc_sum[r + 1][c] + col_asc_sum[r][c + 1] - col_asc_sum[r][c] + m * c;
        }

    auto query_rect_sum = [&](int r_low, int r_high, int c_low, int c_high) -> int64_t
    {
        return rect_sum[r_high][c_high] - rect_sum[r_high][c_low] - rect_sum[r_low][c_high] + rect_sum[r_low][c_low];
    };

    auto query_row_asc_sum = [&](int r_low, int r_high, int c_low, int c_high) -> int64_t
    {
        return row_asc_sum[r_high][c_high] - row_asc_sum[r_high][c_low] - row_asc_sum[r_low][c_high] + row_asc_sum[r_low][c_low]; // - r_low * query_rect_sum(r_low, r_high, c_low, c_high);
    };

    auto query_col_asc_sum = [&](int r_low, int r_high, int c_low, int c_high) -> int64_t
    {
        return col_asc_sum[r_high][c_high] - col_asc_sum[r_high][c_low] - col_asc_sum[r_low][c_high] + col_asc_sum[r_low][c_low]; // - c_low * query_rect_sum(r_low, r_high, c_low, c_high);
    };

    for (int q = 0; q < Q; q++)
    {
        int r_low, c_low, r_high, c_high;
        IO::read_int(r_low, c_low, r_high, c_high);
        r_low--;
        c_low--;
        int64_t ans = query_col_asc_sum(r_low, r_high, c_low, c_high);
        ans += (c_high - c_low) * query_row_asc_sum(r_low, r_high, c_low, c_high);
        ans -= ((c_high - c_low) * r_low + c_low - 1) * query_rect_sum(r_low, r_high, c_low, c_high);
        IO::write_int(ans, q < Q - 1 ? ' ' : '\n');
    }
}

int main()
{
    IO::init();

    int tests;
    IO::read_int(tests);

    while (tests-- > 0)
        run_case();
}