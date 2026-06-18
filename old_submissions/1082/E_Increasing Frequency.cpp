//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
//#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;


const int mod = 1e9 + 7;

int solve(int n, int c, vector<int> a)
{
    int big = 5e5 + 5;
    vector<int> cnt(big, 0);
    vector<vector<pair<int, int> > > cc(big);
    for (int i = 0; i < n; ++i)
    {
        ++cnt[a[i]];
        if (a[i] != c)
        {
            int dd = cnt[a[i]] - cnt[c];
            cc[a[i]].push_back({dd, i});
        }
    }
    for (int i = 0; i < big; ++i)
    {
        sort(all(cc[i]));
    }
    vector<int> pred(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        pred[i] = pred[i - 1] + (a[i - 1] == c);
    }
    int ans = cnt[c];
    int baza = ans;
    vector<int> cnt1(big, 0);
    for (int i = 0; i < n; ++i)
    {
        if (a[i] != c)
        {
            int div = cc[a[i]].back().first, ind = cc[a[i]].back().second;
            while (!cc.empty() and ind < i)
            {
                cc[a[i]].pop_back();
                if (!cc.empty())
                {
                    div = cc[a[i]].back().first;
                    ind = cc[a[i]].back().second;
                }
            }
            if (ind >= i)
                ans = max(ans, div + cnt1[c] - cnt1[a[i]] + baza);
        }
        ++cnt1[a[i]];
    }
    return ans;
}

int solve1(int n, int c, vector<int> a)
{
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == c)
            ++ans;
    }
    for (int l = 0; l < n; ++l)
    {
        for (int r = l; r < n; ++r)
        {
            int ans1 = 0;
            for (int j = 0; j < l; ++j)
            {
                ans1 += (a[j] == c);
            }
            for (int j = r + 1; j < n; ++j)
            {
                ans1 += (a[j] == c);
            }
            map<int, int> t;
            for (int j = l; j <= r; ++j)
            {
                ++t[a[j]];
            }
            int max1 = 0;
            for (auto it = t.begin(); it != t.end(); ++it)
            {
                int dd = (*it).second;
                max1 = max(max1, dd);
            }
            ans1 += max1;
            ans = max(ans1, ans);
        }
    }
    return ans;
}

int32_t main()
{
    //ofstream cout("sum.out");
    //ifstream cin("sum.in");
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed;
    cout.precision(15);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    //
    int n, c;
    cin >> n >> c;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    cout << solve(n, c, a) << endl;
    //
//    for (int tt = 0; tt < 100; ++tt)
//    {
//        int n = rng() % 10 + 1, c = rng() % 10 + 1;
//        vector<int> a(n);
//        for (int i = 0; i < n; ++i)
//        {
//            a[i] = rng() % 10 + 1;
//        }
//        if (solve(n, c, a) != solve1(n, c, a))
//        {
//            cout << "ERROR:" << endl;
//            cout << n << " " << c << endl;
//            for (int i = 0; i < n; ++i)
//            {
//                cout << a[i] << " ";
//            }
//            cout << endl;
//            cout << solve(n, c, a) << " " << solve1(n, c, a) << endl;
//            cout << "-------------------" << endl;
//        }
//    }
}


/*
*/