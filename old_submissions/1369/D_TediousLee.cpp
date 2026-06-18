#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t, mod = 1e9 + 7;
    cin >> t;
    vector<int> dp(3);
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 4;
    vector<pair<int, int> > v(3);
    v[0] = make_pair(1, 0);
    v[1] = make_pair(1, 1);
    v[2] = make_pair(3, 1);
    for (int i = 0; i < t; ++i)
    {
        int n;
        cin >> n;
        if (n - 1 < dp.size())
        {
            cout << dp[n - 1] << "\n";
        }
        else
        {
            while (n - 1 >= dp.size())
            {
                dp.push_back((dp[dp.size() - 3] + v[v.size() - 1].second * 4) % mod);
                v.push_back(make_pair((v[v.size() - 1].second * 2 + v[v.size() - 1].first) % mod, (v[v.size() - 1].first) % mod));
            }
            cout << dp[n - 1] << "\n";
        }
    }
}
