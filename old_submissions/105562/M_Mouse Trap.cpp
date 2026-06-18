//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
#define double long double
//#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

constexpr int mod = 998244353;

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int> > p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i].first >> p[i].second;
    }
    vector<pair<int, int> > pr_l(n, {0, 0}), pr_r(n, {0, 0});
    pr_l[0] = p[0];
    for (int i = 1; i < n; ++i) {
        pr_l[i].first = pr_l[i - 1].first + p[i].first;
        pr_l[i].second = pr_l[i - 1].second + p[i].second;
    }
    pr_r[n - 1] = p[n - 1];
    for (int i = n - 2; i > -1; --i) {
        pr_r[i].first = pr_r[i + 1].first + p[i].first;
        pr_r[i].second = pr_r[i + 1].second + p[i].second;
    }
    double ans = 0;
    for (int j = 1; j < n - 1; ++j) {
        double x1 = p[j].first * j - pr_l[j - 1].first, y1 = p[j].second * j - pr_l[j - 1].second;
        double x2 = pr_r[j + 1].first - (n - j - 1) * p[j].first, y2 = pr_r[j + 1].second - (n - j - 1) * p[j].second;
        ans += abs(x1 * y2 - y1 * x2);
    }
    int s = 0;
    for (int i = 1; i < n - 1; ++i) {
        int x1 = p[i].first - p[0].first, y1 = p[i].second - p[0].second;
        int x2 = p[i + 1].first - p[0].first, y2 = p[i + 1].second - p[0].second;
        s += x1 * y2 - x2 * y1;
    }
    ans /= s;
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