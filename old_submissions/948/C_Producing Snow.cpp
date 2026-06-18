//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#include <random>

#define int long long
#define double long double
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

const int mod = 1e9 + 93, big = 2e6;

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n), t(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    for (int i = 0; i < n; ++i) cin >> t[i];
    int now = 0;
    priority_queue<int, vector<int>, greater<int>> d;
    for (int i = 0; i < n; ++i)
    {
        d.push(now + v[i]);
        now += t[i];
        int ans = 0;
        while (!d.empty() and d.top() <= now)
        {
            ans += d.top() - now + t[i];
            d.pop();
        }
        ans += t[i] * d.size();
        cout << ans << " ";
    }
    cout << endl;
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