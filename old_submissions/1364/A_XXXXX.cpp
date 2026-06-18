#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for(int j = 0; j < t; ++j)
    {
        int n, k;
        cin >> n >> k;
        int sum1 = 0;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            sum1 = (sum1 + a[i]) % k;
            a[i] %= k;
        }
        if (sum1 % k == 0)
        {
            int l = 0, r = n - 1, count1 = 1, count2 = 1;
            while(l < n && a[l] % k == 0)
            {
                ++l;
                ++count1;
            }
            while(r > -1 && a[r] % k == 0)
            {
                --r;
                ++count2;
            }
            if (l == n && r == -1)
            {
                cout << -1 << "\n";
            }
            else
            {
                cout << n - min(count1, count2) << "\n";
            }
        }
        else
        {
            cout << n << "\n";
        }
    }
}
