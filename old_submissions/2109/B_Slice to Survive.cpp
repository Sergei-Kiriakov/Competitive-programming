// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

constexpr int mod = 1e9 + 7;

int get_ans(int n, int m) {
    int ans = 0;
    while (n != 1) {
        n = (n + 1) / 2;
        ++ans;
    }
    while (m != 1) {
        m = (m + 1) / 2;
        ++ans;
    }
    return ans;
}

int solve(int n, int m, int a, int b)
{
    return 1 + min(get_ans(min(a, n - a + 1), m),
               get_ans(n, min(b, m - b + 1)));
}

void input()
{
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    int ans = solve(n, m, a, b);
    cout << ans << endl;
}

int32_t main()
{
    // ofstream cout("");
    // ifstream cin("");
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed;
    cout.precision(7);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int tt = 1;
    cin >> tt;
    while(tt-->0)
    {
        input();
    }
}

/*
*/