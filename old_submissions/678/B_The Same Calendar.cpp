#include <bits/stdc++.h>
#define int int64_t
#define double long double

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

constexpr int mod = 1e9 + 7, p = 179, MAXN = 1e7 + 1;

vvi tree;
int ans = 0;
vi d, a;

void dfs (int v, int p)
{
    for (int u : tree[v])
    {
        if (u != p)
        {
            dfs(u, v);
            if (d[v] == 0)
            {
                d[v] = d[u];
            }
            else if (d[v] > d[u])
            {
                ans += d[v];
                d[v] = d[u];
            }
            else
            {
                ans += d[u];
            }
        }
    }
    d[v] = max(d[v], a[v]);
}

void init(int n)
{
    ans = 0;
    a.clear();
    a.resize(n + 1, 0);
    tree.clear();
    tree.resize(n + 1);
    d.clear();
    d.resize(n + 1);
}

void solve()
{
    int n;
    cin >> n;
    init(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i + 1];
    }
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        tree[x].push_back(i + 1);
    }
    dfs(0, -1);
    ans += d[0];
    cout << ans << "\n";
}

int32_t main()
{
    //ofstream cout("cutting.out");
    //ifstream cin("cutting.in");
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cerr.tie(0);
    int y;
    cin >> y;
    bool flag = ((y % 400 == 0) || (y % 4 == 0 && y % 100 != 0));
    int c = 1000;
    int k = 0;
    for (int i = c + 1; i <= y; ++i)
    {
        if ((i % 400 == 0) || (i % 4 == 0 && i % 100 != 0))
        {
            k += 366 % 7;
        }
        else
        {
            k += 365 % 7;
        }
        k %= 7;
    }
    int k1 = k;
    int i = y + 1;
    for (; true; ++i)
    {
        if ((i % 400 == 0) || (i % 4 == 0 && i % 100 != 0))
        {
            k1 += 366 % 7;
        }
        else
        {
            k1 += 365 % 7;
        }
        k1 %= 7;
        if (k1 == k && ((i % 400 == 0) || (i % 4 == 0 && i % 100 != 0)) == flag)
            break;
    }
    cout << i << "\n";
}

/*
5
1 2 3 4 5
1 3
2 3
*/
