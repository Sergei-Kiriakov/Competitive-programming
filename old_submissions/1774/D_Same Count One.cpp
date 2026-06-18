#include <bits/stdc++.h>

#define Please return
#define Accepted 0
// #define int long long
#define endl "\n"
// #define double long double

using namespace std;

constexpr int MAXN = 1e6 + 6, mod1 = 1e9 + 9, d = 179, mod2 = 1e9 + 7;

void solve ()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int> > a(n, vector<int> (m, 0));
    int cnt1 = 0;
    vector<int> cnt(n, 0);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> a[i][j];
            cnt1 += a[i][j];
            cnt[i] += a[i][j];
        }
    }
    if (cnt1 % n != 0)
    {
        cout << -1 << endl;
        return;
    }
    int need = cnt1 / n;
    vector<vector<int> > aha(m);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (a[i][j] == 1 && cnt[i] > need)
            {
                aha[j].push_back(i);
            }
        }
    }
    vector<vector<int> > ans;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m && cnt[i] < need; ++j)
        {
            while (aha[j].size() != 0 && cnt[aha[j].back()] <= need)
            {
                aha[j].pop_back();
            }
            if (a[i][j] == 0 && aha[j].size() != 0)
            { 
                ans.push_back({i + 1, aha[j].back() + 1, j + 1});
                ++cnt[i];
                --cnt[aha[j].back()];
                aha[j].pop_back();       
            }
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i)
    {
        cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << endl;
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
No brain
*/
