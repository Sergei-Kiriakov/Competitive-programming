//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
//#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

constexpr int mod = 998244353;

void solve()
{
    int n;
    cin >> n;
    vector<vector<int> > a(n, vector<int> (4, 0));
    for (int i = 0; i < n; ++i) {
        int x, y, h;
        cin >> x >> y >> h;
        a[i][0] = h;
        a[i][1] = x;
        a[i][2] = y;
        a[i][3] = i;
    }
    vector<int> ans(n);
    sort(all(a));
    for (int i = 0; i < n; ++i) {
        int min1 = a[i][0];
        for (int j = i + 1; j < n; ++j) {
            int dx = a[i][1] - a[j][1];
            int dy = a[i][2] - a[j][2];
            int bb = dx * dx + dy * dy;
            int now = sqrt(bb);
//            if (now * now == bb) {
//                --now;
//            }
            min1 = min(now, min1);
        }
        ans[a[i][3]] = min1;
    }
    for (auto el : ans) {
        cout << el << endl;
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
//    cin >> tt;
    while(tt-->0)
    {
        solve();
    }
}

/*
*/