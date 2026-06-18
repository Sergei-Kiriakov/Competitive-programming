//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
#include <random>

#define int long long
#define double long double
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

const int mod = 1e9 + 7, ddl = 179;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int ans = 0;
    for (int max1 = 1; max1 < 31; ++max1)
    {
        int last_sum = 0, max_ans = 0;
        for (int i = 0; i < n; ++i)
        {
            if (a[i] > max1)
                last_sum -= 1e9;
            else
                last_sum += a[i];
            if (last_sum < 0)
                last_sum = 0;
            max_ans = max(max_ans, last_sum);
        }
        ans = max(ans, max_ans - max1);
    }
    cout << ans << endl;
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