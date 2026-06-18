//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

constexpr int mod = 1e9 + 7;

bool check (vector<int>& a, int k, int need)
{
    int sum = 0;
    for (size_t i = 0; i < a.size(); ++i)
    {
        sum += max(0ll, need - a[i]);
        if (sum > k)
            return false;
    }
    return sum <= k;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(all(a));
    int l = 0, r = 1e14;
    while (r - l > 1)
    {
        int mid = (r + l) / 2;
        if (check(a, k, mid))
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    int ans = 0;
    for (size_t i = 0; i < n; ++i)
    {
        k -= max(0ll, l - a[i]);
        a[i] = max(l, a[i]);
        ans += l;
        if (a[i] > l)
            ++ans;
    }
    ans += k;
    cout << ans - n + 1 << endl;
}

int32_t main()
{
//    ofstream cout("");
//    ifstream cin("");
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed;
    cout.precision(7);
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