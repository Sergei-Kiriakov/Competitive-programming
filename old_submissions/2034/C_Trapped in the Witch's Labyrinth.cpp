//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

//#define int long long
//#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

constexpr int mod = 998244353;

vector<vector<pair<int, int> > > parent;
vector<vector<int> > sz;
vector<vector<bool> > bes;
vector<vector<bool> > used2;
vector<vector<int> > color;;

void init (int n, int m)
{
    sz = vector<vector<int> > (n + 1, vector<int> (m + 1, 1));
    parent = vector<vector<pair<int, int> > > (n + 1, vector<pair<int, int> > (m + 1));
    bes = vector<vector<bool> > (n + 1, vector<bool> (m + 1, false));
    used2 = vector<vector<bool> > (n + 1, vector<bool> (m + 1, false));
    color = vector<vector<int> > (n + 1, vector<int> (m + 1, 0));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j) {
            parent[i][j] = {i, j};
        }
    }
}

pair<int, int> get_parent (pair<int, int> u)
{

    if (parent[u.first][u.second] == u)
        return u;
    pair<int, int> temp = get_parent(parent[u.first][u.second]);
    parent[u.first][u.second] = temp;
    return parent[u.first][u.second];
}

void connect (pair<int, int> u, pair<int, int> v)
{
    u = get_parent(u);
    v = get_parent(v);
    if (sz[u.first][u.second] < sz[v.first][v.second])
    {
        swap(u, v);
    }
    parent[v.first][v.second] = u;
    bes[u.first][u.second] = (bes[u.first][u.second] or bes[v.first][v.second]);
    sz[u.first][u.second] += sz[v.first][v.second];
}

map<char, pair<int, int> > c;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    init(n, m);
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < m; ++y) {
            if (a[x][y] == '?')
                continue;
            int dx = c[a[x][y]].first, dy = c[a[x][y]].second;
            int nx = x + dx, ny = y + dy;
            if (!(nx > -1 and nx < n and ny > -1 and ny < m))
                continue;
            auto v = get_parent(make_pair(nx, ny));
            auto u = get_parent(make_pair(x, y));
            if (a[nx][ny] == '?')
                bes[v.first][v.second] = true;
            if (u == v)
                bes[v.first][v.second] = true;
            connect(v, make_pair(x, y));
        }
    }
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < m; ++y) {
            if (a[x][y] != '?')
                continue;
            vector<int> dx = {1, -1, 0, 0}, dy = {0, 0, 1, -1};
            auto v = get_parent(make_pair(x, y));
            for (int i = 0; i < dx.size(); ++i) {
                int nx = x + dx[i], ny = y + dy[i];
                if (!(nx > -1 and nx < n and ny > -1 and ny < m))
                    continue;
                auto u = get_parent(make_pair(nx, ny));
                if (a[nx][ny] == '?' or bes[u.first][u.second])
                    bes[v.first][v.second] = true;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            auto temp = get_parent(make_pair(i, j));
            if (bes[temp.first][temp.second]) {
                ++ans;
            }
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

    c['U'] = {-1, 0};
    c['D'] = {1, 0};
    c['L'] = {0, -1};
    c['R'] = {0, 1};

    while(tt-->0)
    {
        solve();
    }
}

/*
*/  