#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define int long long
#define endl "\n"
#define double long double

using namespace std;

constexpr int MAXN = 1e6 + 6, mod = 1e9 + 7, d = 179;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<pair<int, int> > ans;
    set<pair<int, int> > s;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        s.insert({a[i], i});
    }
    if ((*s.begin()).first == (*(--s.end())).first)
    {
        cout << 0 << endl;
        return;
    }
    while ((*s.begin()).first != (*(--s.end())).first && (*s.begin()).first != 1)
    {
        pair<int, int> f1 = *(--s.end()), f2 = (*s.begin());
        s.erase(--s.end());
        ans.push_back({f1.second, f2.second});
        s.insert({(f1.first - 1) / f2.first + 1, f1.second});
    }
    if ((*s.begin()).first != (*(--s.end())).first)
    {
        cout << -1 << endl;
        return;
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i)
    {
        cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cerr.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solve();
    }
}

/*
1
3
4 3 2
*/