#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

//#define int long long
//#define double long double
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

constexpr int mod1 = 1e9 + 7, mod2 = 1e9 + 9;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int> > a(n, vector<int> (n, -1e9));
    for (int i = 0; i < n; ++i)
    {
        for (int j = i; j < n; ++j)
        {
            cin >> a[i][j];
        }
    }
    vector<vector<vector<int> > > dp(n + 1, vector<vector<int > > (2));
    dp[0][0] = {0};
    for (int i = 1; i < n + 1; ++i)
    {
        vector<int> temp;
        for (int el : dp[i - 1][0])
            temp.push_back(el);
        for (int el : dp[i - 1][1])
            temp.push_back(el);
        sort(temp.rbegin(), temp.rend());
        while(temp.size() > k)
            temp.pop_back();
        dp[i][0] = temp;
        vector<int> temp1;
        multiset<pair<int, int> > pp;
        for (int j = 1; j <= i; ++j)
        {
            pp.insert({a[j - 1][i - 1] + dp[j - 1][0][0], j - 1});
        }
        vector<int> cnt(n + 1, 1);
        while (temp1.size() < k and !pp.empty())
        {
            int xx = (*(--pp.end())).first, jj = (*(--pp.end())).second;
            temp1.push_back(xx);
            pp.erase({xx, jj});
            if (dp[jj][0].size() > cnt[jj])
            {
                pp.insert({a[jj][i - 1] + dp[jj][0][cnt[jj]], jj});
                ++cnt[jj];
            }
        }
        dp[i][1] = temp1;
    }
    vector<int> temp;
    for (int el : dp[n][0])
        temp.push_back(el);
    for (int el : dp[n][1])
        temp.push_back(el);
    sort(temp.rbegin(), temp.rend());
    while(temp.size() > k)
        temp.pop_back();
    for (int i = 0; i < k; ++i)
        cout << temp[i] << " ";
    cout << endl;
}

int32_t main()
{
//    ofstream cout("std.out");
//    ifstream cin("std.in");
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed;
//    cout.precision(7);
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