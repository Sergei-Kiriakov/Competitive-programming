//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#include <random>

#define int long long
#define double long double
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

const int mod = 1e9 + 93;

void solve()
{
    int n, m, d;
    cin >> n >> m >> d;
    vector<int> a(m + 2);
    a[0] = 1 - d;
    for (int i = 0; i < m; ++i)
        cin >> a[i + 1];
    a[m + 1] = n + 1;
    int ans = m;
    for (int i = 1; i < a.size(); ++i)
    {
        ans += (a[i] - a[i - 1] - 1) / d;
    }
    int anss = 1e10, cnt = 0;
    for (int i = 1; i < m + 1; ++i)
    {
        int now = ans - (a[i] - a[i - 1] - 1) / d - (a[i + 1] - a[i] - 1) / d + (a[i + 1] - a[i - 1] - 1) / d - 1;
        if (now < anss)
        {
            anss = now;
            cnt = 1;
        }
        else if (now == anss)
        {
            ++cnt;
        }
    }
    cout << anss << " " << cnt << endl;
}

int32_t main()
{
//  ofstream cout("sum.out");
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed;
    cout.precision(7);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int tt = 1;
    cin >> tt;
    while(tt-->0)
    {
        solve();
    }
}


/*
*/