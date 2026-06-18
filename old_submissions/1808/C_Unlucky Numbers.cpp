#include <bits/stdc++.h>

#define int long long
#define endl "\n"

using namespace std;

int f (int n)
{
    int min1 = 10, max1 = -1;
    while (n != 0)
    {
        min1 = min(n % 10, min1);
        max1 = max(max1, n % 10);
        n /= 10;
    }
    return max1 - min1;
}

bool f(string a, string b)
{
    if (a.size() != b.size())
        return a.size() < b.size();
    for (int i = 0; i < a.size(); ++i)
    {
        if (a[i] != b[i])
        {
            return a[i] < b[i];
        }
    }
    return true;
}

void solve()
{
    int l, r;
    cin >> l >> r;
    string a1 = to_string(l), b = to_string(r);
    string ans = "";
    int cnt = 1e9;
    for (int min1 = 0; min1 < 10; ++min1)
    {
        for (int max1 = max(1ll, min1); max1 < 10; ++max1)
        {
            string a = a1;
            int n = a.size(), zap = 0;
            for (int i = n - 1; i > -1; --i)
            {
                int d = a[i] - '0';
                if (d + zap < min1)
                {
                    a[i] = min1 + '0';
                    zap = 0;
                    for (int j = i + 1; j < n; ++j)
                    {
                        a[j] = min1 + '0';
                    }
                }
                else if (d + zap > max1)
                {
                    a[i] = min1 + '0';
                    zap = 1;
                    for (int j = i + 1; j < n; ++j)
                    {
                        a[j] = min1 + '0';
                    }
                }
                else
                {
                    a[i] = a[i] + zap;
                    zap = 0;
                }
            }
            string c;
            if (zap == 1)
                c += min1 + '0';
            c += a;
            if (c[0] == '0')
            {
                c[0]++;
            }
            if (f(c, b) && f(a1, c) && cnt > max1 - min1)
            {
                cnt = max1 - min1;
                ans = c;
            }
        }
    }
    cout << ans << endl;
}

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed;
    cout.precision(15);
    int tt = 1;
    cin >> tt;
    while (tt-->0)
    {
        solve();
    }
}


/*
1
9371 9472
9444
9373
*/