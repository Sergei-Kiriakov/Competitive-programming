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
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    init(n, a);
    vector<vector<int> > st;
    for (int i = 0; i < n; ++i) {
        if (st.empty()) {
            st.push_back({a[i], i});
            continue;
        }
        while (!st.empty() and st.back()[0] < a[i]) {
            nex[st.back()[1]] = i;
            st.pop_back();
        }
        st.push_back({a[i], i});
    }
    while (!st.empty()) {
        nex[st.back()[1]] = -1;
        st.pop_back();
    }
    for (int i = 0; i < q; ++i) {
        char ask;
        cin >> ask;
        if (ask == '+') {
            int v, val;
            cin >> v >> val;
            --v;
            while (val > 0) {
                v = get_parent(v);
                int tmp = min(val, fil[v]);
                fil[v] -= tmp;
                val -= tmp;
                if (fil[v] == 0) {
                    if (nex[v] == -1)
                        break;
                    connect(v, nex[v]);
                }
            }
        }
        else {
            int pos;
            cin >> pos;
            --pos;
            cout << a[pos] - fil[pos] << endl;
        }
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