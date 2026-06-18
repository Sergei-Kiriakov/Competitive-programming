//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
//#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

constexpr int mod = 998244353;

int bin_ (int a, int n, int mod) {
    int ans = 1;
    while (n != 0) {
        if (n % 2 == 1)
            ans = (ans * a) % mod;
        a = (a * a) % mod;
        n /= 2;
    }
    return ans;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int d = bin_(2, k, n);
    string ans;
    for (int i = 0; i < n; ++i) {
        ans += s[i * d % n];
    }
    cout << ans << endl;
}

int32_t main() {
//    ofstream cout("");
//    ifstream cin("");
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed;
    cout.precision(7);
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