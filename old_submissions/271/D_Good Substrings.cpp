#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#include <random>

#define int long long
#define double long double
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

const int mod1 = 1e9 + 93, ddl = 179, mod2 = 1e9 + 9;

void solve()
{
    int m = 26;
    string s, det;
    cin >> s >> det;
    int k;
    cin >> k;
    int n = s.size();
    vector<pair<int, int> > pows(n + 1, {1, 1});
    for (int i = 1; i < n + 1; ++i)
    {
        pows[i].first = pows[i - 1].first * ddl % mod1;
        pows[i].second = pows[i - 1].second * ddl % mod2;
    }
    set<pair<int, int> > c;
    for (int i = 0; i < n; ++i)
    {
        pair<int, int> now = {0, 0};
        int cnt = 0;
        for (int j = i; j < n; ++j)
        {
            now.first = (now.first + pows[j - i].first * s[j]) % mod1;
            now.second = (now.second + pows[j - i].second * s[j]) % mod2;
            cnt += (det[s[j] - 'a'] == '0');
            if (cnt <= k)
                c.insert(now);
        }
    }
    cout << c.size() << endl;
//    for (auto elem : c)
//        cout << elem << " ";
//    cout << endl;
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