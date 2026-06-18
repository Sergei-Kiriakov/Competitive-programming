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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(m);
    int max1 = (n + k - 1) / k;
    bool flag = false;
    int cnt = 0;
    int max2 = n / k + 1;
    for (int i = 0; i < m; ++i)
    {
        cin >> a[i];
        if (a[i] > max1)
        {
            flag = true;
        }
        if (a[i] == max2)
        {
            ++cnt;
        }
    }
    if (flag || k > m || cnt > (n % k))
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
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
