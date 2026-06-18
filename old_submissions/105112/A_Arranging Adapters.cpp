// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

constexpr int mod = 1e9 + 7;

bool check(vector<int> &a, int n, int s, int k )
{
    int cnt_free1 = 0, cnt_free2 = 0;
    int need = 0;
    for (int i = 0; i < min(n, k); ++i)
    {
        need += a[i] / 3;
        cnt_free1 += (a[i] % 3 == 1);
        cnt_free2 += (a[i] % 3 == 2);
    }
    int ans = min(cnt_free2, cnt_free1);
    cnt_free1 -= ans;
    cnt_free2 -= ans;
    ans += cnt_free2;
    ans += (cnt_free1 + 1) / 2;
    return (ans + need <= s);
}

void solve()
{
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    if (n == 1 or s == 1)
    {
        cout << 1 << endl;
        return;
    }
    sort(all(a));
    int ans = 2;
    s -= 2;
    a.pop_back();
    a.pop_back();
    n -= 2;
    int cnt_free1 = 0, cnt_free2 = 0;
    int l = 0, r = min(s, n) + 1;
    while (r - l > 1)
    {
        int mid = (l + r) / 2;
        if (check(a, n, s, mid))
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    cout << ans + l << endl;
    return;
}

int32_t main()
{
    // ofstream cout("");
    // ifstream cin("");
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed;
    cout.precision(7);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int tt = 1;
    // cin >> tt;
    while(tt-->0)
    {
        solve();
    }
    // cout << "Hello" << endl;
}

/*
*/