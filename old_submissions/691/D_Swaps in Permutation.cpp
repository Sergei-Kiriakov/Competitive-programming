#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > t;
vector<int> col;
vector<int> ans;
int c = 1;

void dfs (int v)
{
    ans.push_back(v);
    col[v] = c;
    for (int u : t[v])
    {
        if (col[u] == -1)
        {
            dfs(u);
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cerr.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    col.resize(n, -1);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    t.resize(n);
    for (int i = 0; i < m; ++i)
    {
        int v, u;
        cin >> v >> u;
        --v; --u;
        t[v].push_back(u);
        t[u].push_back(v);
    }
    vector<int> anss(n);
    for (int i = 0; i < n; ++i)
    {
        if (col[i] == -1)
        {
            ans.clear();
            ++c;
            dfs(i);
            vector<int> d;
            for (int i = 0; i < ans.size(); ++i)
            {
                d.push_back(a[ans[i]]);
            }
            sort(ans.begin(), ans.end());
            sort(d.rbegin(), d.rend());
            for (int i = 0; i < ans.size(); ++i)
            {
                anss[ans[i]] = d[i];
            }
        }
    }
    for (int i = 0; i < n; ++i)
    {
        cout << anss[i] << " ";
    }
    cout << "\n";
}
