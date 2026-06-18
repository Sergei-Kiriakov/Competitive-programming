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
    vector<int> a(n);
    vector<int> cnt(k, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] %= k;
        cnt[a[i]] += 1;
    }
    for (int i = 0; i < n; ++i) {
        if (cnt[a[i]] == 1) {
            cout << "YES" << endl;
            cout << i + 1 << endl;
            return;
        }
    }
    cout << "NO" << endl;
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