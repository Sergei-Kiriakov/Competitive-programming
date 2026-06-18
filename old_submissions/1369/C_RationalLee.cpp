#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        int n, k, ans = 0;
        cin >> n >> k;
        vector<int> a(n), w;
        for (int j = 0; j < n; ++j)
        {
            cin >> a[j];
        }
        sort(a.begin(), a.end());
        for (int j = 0; j < k; ++j)
        {
            int p;
            cin >> p;
            if (p == 1)
            {
                ans += a[a.size() - 1] * 2;
                a.pop_back();
            }
            else
            {
                w.push_back(p);
            }
        }
        sort(w.rbegin(), w.rend());
        int h = 0;
        k = w.size();
        n = a.size();
        for (int j = 0; j < k; ++j)
        {
            if (w[j] != 1)
            {
                ans += a[h];
                h += w[j] - 1;
                ans += a[n - j - 1];
            }
            else
            {
                ans += a[n - j - 1];
            }
        }
        cout << ans << "\n";
    }
}
