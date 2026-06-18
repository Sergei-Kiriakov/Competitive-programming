//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

constexpr int mod = 1e9 + 7;

int time_in_seconds (string s) {
    int ans = 0;
    ans += (s[0] - '0') * 60 * 60;
    ans += ((s[2] - '0') * 10 + (s[3] - '0')) * 60;
    ans += (s[5] - '0') * 10 + (s[6] - '0');
    return ans;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> h(n), p(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    vector<pair<int, int> > a(n);
    for (int i = 0; i < n; ++i) {
        a[i] = make_pair(h[i], p[i]);
    }
    sort(all(a));
    int d = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        a[i].second -= d;
        if (a[i].second < a[i].first) {
            cout << -1 << endl;
            return;
        }
        int dif = a[i].second - a[i].first;
        d += dif;
    }
    cout << d << endl;
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