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
    vector<int> ans(n - 1, 0);
    ans[0] = 1;
    vector<int> last_0(n - 1, -1), last_1(n - 1, -1);
    int ind_0 = -1, ind_1 = -1;
    for (int i = 0; i < n - 1; ++i)
    {
        last_0[i] = ind_0;
        last_1[i] = ind_1;
        if (s[i] == '0')
        {
            ind_0 = i;
        }
        else
        {
            ind_1 = i;
        }
    }
    for (int i = 1; i < n - 1; ++i)
    {
        if (s[i] == '1')
        {
            ans[i] = (i + 2) - (i - last_0[i]);
        }
        else
        {
            ans[i] = (i + 2) - (i - last_1[i]);
        }
    }
    for (int i = 0; i < n - 1; ++i)
    {
        cout << ans[i] << " ";
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
No brain
*/
