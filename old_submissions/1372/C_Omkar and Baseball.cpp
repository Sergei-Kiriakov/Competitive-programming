#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t, mod = 1e9 + 7;
    cin >> t;
    for (int j = 0; j < t; ++j)
    {
        int n;
        cin >> n;
        vector<int> a(n), b;
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            b.push_back(a[i]);
        }
        sort(b.begin(), b.end());
        bool flag = false;
        for (int i = 0; i < n; ++i)
        {
            if (a[i] != b[i])
            {
                flag = true;
            }
        }
        if (flag)
        {
            flag = true;
            bool flag1 = false;
            int l, r;
            for (int i = 0; i < n; ++i)
            {
                if (a[i] != b[i] && flag)
                {
                    l = i;
                    flag = false;
                }
                if (a[i] != b[i])
                    r = i;
            }
            for (int i = 0; i < n; ++i)
            {
                if (a[i] == b[i] && i >= l && i <= r)
                    flag1 = true;
            }
            if (flag1)
            {
                cout << 2 << "\n";
            }
            else
            {
                cout << 1 << "\n";
            }
        }
        else
        {
            cout << 0 << "\n";
        }
    }
}
