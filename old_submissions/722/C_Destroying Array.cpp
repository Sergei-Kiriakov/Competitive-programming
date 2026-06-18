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

constexpr int mod = 1e9 + 7, p = 179;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vi parent, sz, sum;

void init (int n, vi &a)
{
    sum = parent = sz = vi (n);
    for (int i = 0; i < n; ++i)
    {
        sz[i] = 1;
        parent[i] = i;
        sum[i] = a[i];
    }
}

int get_parent (int u)
{
    if (parent[u] == u)
    {
        return u;
    }
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
    sz[u] += sz[v];
    parent[v] = u;
    sum[u] += sum[v];
}

int32_t main()
{
    //ofstream cout("cutting.out");
    //ifstream cin("cutting.in");
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cerr.tie(0);
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    init(n, a);
    vi ask(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> ask[i];
        --ask[i];
    }
    int max1 = 0;
    vi ans(n);
    vb alive(n, false);
    for (int i = n - 1; i > -1; --i)
    {
        ans[i] = max1;
        int x = ask[i];
        alive[x] = true;
        if (x - 1 > -1 && alive[x - 1])
        {
            connect(x, x - 1);
        }
        if (x + 1 < n && alive[x + 1])
        {
            connect(x, x + 1);
        }
        x = get_parent(x);
        max1 = max(max1, sum[x]);
    }
    for (int u : ans)
    {
        cout << u << endl;
    }
}

/*
8
1 1 3 1 2 8 8 1
2 3
*/
