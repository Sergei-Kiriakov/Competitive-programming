#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main() {
    int h, w, ans = 1, mod = 1e9 + 7;
    cin >> h >> w;
    vector<int> r(h), c(w);
    vector<vector<int> > a(h + 1, vector<int> (w + 1, -1));
    for (int i = 0; i < h; ++i)
    {
        cin >> r[i];
        if (r[i] == 0)
        {
            a[i][0] = 0;
        }
        else
        {
            for (int j = 0; j < r[i]; ++j)
            {
                a[i][j] = 1;
            }
            a[i][r[i]] = 0;
        }
    }
    bool flag = true;
    for (int i = 0; i < w; ++i)
    {
        cin >> c[i];
        if (c[i] == 0)
        {
            if (a[0][i] == 1)
            {
                flag = false;
            }
            a[0][i] = 0;
        }
        else
        {
            for (int j = 0; j < c[i]; ++j)
            {
                if (a[j][i] == 0)
                    flag = false;
                else
                    a[j][i] = 1;
            }
            if (a[c[i]][i] == 1)
                flag = false;
            a[c[i]][i] = 0;
        }
    }
    if (flag)
    {
        for (int i = 0; i < h; ++i)
        {
            for (int j = 0; j < w; ++j)
            {
                if (a[i][j] == -1)
                    ans = (ans * 2) % mod;
            }
        }
        cout << ans << endl;
    }
    else
    {
        cout << 0 << endl;
    }
}
