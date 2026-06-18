#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

void solve()
{
    int n;
    cin >> n;
    int ans = 0;
    set<char> c;
    c.insert('a');
    c.insert('e');
    c.insert('i');
    c.insert('o');
    c.insert('u');
    c.insert('y');
    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        int cnt1 = 0, cnt2 = 0, cnt3 = 0;
        for (int j = 0; j < s.size(); ++j)
        {
            if (c.count(s[j]))
            {
                if (j % 2 == 0)
                {
                    ++cnt1;
                }
                else
                {
                    ++cnt2;
                }
            }
            else
            {
                ++cnt3;
                if (j % 2 == 0)
                {
                    ++cnt2;
                }
                else
                {
                    ++cnt1;
                }
            }
        }
        ans += min({cnt1, cnt2, cnt3});
    }
    cout << ans << endl;
    return;
}

int32_t main()
{
    //ofstream cout("sum.out");
    //ifstream cin("sum.in");
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed;
    cout.precision(15);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int tt = 1;
    //cin >> tt;
    while(tt-->0)
    {
        solve();
    }
}


/*
*/