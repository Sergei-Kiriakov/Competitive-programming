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
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    int n, m;
    cin >> n >> m;

    vector<pair<int, int> > dd(n);
    for (int i = 0; i < n; ++i) {
        dd[i].second = i;
    }
    vector<pair<int, int> > edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].first >> edges[i].second;
        --edges[i].first; --edges[i].second;
    }
    vector<int> ans(n);
    for (int i = 0; i < n; ++i) ans[i] = i;
    while (true) {
        shuffle(all(ans), rng);
        map<int, int> c;
        for (int i = 0; i < n; ++i) c[ans[i]] = i;
        int cnt = 0;
        for (int i = 0; i < m; ++i) {
            if (c[edges[i].first] < c[edges[i].second]) {
                ++cnt;
            }
        }
        if (cnt * 2 >= m) {
            for (auto el : ans) {
                cout << el + 1 << " ";
            }
            cout << endl;
            return;
        }
    }
}

int32_t main()
{
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