// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
#define endl "\n"

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> ans (n + 1, 1);
    for (int i = 2; i <= n; ++i)
        for (int j = i + i; j <= n; j += i)
            ans[j] = i;
    sort(ans.begin(), ans.end());
    for (int i = 2; i <= n; ++i)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int32_t main()
{
    // ofstream cout("sum.out");
    // ifstream cin("sum.in");
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // cout << fixed;
    // cout.precision(15);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int tt = 1;
    // cin >> tt;
    while(tt-->0)
    {
        solve();
    }  
}


/*
*/  