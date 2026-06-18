#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main()
{
    int n, a, b, k;
    cin >> n >> a >> b >> k;
    vector<int> c(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> c[i];
        c[i] %= (a + b);
        if (c[i] == 0)
            c[i] = a + b;
        c[i] = (c[i] + (a - 1)) / a;
    }
    sort(c.begin(), c.end());
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        if (k >= c[i] - 1)
        {
            k -= c[i] - 1;
            ++ans;
        }
    }
    cout << ans << endl;
}
