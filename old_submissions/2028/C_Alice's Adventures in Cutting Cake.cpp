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
    int n, m, v;
    cin >> n >> m >> v;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int cnt = 0;
    vector<int> inds;
    int now = 0;
    for (int i = 0; i < n; ++i) {
        now += a[i];
        if (now >= v and inds.size() < m) {
            inds.push_back(i);
            now = 0;
        }
    }
    if (inds.size() < m) {
        cout << -1 << endl;
        return;
    }
    int ans = now;
    vector<int> pr(n, 0);
    pr[0] = a[0];
    for (int i = 1; i < n; ++i) {
        pr[i] = pr[i - 1] + a[i];
    }
    vector<int> r_inds;
    now = 0;
    for (int i = n - 1; i > -1; --i) {
        now += a[i];
        if (now >= v and r_inds.size() < m) {
            r_inds.push_back(i);
            now = 0;
        }
    }
    ans = max(now, ans);
    for (int i = 1; i < m; ++i) {
        int l = inds[i - 1];
        int r = r_inds[m - i - 1] - 1;
        ans = max(ans, pr[r] - pr[l]);
    }
    cout << ans << endl;
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