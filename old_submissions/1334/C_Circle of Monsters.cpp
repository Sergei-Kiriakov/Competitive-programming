#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int k = 0; k < t; ++k)
    {
        int n;
        cin >> n;
        vector<vector<int> > a(n, vector<int> (3));
        int sum1 = 0, zero = 0, ans = 1e13;
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i][0] >> a[i][1];
            a[i][2] = a[i][0];
            if (i != 0)
            {
                a[i][0] -= a[(n + i - 1) % n][1];
                a[i][0] = max(a[i][0], zero);
                ans = min(ans, a[i][2] - a[i][0]);
                sum1 += a[i][0];
            }
        }
        a[0][0] -= a[(n + 0 - 1) % n][1];
        a[0][0] = max(a[0][0], zero);
        ans = min(ans, a[0][2] - a[0][0]);
        sum1 += a[0][0];
        cout << ans + sum1 << "\n";
    }
}
