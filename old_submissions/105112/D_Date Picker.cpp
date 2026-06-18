// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

constexpr int mod = 1e9 + 7;

bool cmp(int a, int b) {
    return a > b;
}

int solve_dh(vector<string> & s, int d, int h)
{
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    vector<int> all_d = {0, 1, 2, 3, 4, 5, 6};
    int max_p = 0, max_q = 1e9;
    for (int _ = 0; _ < 5e3; ++_)
    {
        shuffle(all(all_d), rng);
        vector<int> hs(24, 0);
        for (int i = 0; i < d; ++i)
        {
            for (int j = 0; j < 24; ++j)
            {
                int dd = all_d[i];
                hs[j] += (s[dd][j] == '.');
            }
        }
        sort(all(hs), cmp);
        int p = 0;
        for (int i = 0; i < h; ++i)
        {
            p += hs[i];
        }
        max_p = max(max_p, p);
    }
    return max_p;
}

void solve()
{
    vector<string> s(7);
    for (int i = 0; i < 7; ++i)
    {
        cin >> s[i];
    }
    int min_d, min_h;
    cin >> min_d >> min_h;
    // int p = 1, q = 1e9;
    // for (int d = min_d; d <= 7; ++d) {
    //     for (int h = min_h; h <= 24; ++h) {
    //         pair<int, int> temp = solve_dh(s, d, h);
    //         int now_p = temp.first, now_q = temp.second;
    //         if (p * now_q < now_p * q) {
    //             p = now_p;
    //             q = now_q;
    //         }
    //     }
    // }
    int p = 0, q = 1e9;
    for (int d = min_d; d <= 7; ++d)
    {
        for (int h = min_h; h <= 24; ++h)
        {
            int now_p = solve_dh(s, d, h);
            int now_q = (d * h);
            if (now_p * q > p * now_q)
            {
                p = now_p;
                q = now_q;
            }
        }
    }
    long double now_p = p, now_q = q;
    long double ans = now_p / now_q;
    cout << ans << endl;
    return;
}

int32_t main()
{
    // ofstream cout("");
    // ifstream cin("");
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed;
    cout.precision(6);

    int tt = 1;
    // cin >> tt;
    while(tt-->0)
    {
        solve();
    }
    // cout << "Hello" << endl;
}

/*
*/