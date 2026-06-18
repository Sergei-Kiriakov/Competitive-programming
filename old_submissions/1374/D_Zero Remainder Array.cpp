#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for(int i = 0; i < t; ++i)
    {
        int n, k, count1 = 1, count2 = 0, z = 0;
        cin >> n >> k;
        vector<int> a(n);
        bool flag = true;
        for (int j = 0; j < n; ++j)
        {
            cin >> a[j];
            a[j] %= k;
            a[j] = k - a[j];
            if (a[j] != k)
                flag = false;
        }
        sort(a.begin(), a.end());
        int max1 = 0, ind = 0;
        for (int j = 1; j < n; ++j)
        {
            if (a[j - 1] != a[j])
            {
                if (count1 >= max1)
                {
                    ind = a[j - 1];
                    max1 = count1;
                }
                count1 = 1;
            }
            else
                ++count1;
        }
        if (count1 >= max1 && a[n - 1] != k)
        {
            ind = a[n - 1];
            max1 = count1;
        }
        if (flag)
            cout << 0 << "\n";
        else
            cout << k * (max1 - 1) + ind + 1 << "\n";
    }
}
