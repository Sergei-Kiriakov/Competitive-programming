#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main()
{
    int t;
    cin >> t;
    for (int k = 0; k < t; ++k)
    {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        sort(a.rbegin(), a.rend());
        int sum1 = 0, ans = 0, j = 0;
        while (j < n & (sum1 + a[j]) / (ans + 1) >= x)
        {
            sum1 += a[j];
            ++ans;
            ++j;
        }
        cout << ans << endl;
    }
}
