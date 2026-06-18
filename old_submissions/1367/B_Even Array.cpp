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
        int n;
        cin >> n;
        vector<int> a(n);
        int count1 = 0, count2 = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            if (i % 2 == 0 && a[i] % 2 == 1)
            {
                ++count1;
            }
            else if (i % 2 == 1 && a[i] % 2 == 0)
            {
                ++count2;
            }
        }
        if (count1 != count2)
        {
            cout << -1 << "\n";
        }
        else
        {
            cout << count1 << "\n";
        }
    }
}
