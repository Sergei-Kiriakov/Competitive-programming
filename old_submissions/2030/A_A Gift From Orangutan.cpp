//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

constexpr int mod = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(all(a));
    vector<int> ans(n);
    ans[0] = a[0];
    ans[1] = a.back();
    for (int i = 2; i < n; ++i) {
        ans[i] = a[i - 1];
    }
    int anss = 0;
    int max1 = -1, min1 = 1e9;
    for (int i = 0; i < n; ++i) {
        max1 = max(max1, ans[i]);
        min1 = min(min1, ans[i]);
        anss += max1 - min1;
    }
    cout << anss << endl;
}

int32_t main()
{
//    ofstream cout("");
//    ifstream cin("");
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