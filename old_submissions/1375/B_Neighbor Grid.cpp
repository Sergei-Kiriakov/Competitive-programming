// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

constexpr int mod = 1e9 + 7;

pair<string, vector<vector<int> > > solve(int n, int m, vector<vector<int> > grid)
{
    vector<vector<int> > max_grid(n, vector<int> (m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if ((i == 0 and j == 0) or (i == n - 1 and j == 0) or (i == 0 and j == m - 1) or (i == n - 1 and j == m - 1)) {
                max_grid[i][j] = 2;
                continue;
            }
            if ((i == 0) or (j == 0) or (j == m - 1) or (i == n - 1)) {
                max_grid[i][j] = 3;
                continue;
            }
            max_grid[i][j] = 4;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] > max_grid[i][j]) {
                return {"NO", {}};
            }
        }
    }
    return {"YES", max_grid};
}

void input()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int> > grid(n, vector<int> (m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }
    pair<string, vector<vector<int> > > ans = solve(n, m, grid);
    cout << ans.first << endl;
    if (ans.first == "NO") {
        return;
    }
    for (auto raw : ans.second) {
        for (auto el : raw) {
            cout << el << " ";
        }
        cout << endl;
    }
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
        input();
    }
}

/*
*/