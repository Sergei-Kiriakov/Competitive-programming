//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#include <random>

#define int long long
#define double long double
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

const int mod = 1e9 + 93, ddl = 179;

void solve()
{
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int ans = 0;
    for (int i = 0; i < n / 2; ++i)
        if (b[i] == b[n - i - 1])
        {
            if (a[i] != a[n - 1 - i])
                ++ans;
        }
        else
            if (a[i] == a[n - i - 1])
            {
                if (a[i] == b[i] or a[i] == b[n - i - 1])
                    ++ans;
                else
                    ans += 2;
            }
            else
            {
                int d = 2;
                if (a[i] == b[i] or a[i] == b[n - i - 1])
                    --d;
                if (a[n - i - 1] == b[i] or a[n - i - 1] == b[n - i - 1])
                    --d;
                ans += d;
            }
    if (n % 2 == 1 and a[n / 2] != b[n / 2])
        ++ans;
    cout << ans << endl;
}

int32_t main()
{
//  ofstream cout("sum.out");
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed;
    cout.precision(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int tt = 1;
//    cin >> tt;
    while(tt-->0)
    {
        solve();
    }
}


/*
*/