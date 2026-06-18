#include <bits/stdc++.h>
#define int int64_t

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

constexpr int mod = 1e9 + 7, p = 179;

vi parent, sz;
vvi blocks;
vi col, max_c, ans;
vvi tree;
vector<map<int, int> > cnt_col;
vi anss;

void init (int n)
{
    anss = max_c = ans = col = parent = sz = vi (n);
    tree = blocks = vvi(n);
    cnt_col = vector<map<int, int> > (n);
    for (int i = 0; i < n; ++i)
    {
        parent[i] = i;
        sz[i] = 1;
        blocks[i].push_back(i);
        max_c[i] = 1;
    }
}

int get_parent (int u)
{
    if (parent[u] == u)
        return u;
    parent[u] = get_parent(parent[u]);
    return parent[u];
}

void connect (int u, int v)
{
    u = get_parent(u);
    v = get_parent(v);
    if (u == v)
        return;
    if (sz[u] < sz[v])
    {
        swap(u, v);
    }
    parent[v] = u;
    for (int w : blocks[v])
    {
        blocks[u].push_back(w);
        int color = col[w];
        ++cnt_col[u][color];
        if (cnt_col[u][color] > max_c[u])
        {
            max_c[u] = cnt_col[u][color];
            ans[u] = color;
        }
        else if (cnt_col[u][color] == max_c[u])
        {
            ans[u] += color;
        }
    }
    sz[u] += sz[v];
}

void dfs (int v, int p)
{
    for (int u : tree[v])
    {
        if (u != p)
        {
            dfs(u, v);
        }
    }
    anss[v] = ans[get_parent(v)];
    if (p != -1)
        connect(v, p);
}

int32_t main()
{
    //ofstream cout("cutting.out");
    //ifstream cin("cutting.in");
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cerr.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int n;
    cin >> n;
    init (n);
    for (int i = 0; i < n; ++i)
    {
        int c;
        cin >> c;
        col[i] = c;
        ans[i] = c;
        cnt_col[i][c] = 1;
    }
    for (int i = 0; i < n - 1; ++i)
    {
        int v, u;
        cin >> v >> u;
        --v;
        --u;
        tree[v].push_back(u);
        tree[u].push_back(v);
    }
    dfs(0, -1);
    for (int i = 0; i < n; ++i)
    {
        cout << anss[i] << " ";
    }
    cout << endl;
}

/*
*/
