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

int gcd (int a, int b, int &x, int &y)
{
    if (a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }
    int x1, y1;
    int d = gcd (b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

void addmod (int &a, int n)
{
    a = a + n;
    if (a >= mod)
        a -= mod;
 }

void submod (int &a, int n)
{
    a = mod + a - n;
    if (a >= mod)
        a -= mod;
}

int inverse_mod(int a)
{
    int x, y, d = gcd(a, mod, x, y), k;
    return (mod * mod + x) % mod;
}

int binpow (int a, int n) {
	int res = 1;
	while (n) {
		if (n & 1)
			res = (res * a) % mod;
		a = (a * a) % mod;
		n >>= 1;
	}
	return (res % mod);
}

vi cnt;
vvi tree;
vb used;
string ans;

void dfs (int v, int p)
{
    cnt[v] = 0;
    for (int u : tree[v])
    {
        if (u != p && !used[u])
        {
            dfs(u, v);
            cnt[v] = cnt[u] + 1;
        }
    }
}

int centroid (int v, int n, int p)
{
    for (int u : tree[v])
    {
        if (u != p && !used[u] && cnt[u] > n / 2)
        {
            return centroid(u, n, v);
        }
    }
    return v;
}

int stay(int v, char c)
{
    for (int u : tree[v])
    {
        if (!used[u])
        {
            dfs(u, v);
            int w = centroid(u, cnt[u], v);
            ans[w] = c;
            used[w] = true;
            stay(w, c + 1);
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cerr.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int n;
    cin >> n;
    tree.resize(n);
    cnt.resize(n, 0);
    used.resize(n, false);
    ans.resize(n);
    for (int i = 0; i < n - 1; ++i)
    {
        int v, u;
        cin >> v >> u;
        --v;
        --u;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs(0, -1);
    int w = centroid (0, n, -1);
    used[w] = true;
    ans[w] = 'A';
    stay(w, 'B');
    for (int i = 0; i < n; ++i)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}

/*
*/
