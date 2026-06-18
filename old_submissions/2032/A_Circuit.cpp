//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

constexpr int mod = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(2 * n);
    int sum = 0;
    for (int i = 0; i < 2 * n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    int ans1 = 0, ans2 = 0;
    if (sum % 2 == 0)
        ans1 = 0;
    else
        ans1 = 1;
    if (sum <= n)
        ans2 = sum;
    else
        ans2 = 2 * n - sum;
    cout << ans1 << " " << ans2 << endl;
}

int32_t main()
{
//    ofstream cout("");
//    ifstream cin("");
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed;
    cout.precision(7);
    int tt = 1;
    cin >> tt;
    while(tt-->0)
    {
        solve();
    }
}

/*
*/  