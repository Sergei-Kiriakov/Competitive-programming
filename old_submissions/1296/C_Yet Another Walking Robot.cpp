#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main()
{
    int t;
    cin >> t;
    for (int j = 0; j < t; ++j)
    {
        int n, maxs = 1e9, x = 0, y = 0, l = 0, r = 0;
        string s;
        cin >> n >> s;
        map<pair<int, int>, int> p;
        p[make_pair(x, y)] = 1;
        for (int i = 0; i < n; ++i)
        {
            if (s[i] == 'L')
                --x;
            else if (s[i] == 'R')
                ++x;
            else if (s[i] == 'U')
                ++y;
            else
                --y;
            if (p.count(make_pair(x, y)))
            {
                if (maxs > i + 1 - p[make_pair(x, y)] + 1)
                {
                    l = p[make_pair(x, y)];
                    r = i + 1;
                    maxs = min(maxs, r - l + 1);
                }
            }
            p[make_pair(x, y)] = i + 2;
        }
        if (maxs != 1e9)
            cout << l << " " << r << endl;
        else
            cout << -1 << endl;
    }
}
