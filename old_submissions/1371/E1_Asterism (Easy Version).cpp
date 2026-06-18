#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t, mod = 1e9 + 7;
    int n, p;
    cin >> n >> p;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<int> anss;
    for (int i = a[0]; i < a[n - 1]; ++i)
    {
        int ans = 1;
        bool flag = false;
        for (int h = 0; h < n; ++h)
        {
            int l = -1, r = n;
            while (r - l > 1)
            {
                int m = (r + l) / 2;
                if (a[m] > i + h)
                {
                    r = m;
                }
                else
                {
                    l = m;
                }
            }
            int count1 = l + 1 - h;
            if (count1 % p == 0)
            {
                flag = true;
            }
        }
        if (!flag)
        {
            anss.push_back(i);
        }
    }
    cout << anss.size() << "\n";
    for (int i = 0; i < anss.size(); ++i)
    {
        cout << anss[i] << " ";
    }
    cout << "\n";
}
