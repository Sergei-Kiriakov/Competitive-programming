//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
#include <random>

#define int long long
#define double long double
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

const int mod1 = 1e9 + 9, d = 179, mod2 = 1e9 + 93;

vector<int> cnt, sum;
vector<vector<int> > g;

void dfs (int v)
{
    sum[v] += cnt[v];
    for (int u : g[v])
    {
        dfs(u);
        sum[v] += sum[u];
    }
}

vector<int> prefix(string s)
{
    int n = s.size();
    vector<int> pi(n, 0);
    for (int i = 1; i < n; ++i)
    {
        int j = pi[i - 1];
        while (j > 0 and s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j]) ++j;
        pi[i] = j;
    }
    return pi;
}

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    vector<int> p = prefix(s);
//    for (int i = 0; i < n; ++i)
//        cout << p[i] << " ";
//    cout << endl;
    cnt = vector<int> (n + 1, 0);
    sum = vector<int> (n + 1, 0);
    g = vector<vector<int> > (n + 1);
    for (int i = 0; i < n; ++i)
    {
        g[p[i]].push_back(i + 1);
        ++cnt[p[i]];
    }
    dfs(0);
    vector<int> inds = {n - 1};
    int d = p[inds.back()] - 1;
    while (d != -1)
    {
        inds.push_back(d);
        d = p[inds.back()] - 1;
    }
    reverse(all(inds));
    cout << inds.size() << endl;
    for (int elem : inds)
        cout << elem + 1 << " " << sum[elem + 1] + 1 << endl;
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