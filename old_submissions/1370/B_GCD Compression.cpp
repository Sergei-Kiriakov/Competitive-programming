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
        vector<int> a(2 * n);
        vector<pair<int, int> > l, r;
        for (int i = 0; i < 2 * n; ++i)
        {
            cin >> a[i];
            if (a[i] % 2 == 1)
                l.push_back(make_pair(a[i], i + 1));
            else
                r.push_back(make_pair(a[i], i + 1));
        }
        int count1 = 0;
        for (int i = 0; i < l.size() - l.size() % 2; i += 2)
        {
            if (count1 < n - 1)
            {
                cout << l[i].second << " " << l[i + 1].second << "\n";
            }
            ++count1;
        }
        for (int i = 0; i < r.size() - r.size() % 2; i += 2)
        {
            if (count1 < n - 1)
            {
                cout << r[i].second << " " << r[i + 1].second << "\n";
            }
            ++count1;
        }
    }
}
