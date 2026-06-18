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
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        vector<int> ans;
        ans.push_back(a[0]);
        int l = 0;
        for (int i = 1; i < n; ++i)
        {
            if (l == 0)
            {
                if (a[i] > a[i - 1])
                {
                    l = 1;
                }
                else if (a[i] < a[i - 1])
                {
                    l = -1;
                }
            }
            else if (a[i] > a[i - 1] && l == -1)
            {
                l = 1;
                ans.push_back(a[i - 1]);
            }
            else if (a[i] < a[i - 1] && l == 1)
            {
                l = -1;
                ans.push_back(a[i - 1]);
            }
        }
        ans.push_back(a[n - 1]);
        cout << ans.size() << "\n";
        for (int i = 0; i < ans.size(); ++i)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}
