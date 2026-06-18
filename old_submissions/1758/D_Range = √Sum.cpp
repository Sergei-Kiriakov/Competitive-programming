#include <bits/stdc++.h>

#define int long long
#define endl "\n"

using namespace std;

constexpr int MAXN = 10, mod = 998244353;

void solve ()
{
    int n;
    cin >> n;
    if (n == 3)
    {
        cout << 3 << " " << 6 << " " << 7 << endl;
        return;
    }
    if (n % 2 == 0)
    {
        vector<int> ans(n);
        for (int i = 0; i < n / 2; ++i)
        {
            ans[i] = n - i - 1;
            ans[n - i - 1] = n + i + 1;
        }
        for (int i = 0; i < n; ++i)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    else
    {
        vector<int> ans(n);
        for (int i = 0; i < n / 2; ++i)
        {
            ans[i] = (4 * n - i - 1);
            ans[n - i - 1] = (4 * n + i + 1);
        }
        ans[n / 2] = n * 4;
        sort(ans.begin(), ans.end());
        // 2* n - n + 1 = n + 1
        ans[0] -= (n + 1) / 2;
        ans[n - 1] += (n + 1) / 2;
        // int sum = 0;
        for (int i = 0; i < n; ++i)
        {
            cout << ans[i] << " ";
            // sum += ans[i];
        }
        cout << endl;
        // cout << sum << " " << ans[n - 1] - ans[0] << endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cerr.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solve();
    }  
}

/*
19 + 20 + 24 + 28 + 32 + 36 + 37
39 63 91 123 198
*/