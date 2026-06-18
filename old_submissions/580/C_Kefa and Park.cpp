#include <bits/stdc++.h>
#define int long long
#define double long double

typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
typedef std::vector<vvi> vvvi;
typedef std::vector<vvvi> vvvvi;
typedef std::vector<std::string> vs;
typedef std::vector<bool> vb;
typedef std::vector<vb> vvb;
typedef std::vector<double> vd;
typedef std::vector<vd> vvd;
typedef std::pair<int, int> pii;
typedef std::vector<pii> vpii;
typedef std::vector<vpii> vvpii;
using ull = unsigned long long;

using namespace std;

constexpr int mod = 1e9 + 7, p = 179;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> have_cat(n);
    vector<vector<int> > g(n);
    vector<bool> used(n, false);
    for (int i = 0; i < n; ++i)
    {
        cin >> have_cat[i];
    }
    for (int i = 0; i < n - 1; ++i)
    {
        int v, w;
        cin >> v >> w;
        --v; --w;
        g[w].push_back(v);
        g[v].push_back(w);
    }
    vector<int> leafs;
    for (int i = 1; i < n; ++i)
    {
        if (g[i].size() == 1)
        {
            leafs.push_back(i);
            //cout << i << " ";
        }
    }
    //cout << endl;
    deque<pair<int, int> > q;
    q.push_back({0, have_cat[0]});
    used[0] = true;
    while (!q.empty())
    {
        int v = q.front().first, cnt_cats = q.front().second;
        q.pop_front();
        for (int w : g[v])
        {
            if (!used[w] && m >= cnt_cats + have_cat[w])
            {
                used[w] = true;
                if (have_cat[w] == 0)
                    q.push_back({w, 0});
                else
                    q.push_back({w, cnt_cats + have_cat[w]});
            }
        }
    }
    int ans = 0;
    for (int v : leafs)
    {
        ans += used[v];
    }
    cout << ans << "\n";
}

int32_t main()
{
    //ofstream cout("test.txt");
    //ifstream cin("joseph.in");
    //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cerr.tie(0);
    solve();
    //solve();
    return 0;
}
