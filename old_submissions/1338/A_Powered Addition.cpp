#include <bits/stdc++.h>
#define int long long
#define double long double

typedef std::vector<int> vi;

using namespace std;

constexpr int mod = 1e9 + 7, p = 179, MAX = 1e4 * 4;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    vector<int> best_pos(n);
    best_pos[0] = a[0];
    for (int i = 1; i < n; ++i)
    {
        best_pos[i] = max(best_pos[i - 1], a[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        int elem = best_pos[i] - a[i];
        int max_bit = 0;
        while (elem != 0)
        {
            ++max_bit;
            elem >>= 1;
        }
        ans = max(ans, max_bit);
    }
    cout << ans << "\n";
}

int32_t main()
{
    //ofstream cout("test.txt");
    //ifstream cin("joseph.in");
    //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cerr.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
