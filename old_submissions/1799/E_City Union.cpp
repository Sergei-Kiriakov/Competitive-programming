#include <bits/stdc++.h>

// #define int long long
#define endl "\n"

using namespace std;

const int mod = 998244353;

void solve();

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cerr.tie(nullptr);
    cout << fixed;
    cout.precision(15);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

vector<vector<int> > color;
vector<int> dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
vector<string> a;

void up(int n, int m)
{
    color = vector<vector<int> > (n, vector<int> (m, 0));
    a = vector<string> (n);
}

bool norm (int x, int y)
{
    int n = color.size(), m = color[0].size();
    return x > -1 && x < n && y > -1 && y < m;
}

void dfs (int x, int y, int col)
{
    color[x][y] = col;
    for (int i = 0; i < dx.size(); ++i)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (norm(nx, ny) && color[nx][ny] == 0 && a[nx][ny] == '#')
        {
            dfs(nx, ny, col);
        }
    }
}

void otvet ()
{
    int n = a.size(), m = a[0].size();
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cout << a[i][j];
        }
        cout << endl;
    }
}

void fill_gap ()
{
    int n = a.size(), m = a[0].size();
    vector<pair<int, int> > line(n, {-1, -1}), col(m, {-1, -1});
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (a[i][j] == '#')
            {
                if (line[i].first == -1)
                {
                    line[i].first = j;
                }
                line[i].second = j;
                if (col[j].first == -1)
                {
                    col[j].first = i;
                }
                col[j].second = i;
            }
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = line[i].first; j < line[i].second; ++j)
        {
            a[i][j] = '#';
        }
    }
    for (int j = 0; j < m; ++j)
    {
        for (int i = col[j].first; i < col[j].second; ++i)
        {
            a[i][j] = '#';
        }
    }
}

void findd(pair<int, int> &p1, pair<int, int> &p2, pair<int, int> &q1, pair<int, int> &q2)
{
    int n = a.size(), m = a[0].size();
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (color[i][j] == 1)
            {
                if (p1.first == -1)
                {
                    p1.first = i;
                }
                p2.first = i;
            }
           if (color[i][j] == 2)
           {
                if (q1.first == -1)
                {
                    q1.first = i;
                }
                q2.first = i;
           }
        }
    }
    for (int j = 0; j < m; ++j)
    {
        for (int i = 0; i < n; ++i)
        {
            if (color[i][j] == 1)
            {
                if (p1.second == -1)
                {
                    p1.second = j;
                }
                p2.second = j;
            }
           if (color[i][j] == 2)
           {
                if (q1.second == -1)
                {
                    q1.second = j;
                }
                q2.second = j;
           }
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    up(n, m);
    for (int i = 0; i < n; ++i) cin >> a[i];
    fill_gap();
    fill_gap();
    int cnt_obl = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (color[i][j] == 0 && a[i][j] == '#')
            {
                ++cnt_obl;
                dfs(i, j, cnt_obl);
            }
        }
    }
    if (cnt_obl == 1)
    {
        fill_gap();
        fill_gap();
        otvet();
        return;
    }
    pair<int, int> p1 = {-1, -1}, p2 = {-1, -1}, q1 = {-1, -1}, q2 = {-1, -1};
    findd(p1, p2, q1, q2);
    if (q1.second < p1.second)
    {
        swap(q1, p1);
        swap(q2, p2);
    }
    if (p1.first > q1.first)
    {
        for (int j = p2.second; j <= q1.second; ++j)
        {
            a[p1.first][j] = '#';
        }
        for (int i = q2.first; i <= p1.first; ++i)
        {
            a[i][q1.second] = '#';
        }
    }
    else
    {
        for (int j = p2.second; j <= q1.second; ++j)
        {
            a[p2.first][j] = '#';
        }
        for (int i = p2.first; i <= q1.first; ++i)
        {
            a[i][q1.second] = '#';
        }
    }
    fill_gap();
    fill_gap();
    otvet();
}

/*
...
*/