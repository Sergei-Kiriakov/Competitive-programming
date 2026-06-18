#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define int long long
#define endl "\n"
#define double long double

using namespace std;

constexpr int MAXN = 1e6 + 6, mod = 1e9 + 7, d = 179;

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    vector<int> cnt(26, 0);
    for (int i = 0; i < n; ++i)
    {
        ++cnt[s[i] - 'a'];
    }
    vector<char> a(n);
    int last = 0;
    int i = 0;
    int cnt_em = n;
    while (i < cnt.size())
    {
        for (int j = 0; j < cnt[i] / 2; ++j)
        {
            a[last] = 'a' + i;
            a[n - last - 1] = 'a' + i;
            ++last;
        }
        cnt_em -= cnt[i] - cnt[i] % 2;
        if (cnt[i] % 2 == 1)
        {
            char save = 'a' + i;
            ++i;
            while (i < cnt.size() && cnt[i] == 0)
            {
                ++i;
            }
            if (i != cnt.size())
            {
                if (cnt[i] + 1 == cnt_em)
                {
                    for (int j = 0; j < cnt[i] / 2; ++j)
                    {
                        a[last] = 'a' + i;
                        a[n - last - 1] = 'a' + i;
                        ++last;
                    }
                    a[n - last - 1] = save;
                    if (cnt[i] % 2 == 1)
                    {
                        a[last] = 'a' + i;
                    }
                    i = cnt.size();
                }
                else
                {
                    a[n - last - 1] = save;
                    while (i < cnt.size())
                    {
                        for (int j = 0; j < cnt[i]; ++j)
                        {
                            a[last] = 'a' + i;
                            ++last;
                        }
                        ++i;
                    }
                }
            }
            else
            {
                a[last] = save;
            }
        }
        ++i;
    }
    for (int i = 0; i < n; ++i)
    {
        cout << a[i];
    }
    cout << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cerr.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solve();
    }
}

/*
1
3
4 3 2
*/