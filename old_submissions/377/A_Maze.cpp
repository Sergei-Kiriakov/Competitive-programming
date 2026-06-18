#include <bits/stdc++.h>

//#define int long long
//#define double long double

using namespace std;

vector<string> a;
vector<vector<bool> > used;
int cnt;

bool in_bord(int x, int y, int n, int m)
{
    return x > -1 && x < n && y > -1 && y < m;
}

void dfs (int x, int y)
{
    used[x][y] = true;
    int n = a.size(), m = a[0].size();
    vector<int> dx = {1, -1, 0, 0}, dy = {0, 0, 1, -1};
    for (int i = 0; i < dx.size(); ++i)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (in_bord(nx, ny, n, m) && !used[nx][ny] && a[nx][ny] == '.')
        {
            dfs(nx, ny);
        }
    }
    if (cnt > 0)
    {
        --cnt;
        a[x][y] = 'X';
    }
}

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    cnt = k;
    a = vector<string> (n);
    used = vector<vector<bool> > (n, vector<bool> (m, false));
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<vector<int> > dist(n, vector<int> (m, 1e9));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (!used[i][j] && a[i][j] != '#')
            {
                dfs(i, j);
            }
        }
    }
    for (auto str : a) cout << str << "\n";
}

int32_t main()
{
    //ofstream cout("test.txt");
    //ifstream cin("joseph.in");
    //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cerr.tie(0);
    int t;
    t = 1;
    while (t--)
    {
        solve();
    }
    //solve();
    return 0;
}

/*
*/
