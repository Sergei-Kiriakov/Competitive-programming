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
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int sum = 0;
    for (int i = 0; i < n - 2; ++i) sum += a[i];
    cout << a[n - 1] - a[n - 2] + sum << endl;
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