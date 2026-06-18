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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> cnt(n + 1, 0);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        ++cnt[a[i]];
    }
    int el = -1;
    for (int i = 0; i < n + 1; ++i)
    {
        if (cnt[i] == 0)
            el = i;
    }
    vector<int> b(n + 1);
    b[0] = el;
    for (int i = 0; i < n; ++i)
    {
        b[i + 1] = a[i];
    }
    int r = ((n + 1) * mod + n - k) % (n + 1);
    vector<int> ans;
    for (int i = 0; i < n; ++i)
    {
        int j = ((n + 1) + r - i) % (n + 1);
        ans.push_back(b[j]);
    }
    reverse(all(ans));
    for (int i = 0; i < n; ++i)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
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