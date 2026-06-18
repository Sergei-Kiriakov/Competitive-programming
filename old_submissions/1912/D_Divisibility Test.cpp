//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
//#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

constexpr int mod = 998244353;

void solve() {
    int b, n;
    cin >> b >> n;
    int k1 = 1e9, k2 = 1e9, k3 = 1e9;
    int d1 = b % n;
    for (int i = 0; i <= n; ++i) {
        if (d1 == 0) {
            k1 = i + 1;
            break;
        }
        d1 = d1 * b % n;
    }
    int d2 = b % n;
    for (int i = 0; i <= n; ++i) {
        if (d2 == 1) {
            k2 = i + 1;
            break;
        }
        d2 = d2 * b % n;
    }
    int d3 = b % n;
    for (int i = 0; i <= n; ++i) {
        if (d3 == n - 1) {
            k3 = i + 1;
            break;
        }
        d3 = d3 * b % n;
    }
    int min1 = min({k1, k2, k3});
    if (min1 == 1e9) {
        cout << 0 << endl;
        return;
    }
    if (min1 == k1) {
        cout << 1 << " " << k1 << endl;
        return;
    }
    if (min1 == k2) {
        cout << 2 << " " << k2 << endl;
        return;
    }
    if (min1 == k3) {
        cout << 3 << " " << k3 << endl;
    }
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