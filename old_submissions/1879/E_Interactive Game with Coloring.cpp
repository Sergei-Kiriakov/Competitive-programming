//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
//#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

constexpr int mod = 998244353;

vector<vector<int> > g;
vector<vector<int> > col;

void dfs (int v, int p = -1)
{
    if (v == 0)
        return;
    col.back()[v] = (col.back()[p] + 1) % 2;
    for (int u : g[v])
    {
        if (u == p)
            continue;
        dfs(u, v);
    }
}

void dfs1 (int v, int p = -1)
{
    for (int u : g[v])
    {
        if (u == p)
            continue;
        col.back()[u] = (col.back()[v] + 1) % 3;
        dfs1(u, v);
    }
}

void solve()
{
    int n;
    cin >> n;
    g.resize(n);
    vector<int> a(n, -1);
    for (int i = 1; i < n; ++i)
    {
        int p;
        cin >> p;
        --p;
        a[i] = p;
        g[i].push_back(p);
        g[p].push_back(i);
    }
    int cnt1 = 0;
    bool adj2 = false;
    for (int i = 1; i < n; ++i)
    {
        cnt1 += (g[i].size() == 1);
        if (g[i].size() == 2)
        {
            col.push_back(vector<int> (n, -1));
            col.back()[a[i]] = 1;
            dfs(i, a[i]);
            dfs(a[i], i);
        }
    }
    int t = 1;
    for (int l = 0; l < col.size(); ++l)
        for (int i = l + 1; i < col.size(); ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (col[i][j] == -1)
                    continue;
                if (col[l][j] == -1)
                    continue;
                if (col[i][j] != col[l][j])
                    adj2 = true;
            }
        }
    if (cnt1 == n - 1)
    {
        cout << 1 << "\n";
        for (int i = 0; i < n - 1; ++i)
            cout << 1 << " ";
        cout << endl;
        int flag;
        cin >> flag;
        while (flag == 0)
        {
            int d1;
            cin >> d1;
            cout << 1 << endl;
            cin >> flag;
        }
    }
    else if (!adj2)
    {
        col.push_back(vector<int> (n, -1));
        for (int i = 0; i < col.size() - 1; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (col.back()[j] == -1 and col[i][j] != -1)
                    col.back()[j] = col[i][j];
            }
        }
        for (int u : g[0])
        {
            if (col.back()[u] == -1)
                dfs(u, 0);
        }
        cout << 2 << "\n";
        for (int i = 1; i < n; ++i)
            cout << col.back()[i] + 1 << " ";
        cout << endl;
        int flag;
        cin >> flag;
        while (flag == 0)
        {
            int d1, d2;
            cin >> d1 >> d2;
            if (d2 == 0)
            {
                cout << 1 << endl;
            }
            else if (d1 == 0)
            {
                cout << 2 << endl;
            }
            else if (d1 < d2)
            {
                cout << 1 << endl;
            }
            else if (d2 < d1)
            {
                cout << 2 << endl;
            }
            else
            {
                cout << 1 << endl;
            }
            cin >> flag;
        }
    }
    else
    {
        col.push_back(vector<int> (n, -1));
        dfs1(0);
        cout << 3 << "\n";
        for (int i = 1; i < n; ++i)
            cout << col.back()[i] + 1 << " ";
        cout << endl;
        int flag;
        cin >> flag;
        while (flag == 0)
        {
            int d1, d2, d3;
            cin >> d1 >> d2 >> d3;
            if (d1 == 0 and d2 == 0)
                cout << 3 << endl;
            else if (d1 == 0 and d3 == 0)
                cout << 2 << endl;
            else if (d2 == 0 and d3 == 0)
                cout << 1 << endl;
            else if (d1 == 0)
                cout << 2 << endl;
            else if (d3 == 0)
                cout << 1 << endl;
            else
                cout << 3 << endl;
            cin >> flag;
        }
    }
}

int32_t main()
{
//    ofstream cout("sum.out");
//    ifstream cin("sum.in");
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed;
    cout.precision(9);
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