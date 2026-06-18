#include <bits/stdc++.h>
#define int long long
#define double long double

typedef std::vector<int> vi;

using namespace std;

constexpr int mod = 1e9 + 7, p = 179, MAX = 1e4 * 4;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    vector<int> pref_sum(n);
    pref_sum[0] = a[0];
    for (int i = 1; i < n; ++i)
    {
        pref_sum[i] = pref_sum[i - 1] + a[i];
    }
    if (pref_sum[n - 1] % 3 != 0 || n < 3)
    {
        cout << 0 << "\n";
    }
    else
    {
        int ans = 0;
        int k = pref_sum[n - 1] / 3;
        vector<int> pref_count_2k(n);
        pref_count_2k[0] = (pref_sum[0] == 2 * k);
        for (int i = 1; i < n; ++i)
        {
            pref_count_2k[i] = pref_count_2k[i - 1] + (pref_sum[i] == 2 * k);
        }
        /*
        for (int i = 0; i < n; ++i)
        {
            cout << pref_count_2k[i] << " ";
        }
        cout << "\n";
        */
        for (int i = 0; i < n - 2; ++i)
        {
            if (pref_sum[i] == k)
            {
                ans += pref_count_2k[n - 2] - pref_count_2k[i];
            }
        }
        cout << ans << "\n";
    }
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
