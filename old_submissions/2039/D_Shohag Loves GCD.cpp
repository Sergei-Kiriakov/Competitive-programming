//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
//#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

constexpr int mod = 1e9 + 7;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
    }
    vector<int> ans(n, m - 1);
    for (int i = 0; i < n; ++i) {
        int o = 2;
        for (int j = i + (i + 1); j < n; j += (i + 1)) {
            ans[j] = min(ans[j], ans[i] - 1);
        }
    }
    for (auto el : ans) {
        if (el < 0) {
            cout << -1 << endl;
            return;
        }
    }
    for (auto el: ans) {
        cout << a[el] << " ";
    }
    cout << endl;
}

int solve1(int x, int m)
{
//    int x, m;
//
//    cin >> x >> m;
    int ans = 0;
    int min1 = min(m, m);
    for (int y = 1; y <= min1; ++y) {
        int now = (y ^ x);
        if (now % x == 0 or now % y == 0) {
            ++ans;
//            cout << y << " " << now << endl;
        }
    }

//    cout << ans << endl;
    return ans;
}

int32_t main() {
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