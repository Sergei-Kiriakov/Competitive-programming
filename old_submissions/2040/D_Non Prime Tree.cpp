//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

constexpr int mod = 1e9 + 7;

vector<vector<int> > g;
vector<int> d;
int now;

void dfs(int v, int p=-1) {
    ++now;
    if (p != -1) {
        if ((now - d[p]) % 2 != 0 and now - d[p] != 1) {
            ++now;
        }
        if (now - d[p] == 2) {
            now += 2;
        }
    }
    d[v] = now;
//    cout << d[v] << endl;
    for (auto u : g[v]) {
        if (u != p) {
            dfs(u, v);
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    g = vector<vector<int> > (n);
    for (int i = 0; i < n - 1; ++i) {
        int v, u;
        cin >> v >> u;
        --v; --u;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    d = vector<int> (n, 0);
    now = 0;
    dfs(0);
    for (auto el : d) {
        cout << el << " ";
    }
    cout << endl;
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