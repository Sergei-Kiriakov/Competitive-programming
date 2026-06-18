//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#include <random>

#define int long long
#define double long double
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

const int mod = 1e9 + 93;

void solve()
{
    string s;
    cin >> s;
    vector<int> cnt(30, 0);
    int n = s.size();
    for (int i = 0; i < n; ++i)
    {
        ++cnt[s[i] - 'a'];
    }
    sort(all(cnt));
    reverse(all(cnt));
    int cnt_dif = 0;
    for (int i = 0; i < cnt.size(); ++i)
    {
        if (cnt[i] != 0)
            ++cnt_dif;
    }
    if (cnt_dif <= 4 and cnt[1] + cnt[2] > 1 and n > 3)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}

int32_t main()
{
//  ofstream cout("sum.out");
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed;
    cout.precision(7);
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