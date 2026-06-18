//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;


const int mod = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<pair<int, int> > b(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        b[i] = {a[i], i};
    }
    sort(all(b));
    int ans = 0;
    for (int i = 1; i < n; ++i)
    {
        if (b[i].second < b[i - 1].second)
        {
            ++ans;
        }
    }
    cout << ans << endl;
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
    cin >> tt;
    while(tt-->0)
    {
        solve();
    }
}


/*
*/