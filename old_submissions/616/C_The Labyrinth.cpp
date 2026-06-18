#include <bits/stdc++.h>
#define int long long
#define double long double

typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
typedef std::vector<vvi> vvvi;
typedef std::vector<vvvi> vvvvi;
typedef std::vector<std::string> vs;
typedef std::vector<bool> vb;
typedef std::vector<vb> vvb;
typedef std::vector<double> vd;
typedef std::vector<vd> vvd;
typedef std::pair<int, int> pii;
typedef std::vector<pii> vpii;
typedef std::vector<vpii> vvpii;
using ull = unsigned long long;

using namespace std;

const int mod = 1e9 + 7, MAXN = 400 + 4;

vi dx = {1, -1, 0, 0}, dy = {0, 0, 1, -1};
vs a;
vvi col;
map<int, int> g;
int cnt_v = 0;

bool normal (int x, int y, int n, int m)
{
    return x > -1 && y > -1 && x < n && y < m;
}

void dfs (int x, int y, int c)
{
    col[x][y] = c;
    ++cnt_v;
    int n = a.size(), m = a[0].size();
    for (int i = 0; i < 4; ++i)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (normal(nx, ny, n, m) && col[nx][ny] == -1 && a[nx][ny] == '.')
        {
            dfs(nx, ny, c);
        }
    }
}

int32_t main()
{
    //ofstream cout("test.txt");
    //ifstream cin("joseph.in");
    //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cerr.tie(0);
    int n, m;
    cin >> n >> m;
    a.resize(n);
    col = vvi (n, vi (m, -1));
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    int cnt_col = 1;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (col[i][j] == -1 && a[i][j] == '.')
            {
                cnt_v = 0;
                dfs(i, j, cnt_col);
                g[cnt_col] = cnt_v;
                ++cnt_col;
            }
        }
    }
    vs ans(n, "");
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (a[i][j] == '.')
            {
                ans[i].push_back('.');
            }
            else
            {
                int cnt = 1;
                set<int> cc;
                for (int k = 0; k < 4; ++k)
                {
                    int nx = i + dx[k], ny = j + dy[k];
                    if (normal(nx, ny, n, m) && a[nx][ny] == '.' && cc.count(col[nx][ny]) == 0)
                    {
                        cnt += g[col[nx][ny]];
                        cc.insert(col[nx][ny]);
                    }
                }
                cnt %= 10;
                ans[i].push_back('0' + cnt);
            }
        }
        cout << ans[i] << "\n";
    }
}

/*
*/
