//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

const int mod1 = 1e9 + 93, mod2 = 1e9 + 21, d = 179;

void solve()
{
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<pair<int, int> > a(m);
    for (int i = 0; i < m; ++i)
    {
        cin >> a[i].first >> a[i].second;
//        --a[i].first; --a[i].second;
    }
    vector<pair<int, int> > h0(n + 1, {0, 0}), h1(n + 1, {0, 0});
    vector<pair<int, int> > pw(n + 1, {1, 1});
    vector<pair<int, int> > hashs1(n + 1, {0, 0});
    vector<int> cnt0(n + 1, 0), cnt1(n + 1, 0);
    for (int i = 1; i < n + 1; ++i)
    {
        h0[i].first = (h0[i - 1].first * d + '0') % mod1;
        h0[i].second = (h0[i - 1].second * d + '0') % mod2;
        h1[i].first = (h1[i - 1].first * d + '1') % mod1;
        h1[i].second = (h1[i - 1].second * d + '1') % mod2;
        pw[i].first = (pw[i - 1].first * d) % mod1;
        pw[i].second = (pw[i - 1].second * d) % mod2;
        hashs1[i].first = (hashs1[i - 1].first * d + s[i - 1]) % mod1;
        hashs1[i].second = (hashs1[i - 1].second * d + s[i - 1]) % mod2;
        cnt0[i] = cnt0[i - 1] + (s[i - 1] == '0');
        cnt1[i] = cnt1[i - 1] + (s[i - 1] == '1');
    }
    set<pair<int, int> > ans;
    pair<int, int> hash = hashs1[n];
    for (int i = 0; i < m; ++i)
    {
        int l = a[i].first, r = a[i].second;
        int c0 = cnt0[r] - cnt0[l - 1], c1 = cnt1[r] - cnt1[l - 1];
        int new_hash1 = (hash.first - hashs1[r].first * pw[n - r].first + mod1 * mod1) % mod1;
        new_hash1 = (new_hash1 + hashs1[l - 1].first * pw[n - l + 1].first) % mod1;
        int new_hash2 = (hash.second - hashs1[r].second * pw[n - r].second + mod2 * mod2) % mod2;
        new_hash2 = (new_hash2 + hashs1[l - 1].second * pw[n - l + 1].second) % mod2;
        int plus1 = (h0[c0].first * pw[n - (l + c0) + 1].first + h1[c1].first * pw[n - r].first) % mod1;
        int plus2 = (h0[c0].second * pw[n - (l + c0) + 1].second + h1[c1].second * pw[n - r].second) % mod2;
        new_hash1 = (new_hash1 + plus1) % mod1;
        new_hash2 = (new_hash2 + plus2) % mod2;
        ans.insert({new_hash1, new_hash2});
    }
    cout << ans.size() << endl;
}

int32_t main()
{
//    ofstream cout("sum.out");
//    ifstream cin("sum.in");
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed;
    cout.precision(15);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int tt = 1;
    cin >> tt;
    while(tt-->0)
    {
        solve();
    }
}


/*
*/