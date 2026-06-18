#include <bits/stdc++.h>

#define Please return
#define Accepted 0
#define int long long
#define endl "\n"
#define double long double

using namespace std;

constexpr int MAXN = 1e6 + 6, mod = 998244353;

void solve ()
{
    string s;
    cin >> s;
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    int p1, p2, p3;
    cin >> p1 >> p2 >> p3;
    int r;
    cin >> r;
    int cnt1 = 0, cnt2 = 0, cnt3 = 0, n = s.size();
    for (int i = 0; i < n; ++i)
    {
        cnt1 += (s[i] == 'B');
        cnt2 += (s[i] == 'S');
        cnt3 += (s[i] == 'C');
    }
    int ans = 0;
    bool buy = true;
    while (buy)
    {
        buy = false;
        if ((n1 == 0 || cnt1 == 0) && (n2 == 0 || cnt2 == 0) && (n3 == 0 || cnt3 == 0))
        {
            ans += r / (cnt1 * p1 + cnt2 * p2 + cnt3 * p3);
        }
        else
        {
            int q = max(cnt1 - n1, 0ll) * p1 + max(cnt2 - n2, 0ll) * p2 + max(cnt3 - n3, 0ll) * p3;
            n1 = max(0ll, n1 - cnt1);
            n2 = max(0ll, n2 - cnt2);
            n3 = max(0ll, n3 - cnt3);
            if (q <= r)
            {
                buy = true;
                r -= q;
                ++ans;
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
    // cin >> tt;
    while (tt--)
    {
        solve();
    }
}

/*
0 1
4
1 2 2 5
1 2 3 5
3 2 2 1 1 
*/
