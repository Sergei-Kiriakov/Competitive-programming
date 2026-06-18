#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#include <random>

#define int __int128
#define double long double
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

const int mod = 998244353, big = 2e6;

void solve()
{
    long long n;
    cin >> n;
    vector<int> a(n);
    vector<long long> b(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> b[i];
        a[i] = b[i];
    }
    __int128 now = 0;
    int d = 1;
    vector<int> ans;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] < 128)
        {
            now += a[i] * d;
            if (now % 2 == 0)
                ans.push_back(now / 2);
            else
                ans.push_back((now + 1) / 2 * -1);
            now = 0;
            d = 1;
        }
        else
        {
            now += (a[i] - 128) * d;
            d <<= 7;
        }
    }
    if (a.back() >= 128)
    {
        now += a.back() * d;
        d <<= 7;
        if (now % 2 == 0)
            ans.push_back(now / 2);
        else
            ans.push_back((now + 1) / 2 * -1);
        now = 0;
        d = 1;
    }
    for (auto elem : ans)
        cout << (long long) elem << endl;
}

int32_t main()
{
//  ofstream cout("sum.out");
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed;
    cout.precision(7);
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