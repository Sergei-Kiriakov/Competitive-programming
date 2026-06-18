//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
//#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

constexpr int mod = 998244353;

vector<int> parent, nex, sz, fil;

void init (int n, const vector<int> & a) {
    parent = nex = sz = fil = vector<int> (n);
    for (int i = 0; i < n; ++i) {
        sz[i] = 1;
        parent[i] = i;
        fil[i] = a[i];
    }
}

int get_parent (int u) {
    if (parent[u] == u)
        return u;
    parent[u] = get_parent(parent[u]);
    return parent[u];
}

void connect (int u, int v) {
    u = get_parent(u);
    v = get_parent(v);
//    if (sz[u] < sz[v]) {
//        swap(u, v);
//    }
    parent[u] = v;
//    sz[u] += sz[v];
}

void solve()
{
    int n;
    cin >> n;
    int x = 1;
    cout << "? " << n << " " << x << endl;
    int c;
    cin >> c;
    if (c == n) {
        cout << "! " << n << " " << x << endl;
        return;
    }
    cout << "? " << n - c << " " << x << endl;
    int r;
    cin >> r;
    cout << "! " << c << " " << r << endl;
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