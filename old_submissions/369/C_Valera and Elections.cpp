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

map<pii, int> ways;
vvi tree;
vpii wait;
vi ans;

void dfs(int v, int p)
{
    for (int u : tree[v])
    {
        if (u != p)
        {
            if (ways[{u, v}] == 2)
                wait.push_back({u, v});
            dfs(u, v);
            if (ways[{u, v}] == 2)
            {
                for (pii way : wait)
                {
                    int a, b;
                    tie(a, b) = way;
                    ways[{a, b}] = 3;
                    ways[{b, a}] = 3;
                }
                wait.clear();
                ans.push_back(u + 1);
            }
        }
    }
}

int32_t main()
{
    //ofstream cout("text.out");
    //ifstream cin("text.in");
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cerr.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int n;
    cin >> n;
    tree.resize(n);
    for (int i = 0; i < n - 1; ++i)
    {
        int v, u, t;
        cin >> v >> u >> t;
        --v;
        --u;
        ways[{v, u}] = t;
        ways[{u, v}] = t;
        tree[v].push_back(u);
        tree[u].push_back(v);
    }
    dfs(0, -1);
    cout << ans.size() << endl;
    for (int anss : ans)
    {
        cout << anss << " ";
    }
}

/*
*/