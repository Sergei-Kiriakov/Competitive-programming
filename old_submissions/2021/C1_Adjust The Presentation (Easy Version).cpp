// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()

typedef std::vector<int> vi;

using namespace std;

constexpr int mod = 1e9 + 7;

class UnionFind {
private: vi p, rank;
public:
    explicit UnionFind(const int N) {
        rank.assign(N, 0);
        p.assign(N, 0);
        for (int i = 0; i < N; i++) p[i] = i;
    }
    int findSet(const int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
    bool isSameSet(const int i, const int j) { return findSet(i) == findSet(j); }
    void unionSet(const int i, const int j) {
        if (!isSameSet(i, j)) {
            int x = findSet(i), y = findSet(j);
            if (rank[x] > rank[y]) p[y] = x;
            else {
                p[x] = y;
                if (rank[x] == rank[y]) rank[y]++;
            }
        }
    }
};

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    vi a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vi b(m);
    for (int i = 0; i < m; ++i) cin >> b[i];
    vi next_b(m, -1);
    vi last_b(n + 1, -1);
    for (int i = m - 1; i > -1; --i) {
        if (last_b[b[i]] != -1)
            next_b[i] = last_b[b[i]];
        last_b[b[i]] = i;
    }
    vi first_b;
    set<int> was;
    for (int i = 0; i < m; ++i) {
        if (was.count(b[i]) == 0)
            first_b.push_back(b[i]);
        was.insert(b[i]);
    }
    string ans = "YA";
    for (int i = 0; i < first_b.size(); ++i) {
        if (first_b[i] != a[i])
            ans = "TIDAK";
    }
    cout << ans << endl;
}

int32_t main()
{
    // ofstream cout("");
    // ifstream cin("");
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