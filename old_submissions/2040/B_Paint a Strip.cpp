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
    if (n == 1) {
        cout << 1 << endl;
        return;
    }
    if (n == 2 or n == 3) {
        cout << 2 << endl;
        return;
    }
    int ans = 2;
    int sz = 4;
    while (sz < n) {
        ++sz;
        sz *= 2;
        ++ans;
    }
    cout << ans << endl;
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