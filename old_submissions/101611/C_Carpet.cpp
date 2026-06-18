#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#include <random>

//#define int long long
//#define double long double
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

const int mod = 998244353, big = 2e6;

vector<vector<int> > g;
vector<bool> g_used, used;
int ind, deep;
vector<pair<int, int> > anss;
vector<int> pred;
vector<int> xs;

void dfs(int v, int p = -1, int d = 0)
{
    if (d > deep)
    {
        deep = d;
        ind = v;
    }
    pred[v] = p;
    for (int u : g[v])
    {
        if (u == p)
            continue;
        if (g_used[u])
            continue;
        dfs(u, v, d + 1);
    }
}

void refresh(int n)
{
    ind = -1;
    deep = -1;
}

pair<int, int> find_d (int v = 0)
{
    int n = g.size();
    refresh(n);
    dfs(v);
    int u = ind;
//    refresh(n);
//    dfs(u);
//    int w = ind;
    return {v, u};
}

void f(int v, int y)
{
    pair<int, int> p = find_d(v);
    vector<int> path;
    int start = p.first, finish = p.second;
    pred[start] = -1;
    while (finish != -1)
    {
        path.push_back(finish);
        finish = pred[finish];
    }
    reverse(all(path));
    for (int i = 0; i < path.size(); ++i)
    {
        int u = path[i];
        g_used[u] = true;
        anss[u] = {xs[y], y};
        ++xs[y];
    }
    int ttt = 0;
    for (int u : path)
    {
        for (int w : g[u])
        {
            if (g_used[w])
                continue;
            f(w, y + 1);
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    g = vector<vector<int> > (n);
    g_used = vector<bool> (n, false);
    anss = vector<pair<int, int> > (n, {-1, -1});
    xs = vector<int> (21, 0);
    pred = vector<int> (n, -1);
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    f(0, 0);
    for (int i = 0; i < n; ++i)
    {
        cout << anss[i].first + 1 << " " << anss[i].second + 1 << endl;
    }
//    cout << endl;
}

int32_t main()
{
//  ofstream cout("sum.out");
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