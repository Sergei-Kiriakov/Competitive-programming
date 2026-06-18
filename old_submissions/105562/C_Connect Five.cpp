//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
#define double long double
//#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

constexpr int mod = 998244353;

bool cmp_x_r (pair<int, int> a, pair<int, int> b) {
    return a.first > b.first;
}

bool cmp_y_l (pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

bool cmp_y_r (pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
}

void del_same(vector<pair<int, int> > & a) {
    int n = a.size();
    vector<pair<int, int> > b;
    b.push_back(a[0]);
    for (int i = 1; i < n; ++i) {
        if (a[i] != a[i - 1])
            b.push_back(a[i]);
    }
    a = b;
}

void solve()
{
    int n = 5;
    vector<pair<int, int> > a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    int ans = 0;
    for (int i = 0; i < 100; ++i) {
        sort(all(a));
        if (a.size() >= 2 and a[0].first != a[1].first) {
            ans += a[1].first - a[0].first;
            a[0].first = a[1].first;
        }
        sort(all(a), cmp_x_r);
        if (a.size() >= 2 and a[0].first != a[1].first) {
            ans += abs(a[1].first - a[0].first);
            a[0].first = a[1].first;
        }
        del_same(a);
        sort(all(a), cmp_y_l);
        if (a.size() >= 2 and a[0].second != a[1].second) {
            ans += abs(a[1].second - a[0].second);
            a[0].second = a[1].second;
        }
        del_same(a);
        sort(all(a), cmp_y_r);
        if (a.size() >= 2 and a[0].second != a[1].second) {
            ans += abs(a[1].second - a[0].second);
            a[0].second = a[1].second;
        }
        del_same(a);
    }
    sort(all(a));
    int cnt = 0;
    pair<int, int> mid = a[2];
    if (a.size() == 5 and mid.first != a[1].first and mid.first != a[3].first) {
        ++cnt;
    }
    sort(all(a), cmp_y_l);
    if (a.size() == 5 and mid.second != a[1].second and mid.second != a[3].second) {
        ++cnt;
    }
    if (a.size() >= 4) {
        int min_x = 1e9, max_x = -1, min_y = 1e9, max_y = -1;
        for (int i = 0; i < a.size(); ++i) {
            min_x = min(min_x, a[i].first);
            max_x = max(max_x, a[i].first);
            min_y = min(min_y, a[i].second);
            max_y = max(max_y, a[i].second);
        }
        int dx = max_x - min_x;
        int dy = max_y - min_y;
        ans += dx * 2 + dy * 2 + min(dx, dy) * (cnt == 2);
        cout << ans << endl;
        return;
    }
    if (a.size() == 1) {
        cout << ans << endl;
        return;
    }
    if (a.size() == 2) {
        ans += abs(a[0].first - a[1].first) + abs(a[0].second - a[1].second);
        cout << ans << endl;
        return;
    }
    cout << "axaxaxxaxaxxaxaxxaxaxa" << endl;
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