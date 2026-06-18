#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#include <random>

#define int long long
#define double long double
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

const int mod = 1e9 + 7, ddl = 179;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    deque<int> q;
    vector<int> cnt(k + 1, 0);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        q.push_front(a[i]);
        ++cnt[a[i]];
    }
    vector<int> ans(k);
    for (int i = 1; i < k + 1; ++i)
    {
        if (cnt[i] == 0)
            ans[i - 1] = 0;
        else
            ans[i - 1] = q.size() * 2;
        while (!q.empty() and q.front() <= i)
            q.pop_front();
        while (!q.empty() and q.back() <= i)
            q.pop_back();
    }
    for (int elem : ans) cout << elem << " ";
    cout << endl;
}

int32_t main()
{
//  ofstream cout("sum.out");
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed;
    cout.precision(0);
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