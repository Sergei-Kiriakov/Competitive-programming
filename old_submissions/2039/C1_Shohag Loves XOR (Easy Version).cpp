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
    int x, m;
    cin >> x >> m;
    int ans = 0;
    for (int y = 1; y <= min(5 * x, m); ++y) {
        int now = (y ^ x);
        if (now == 0)
            continue;
        if (x % now == 0 or y % now == 0) {
            ++ans;
//            cout << y << " " << now << endl;
        }
    }
    cout << ans << endl;
}

int32_t main() {
//    ofstream cout("");
//    ifstream cin("");
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed;
    cout.precision(7);
    int tt = 1;
    cin >> tt;
    while(tt-->0)
    {
        solve();
    }
}

/*
*/  