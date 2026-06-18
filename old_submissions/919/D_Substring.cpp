#include <bits/stdc++.h>
#define int long long

typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
typedef std::vector<vvi> vvvi;
typedef std::vector<std::string> vs;
typedef std::vector<bool> vb;
typedef std::vector<vb> vvb;
typedef std::vector<double> vd;
typedef std::vector<vd> vvd;
typedef std::pair<int, int> pii;
typedef std::vector<pii> vpii;
typedef std::vector<vpii> vvpii;

using namespace std;

constexpr int mod = 998244353, p = 179;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vvi tree;
vi color;
bool er;
vvi ans;
string s;

void init(int n)
{
    color = vi (n + 1, 0);
    tree = vvi (n + 1);
    er = false;
    ans = vvi (n + 1, vi (32, 0));
    for (int i = 1; i < n + 1; ++i)
    {
        ans[i][s[i - 1] - 'a'] = 1;
    }
}

void update (int v, int u)
{
    for (int i = 0; i < 32; ++i)
    {
        ans[v][i] = max(ans[u][i] + ((s[v - 1] - 'a') == i), ans[v][i]);
    }
}

void dfs (int v, int p)
{
    for (int u : tree[v])
    {
        if (u == p || u == v)
        {
            er = true;
        }
        else
        {
            if (color[u] == 0)
            {
                color[u] = 1;
                dfs(u, v);
                color[u] = 2;
                update(v, u);
            }
            else if (color[u] == 1)
            {
                er = true;
            }
            else
            {
                update(v, u);
            }
        }
    }
}

int32_t main()
{
    //ofstream cout("cutting.out");
    //ifstream cin("cutting.in");
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cerr.tie(0);
    int n, m;
    cin >> n >> m;
    cin >> s;
    init(n);
    for (int i = 0; i < m; ++i)
    {
        int v, u;
        cin >> v >> u;
        tree[v].push_back(u);
    }
    for (int i = 1; i < n + 1; ++i)
    {
        if (color[i] == 0)
        {
            dfs(i, -1);
        }
    }
    if (er)
    {
        cout << -1 << endl;
    }
    else
    {
        int anss = 0;
        for (int i = 1; i < n + 1; ++i)
        {
            for (int j = 0; j < 32; ++j)
            {
                anss = max(anss, ans[i][j]);
            }
        }
        cout << anss << endl;
    }
}

/*
8
1 1 3 1 2 8 8 1
2 3
*/
