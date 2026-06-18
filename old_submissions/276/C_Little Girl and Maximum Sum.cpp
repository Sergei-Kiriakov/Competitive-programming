#include <bits/stdc++.h>
#define int long long
#define double long double

typedef std::vector<int> vi;

using namespace std;

constexpr int mod = 1e9 + 7, p = 179, MAX = 1e4 * 4;

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    vector<int> cnt(n + 1, 0);
    for (int i = 0; i < q; ++i)
    {
        int l, r;
        cin >> l >> r;
        --l; --r;
        ++cnt[l];
        --cnt[r + 1];
    }
    int bal = 0;
    for (int i = 0; i < n; ++i)
    {
        bal += cnt[i];
        cnt[i] = bal;
    }
    sort(cnt.begin(), cnt.end());
    sort(a.begin(), a.end());
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        ans += a[i] * cnt[i + 1];
    }
    cout << ans << "\n";
}

int32_t main()
{
    //ofstream cout("test.txt");
    //ifstream cin("joseph.in");
    //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cerr.tie(0);
    /*
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    */
    solve();
    return 0;
}
