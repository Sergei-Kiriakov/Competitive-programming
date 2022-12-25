#include <bits/stdc++.h>
 
#define int long long
#define endl "\n"
#define double long double
 
using namespace std;
 
constexpr int MAXN = 1e6 + 6, mod1 = 1e9 + 9, d = 179, mod2 = 1e9 + 7;
 
const double pi = 3.14159265358979323846;
 
void solve ()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> p(10, 1);
    for (int i = 1; i < p.size(); ++i)
    {
        p[i] = p[i - 1] * 2;
    }
    int min1 = (1 << 10) - 1, max1 = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        for (int j = 0; j < p.size(); ++j)
        {
            if (p[j] & a[i])
            {
                max1 |= p[j];
            }
            else
            {
                min1 = min(min1, min1 ^ p[j]);
            }
        }
    }
    cout << max1 - min1 << endl;
 
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
*/