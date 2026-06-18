//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
#include <random>

#define int long long
#define double long double
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

const int mod = 1e9 + 7, ddl = 179;

bool check(vector<int> a1, vector<int> a2, int k, int need)
{
    int n = a1.size(), m = a2.size();
    int ans = 0;
    if (k % 2 == 1)
    {
        if (a1.size() != 0)
        {
            ans += a1.back();
            a1.pop_back();
            --k;
        }
    }
    for (int i = 0; i < k / 2; ++i)
    {
        int d1 = 0, d2 = 0;
        if (a1.size() >= 2) d1 = a1.back() + a1[a1.size() - 2];
        else if (a1.size() >= 1) d1 = a1.back();
        if (a2.size() >= 1) d2 = a2.back();
        if (d1 > d2)
        {
            a1.pop_back();
            if (a1.size() >= 1)
                a1.pop_back();
            ans += d1;
        }
        else
        {
            a2.pop_back();
            ans += d2;
        }
    }
    return ans >= need;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n);
    vector<int> a1, a2;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i)
    {
        cin >> b[i];
        if (b[i] == 1)
            a1.push_back(a[i]);
        else
            a2.push_back(a[i]);
    }
    sort(all(a1));
    sort(all(a2));
    int sum = 0;
    for (int i = 0; i < n; ++i) sum += a[i];
    if (sum < m)
    {
        cout << -1 << endl;
        return;
    }
    int l = 0, r = 2 * n;
    while (r - l > 1)
    {
        int mid = (l + r) / 2;
        if (check(a1, a2, mid, m))
            r = mid;
        else
            l = mid;
    }
    cout << r << endl;
}

int32_t main()
{
//  ofstream cout("sum.out");
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed;
    cout.precision(0);
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