// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

constexpr int mod = 1e9 + 7;

bool is_norm(int x, int y, int n, int m) {
    return x >= 0 and x < n and y >= 0 and y < m;
}

void solve()
{
    int r, c, n, p;
    cin >> r >> c >> n >> p;
    vector<vector<int> > grid(r, vector<int> (c, 0));
    map<int, pair<int, int> > position;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> grid[i][j];
            position[grid[i][j]] = {i, j};
        }
    }
    set<int> adj;
    for (int q = p; q >= 1; --q) {
        pair<int, int > temp = position[q];
        int x = temp.first, y = temp.second;
        vector<int> moves_x = {-1, 1, 0, 0};
        vector<int> moves_y = {0, 0, 1, -1};
        int delta = p - q;
        for (int i = 0; i < moves_x.size(); ++i) {
            int nx = x + moves_x[i];
            int ny = y + moves_y[i];
            if (is_norm(nx, ny, r, c) and grid[nx][ny] + delta <= n and grid[nx][ny] != 0) {
                adj.insert(grid[nx][ny] + delta);
            }
        }
    }
    cout << adj.size() << '/' << n - 1 << endl;
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
//    cin >> tt;
    while(tt-->0)
    {
        solve();
    }
}

/*
*/  