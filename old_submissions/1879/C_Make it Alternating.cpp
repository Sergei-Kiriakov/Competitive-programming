//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

constexpr int mod = 998244353;

vector<int> fac;

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    int ans2 = 1;
    int ans1 = 0;
    int cnt = 1;
    for (int i = n - 2; i > -1; --i)
    {
        if (s[i] != s[i + 1])
        {
            ans2 = ans2 * cnt % mod;
            ans1 += cnt - 1;
            cnt = 1;
        }
        else
        {
            ++cnt;
        }
    }
    ans1 += cnt - 1;
    ans2 = ans2 * cnt % mod;
    ans2 = ans2 * fac[ans1] % mod;
    cout << ans1 << " " << ans2 % mod << endl;
}

int32_t main()
{
    int big = 1e6;
    fac = vector<int> (big, 1);
    for (int i = 2; i < big; ++i)
    {
        fac[i] = fac[i - 1] * i % mod;
    }
//    ofstream cout("sum.out");
//    ifstream cin("sum.in");
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed;
    cout.precision(9);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int tt = 1;
    cin >> tt;
    while(tt-->0)
    {
        solve();
    }
}


/*


*/  