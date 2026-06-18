//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#include <random>

#define int long long
#define double long double
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

const int mod = 1e9 + 93, ddl = 179;

vector<vector<pair<int, int> > > g, new_g, rev_new_g;
vector<int> min_col0, max_col0, min_coln, max_coln;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int> > edges(m, vector<int> (3, 0));
    g = vector<vector<pair<int, int> > > (n);
    for (int i = 0; i < m; ++i)
    {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
        --edges[i][0]; --edges[i][1];
        g[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        g[edges[i][1]].push_back({edges[i][0], edges[i][2]});
    }
    vector<int> dist0(n, 1e9), distn(n, 1e9);
    deque<int> q;
    dist0[0] = 0;
    distn[n - 1] = 0;

    q.push_back(0);
    while (!q.empty())
    {
        int start = q.front();
        q.pop_front();
        for (pair<int, int> uu : g[start])
        {
            int u = uu.first;
            if (dist0[u] == 1e9)
            {
                dist0[u] = dist0[start] + 1;
                q.push_back(u);
            }
        }
    }

    q.push_back(n - 1);
    while (!q.empty())
    {
        int start = q.front();
        q.pop_front();
        for (pair<int, int> uu : g[start])
        {
            int u = uu.first;
            if (distn[u] == 1e9)
            {
                distn[u] = distn[start] + 1;
                q.push_back(u);
            }
        }
    }

    if (dist0[n - 1] == 1)
    {
        cout << 1 << endl;
        cout << 1 << " " << n << endl;
        return;
    }

    int min_len = dist0[n - 1];
    vector<vector<int> > need_edges;
    new_g = vector<vector<pair<int, int> > > (n);
    rev_new_g = vector<vector<pair<int, int> > > (n);
    for (int i = 0; i < m; ++i)
    {
        int u = edges[i][0], v = edges[i][1];
        if (dist0[u] + distn[v] + 1 == min_len)
        {
            need_edges.push_back(edges[i]);
            new_g[u].push_back({v, edges[i][2]});
            rev_new_g[v].push_back({u, edges[i][2]});
        }
        else if (dist0[v] + distn[u] + 1 == min_len)
        {
            need_edges.push_back(edges[i]);
            new_g[v].push_back({u, edges[i][2]});
            rev_new_g[u].push_back({v, edges[i][2]});
        }
    }

    min_col0 = vector<int> (n, 1e9);
    max_col0 = vector<int> (n, -1e9);
    min_coln = vector<int> (n, 1e9);
    max_coln = vector<int> (n, -1e9);
    vector<int> pred_min_col0(n, -1), pred_max_col0(n, -1), pred_min_coln(n, -1), pred_max_coln(n, -1);
    vector<int> used(n, false);
    q.push_back(0);
    while (!q.empty())
    {
        int start = q.front();
        q.pop_front();
        if (used[start])
            continue;
        used[start] = true;
        for (pair<int, int> uu : new_g[start])
        {
            int u = uu.first, coll = uu.second;
            q.push_back(u);
            if (min(min_col0[start], coll) < min_col0[u])
            {
                min_col0[u] = min(min_col0[start], coll);
                pred_min_col0[u] = start;
            }
            if (max(max_col0[start], coll) > max_col0[u])
            {
                max_col0[u] = max(max_col0[start], coll);
                pred_max_col0[u] = start;
            }
        }
    }

    used = vector<int> (n, false);
    q.push_back(n - 1);
    while (!q.empty())
    {
        int start = q.front();
        q.pop_front();
        if (used[start])
            continue;
        used[start] = true;
        for (pair<int, int> uu : rev_new_g[start])
        {
            int u = uu.first, coll = uu.second;
            q.push_back(u);
            if (min(min_coln[start], coll) < min_coln[u])
            {
                min_coln[u] = min(min_coln[start], coll);
                pred_min_coln[u] = start;
            }
            if (max(max_coln[start], coll) > max_coln[u])
            {
                max_coln[u] = max(max_coln[start], coll);
                pred_max_coln[u] = start;
            }
        }
    }

    int max1 = -1, ind1 = -1;
    int max2 = -1, ind2 = -1;
    for (int i = 1; i < n - 1; ++i)
    {
        if (max_coln[i] - min_col0[i] > max1)
        {
            max1 = max_coln[i] - min_col0[i];
            ind1 = i;
        }
        if (max_col0[i] - min_coln[i] > max2)
        {
            max2 = max_col0[i] - min_coln[i];
            ind2 = i;
        }
    }

    if (max1 > max2)
    {
        vector<int> ans;
        int d = ind1;
        while (d != -1)
        {
            ans.push_back(d);
            d = pred_min_col0[d];
        }
        reverse(all(ans));
        d = ind1;
        ans.pop_back();
        while (d != -1)
        {
            ans.push_back(d);
            d = pred_max_coln[d];
        }
        cout << ans.size() - 1 << endl;
        for (int elem : ans) cout << elem + 1 << " ";
        cout << endl;
    }
    else
    {
        vector<int> ans;
        int d = ind2;
        while (d != -1)
        {
            ans.push_back(d);
            d = pred_max_col0[d];
        }
        reverse(all(ans));
        d = ind2;
        ans.pop_back();
        while (d != -1)
        {
            ans.push_back(d);
            d = pred_min_coln[d];
        }
        cout << ans.size() - 1 << endl;
        for (int elem : ans) cout << elem + 1 << " ";
        cout << endl;
    }
}

int32_t main()
{
//  ofstream cout("sum.out");
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed;
    cout.precision(0);
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