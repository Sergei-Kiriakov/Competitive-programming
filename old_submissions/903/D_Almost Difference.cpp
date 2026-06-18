#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#include <random>

#define int long long
#define double long double
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

const int mod = 1e9 + 93, big = 2e6;

void print(__int128 x)
{
    if (x < 0) {
        cout << '-';
        x = -x;
    }
    if (x > 9) print(x / 10);
    cout << (char) ((x % 10) + '0');
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    unordered_map<int, int> cnt;
    __int128 ans = 0;
    int now_sum = 0;
    for (int i = 0; i < n; ++i)
    {
        int d = a[i];
        ans += d * i - now_sum + cnt[d - 1] * (d - 1) + cnt[d] * d + cnt[d + 1] * (d + 1) - d * (cnt[d - 1] + cnt[d] + cnt[d + 1]);
        ++cnt[a[i]];
        now_sum += a[i];
    }
    print(ans);
}

int32_t main()
{
//  ofstream cout("sum.out");
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed;
    cout.precision(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int tt = 1;
//    cin >> tt;
    while(tt-->0)
    {
        solve();
    }
}


/*
*/