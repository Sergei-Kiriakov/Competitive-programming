#include <bits/stdc++.h>

#define Please return
#define Accepted 0
// #define int long long
#define endl "\n"
// #define double long double

using namespace std;

constexpr int MAXN = 1e6 + 6, mod1 = 1e9 + 9, d = 179, mod2 = 1e9 + 7;

void solve ()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int bal = s[0] - '0';
    string ans;
    for (int i = 1; i < n; ++i)
    {
        if (s[i] == '0')
        {
            ans += '+';
        }
        else
        {
            if (bal > 0)
            {
                ans += '-';
                bal--;
            }
            else
            {
                ans += '+';
                bal++;
            }
        }
    }
    cout << ans << endl;
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
No brain
*/
