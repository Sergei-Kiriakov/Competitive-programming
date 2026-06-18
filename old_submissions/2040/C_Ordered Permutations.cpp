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
    int n, k;
    cin >> n >> k;
    vector<int> ans(n, 0);
    if (k > (1ll << min(n - 1, 50ll))) {
        cout << -1 << endl;
        return;
    }
    int now = 0;
    int l = 0, r = n - 1;
    for (int i = 0; i < n; ++i) {
        int d = n - 2 - i;
        d = max(0ll, d);
        d = min(50ll, d);
        if (now + (1ll << d) < k) {
            now += (1ll << d);
            ans[r] = i + 1;
            --r;
        }
        else {
            ans[l] = i + 1;
            ++l;
        }
    }
    for (auto el : ans) {
        cout << el << " ";
    }
    cout << endl;
    return;
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