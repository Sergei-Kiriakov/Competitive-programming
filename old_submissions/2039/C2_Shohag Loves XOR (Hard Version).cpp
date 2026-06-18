//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
//#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

constexpr int mod = 1e9 + 7;

int solve(int x, int m)
{
    if (x == 1) {
        return m;
    }
    int kk = 5;
    int ans = 0;
    int min1 = min(kk * x, m);
    set<int> s;
    for (int y = 1; y <= min1; ++y) {
        int now = (y ^ x);
        if (now % x == 0 or now % y == 0) {
            ++ans;
            if (now % x == 0) {
                s.insert(now);
            }
//            cout << y << " " << now << endl;
        }
    }
    bool flag = false;
    bool flag1 = true;
    for (int y = max({m - kk * x, 1ll, min1 + 1}); y > min1 and y <= m; ++y) {
        if (y == min1 + 1)
            flag1 = false;
        flag = true;
        int now = (y ^ x);
        if (now % x == 0 or now % y == 0) {
            ++ans;
            if (now % x == 0) {
                s.insert(now);
            }
//            cout << y << " " << now << endl;
        }
    }
    int max1 = 0;
    if (!s.empty() and flag and flag1) {
        s.erase(--s.end());
        s.erase(--s.end());
        auto it = --s.end();
        int el = *it;
        s.insert(x);
        int dd = (el / x + 1) - (int) s.size();
        ans += max(dd, (int) 0);
    }
    return ans;
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
        int x, m;
        cin >> x >> m;
        cout << solve(x, m) << endl;
//        for (int x = 1; x <= 1000; ++x) {
//            for (int m = 1; m <= 1000; ++m) {
////                if (x == 2 and m == 24)
////                    int o = 2;
//                int ans1 = solve(x, m), ans2 = solve1(x, m);
//                if (ans1 != ans2) {
//                    cout << "-----------" << endl;
//                    cout << x << " " << m << endl;
//                    cout << ans1 << " " << ans2 << endl;
//                }
//            }
//        }
    }
}

/*
*/  