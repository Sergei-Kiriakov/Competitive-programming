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
    int n;
    cin >> n;
    int ans = 0;
    for (int i = n * n; i >= n; --i)
    {
        set<int> s;
        for (int j = 1; j < n + 1; ++j)
        {
            s.insert(j);
        }
        int now = 0;
        for (int j = n; j > 0; --j)
        {
            int d = i / j;
            auto it = s.lower_bound(d);
            if (it == s.end() or *it > d)
            {
                if (it == s.begin())
                    continue;
                --it;
            }
            now += *it * j;
            s.erase(it);
        }
        now -= i;
        ans = max(now, ans);
    }
    cout << ans << endl;
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