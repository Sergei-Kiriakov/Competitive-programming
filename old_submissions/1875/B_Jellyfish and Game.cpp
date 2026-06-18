//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#include <random>

#define int long long
#define double long double
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

const int mod = 998244353, big = 2e6;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    multiset<int> a, b;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        a.insert(x);
    }
    for (int i = 0; i < m; ++i)
    {
        int x;
        cin >> x;
        b.insert(x);
    }
    if (k > 2000)
    {
        k -= 2000;
        for (int i = 1; i <= 2000; ++i)
        {
            if (i % 2 == 1)
            {
                int d1 = *a.begin(), d2 = *(--b.end());
                if (d1 >= d2)
                    continue;
                a.erase(a.begin());
                b.erase(--b.end());
                a.insert(d2);
                b.insert(d1);
            }
            else
            {
                int d1 = *b.begin(), d2 = *(--a.end());
                if (d1 >= d2)
                    continue;
                b.erase(b.begin());
                a.erase(--a.end());
                a.insert(d1);
                b.insert(d2);
            }
        }
        if (k % 2 == 1)
        {
            int d1 = *a.begin(), d2 = *(--b.end());
            if (d1 < d2)
            {
                a.erase(a.begin());
                b.erase(--b.end());
                a.insert(d2);
                b.insert(d1);
            }
        }
        int ans = 0;
        for (auto it = a.begin(); it != a.end(); ++it) ans += *it;
        cout << ans << endl;
    }
    else
    {
        for (int i = 1; i <= k; ++i)
        {
            if (i % 2 == 1)
            {
                int d1 = *a.begin(), d2 = *(--b.end());
                if (d1 >= d2)
                    continue;
                a.erase(a.begin());
                b.erase(--b.end());
                a.insert(d2);
                b.insert(d1);
            }
            else
            {
                int d1 = *b.begin(), d2 = *(--a.end());
                if (d1 >= d2)
                    continue;
                b.erase(b.begin());
                a.erase(--a.end());
                a.insert(d1);
                b.insert(d2);
            }
        }
        int ans = 0;
        for (auto it = a.begin(); it != a.end(); ++it) ans += *it;
        cout << ans << endl;
    }
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