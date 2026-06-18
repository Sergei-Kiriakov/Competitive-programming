#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()


using namespace std;

const int mod = 1e9 + 7;

void solve()
{
    int n, m, c;
    cin >> n >> m >> c;
    int ans = 1e18, ans1 = -1, ans2 = -1;
    for (int i = 0; i <= n / m + 2; ++i)
    {
        int d = max(n - m * i, 0ll);
        int j = d / c;
        int j1 = j + 1;
        if (abs(i * m + c * j - n) < ans)
        {
            ans = abs(i * m + c * j - n);
            ans1 = i;
            ans2 = j;
        }
        if (abs(i * m + c * j1 - n) < ans)
        {
            ans = abs(i * m + c * j1 - n);
            ans1 = i;
            ans2 = j1;
        }
    }
    cout << ans1 << " " << ans2 << endl;
}

int32_t main()
{
    //ofstream cout("sum.out");
    //ifstream cin("sum.in");
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed;
    cout.precision(15);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int tt = 1;
    //cin >> tt;
    while(tt-->0)
    {
        solve();
    }
}


/*
*/