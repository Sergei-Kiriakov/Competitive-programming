#include <bits/stdc++.h>
#define int long long
#define double long double

using vi = std::vector<int>;
using vvi = std::vector<vi>;
using vvvi = std::vector<vvi>;
using vvvvi = std::vector<vvvi>;
using vb = std::vector<bool>;
using vvb = std::vector<vb>;
using pii = std::pair<int, int>;
using vpii = std::vector<pii>;
using vvpii = std::vector<vpii>;
using mii = std::map<int, int>;
using ull = unsigned long long;
using vs = std::vector<std::string>;

using namespace std;

constexpr int MOD = 1e9 + 7, P = 179, maxn = 300 + 3;

vvpii parent;
vvi ans, sz;
vs a;

void init (int n, int m)
{
    parent = vvpii(n, vpii(m));
    ans = vvi(n, vi (m));
    sz = vvi(n, vi(m, 1));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            parent[i][j] = {i, j};
            ans[i][j] = (j - 1 > -1 && a[i][j - 1] == '*') + (j + 1 < m && a[i][j + 1] == '*') + (i + 1 < n && a[i + 1][j] == '*') + (i - 1 > -1 && a[i - 1][j] == '*');
        }
    }
}

pii get_parent (pii v)
{
    int v1 = v.first, v2 = v.second;
    if (parent[v1][v2] == v)
        return {v1, v2};
    parent[v1][v2] = get_parent(parent[v1][v2]);
    return parent[v1][v2];
}

void connect(pii v, pii w)
{
    //cerr << -4;
    v = get_parent(v);
    w = get_parent(w);
    //cerr << -5;
    if (v == w)
        return;
    int w1 = w.first, w2 = w.second, v1 = v.first, v2 = v.second;
    //cerr << -3;
    if (sz[w1][w2] > sz[v1][v2])
    {
        swap(v1, w1);
        swap(v2, w2);
    }
    parent[w1][w2] = {v1, v2};
    sz[v1][v2] += sz[w1][w2];
    ans[v1][v2] += ans[w1][w2];
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cerr.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    a.resize(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    init(n, m);
    vi dx = {1, -1, 0, 0}, dy = {0, 0, -1, 1};
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            for (int l = 0; l < 4; ++l)
            {
                //cerr << i << " " << j << " " << l << endl;
                if (a[i][j] == '.' && a[i + dx[l]][j + dy[l]] == '.')
                {
                    //cerr << i << " " << j << " " << l << endl;
                    connect({i, j}, {i + dx[l], j + dy[l]});
                }
            }
        }
    }
    //cerr << -1;
    for (int i = 0; i < k; ++i)
    {
        int x, y;
        cin >> x >> y;
        --x; --y;
        tie(x, y) = get_parent({x, y});
        cout << ans[x][y] << "\n";
    }
}

/*
*/
