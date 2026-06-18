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
    vector<int> a(n);
    map<int, vector<int> > c;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i > 0)
            c[a[i] + i].push_back(i);
    }
    std::priority_queue<int, std::vector<int>, std::greater<int>> q;
    int ans = n;
    q.push(n);
    set<int> used;
    while (!q.empty()) {
        int v = q.top();
        ans = max(ans, v);
        q.pop();
        if (used.count(v))
            continue;
        used.insert(v);
        for (auto el : c[v]) {
            q.push(v + el);
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