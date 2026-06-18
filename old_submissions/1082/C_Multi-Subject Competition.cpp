//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
//#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;


const int mod = 1e9 + 7;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int> > pred(m);
    for (int i = 0; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        --a;
        pred[a].push_back(b);
    }
    for (int i = 0; i < m; ++i)
    {
        sort(all(pred[i]));
        reverse(all(pred[i]));
    }
    vector<int> ans(n, 0);
    vector<vector<int> > pref(m);
    for (int i = 0; i < m; ++i)
    {
        int ss = 0;
        for (int j = 0; j < pred[i].size(); ++j)
        {
            ss += pred[i][j];
            if (ss > 0)
            {
                ans[j] += ss;
            }
        }
    }
    int anss = 0;
    for (int i = 0; i < n; ++i)
    {
        anss = max(ans[i], anss);
    }
    cout << anss << endl;
}

int32_t main()
{
    //ofstream cout("sum.out");
    //ifstream cin("sum.in");
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed;
    cout.precision(15);
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