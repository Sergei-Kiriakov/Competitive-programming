//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define remin(x, y) x = min(x, y)
#define remax(x, y) x = max(x, y)
#define lowpos(a, x) int(lower_bound(a.begin(), a.end(), x) - a.begin())
#define uppos(a, x) int(upper_bound(a.begin(), a.end(), x) - a.begin())

using namespace std;

constexpr int mod = 1e9 + 7;

vector<int> get_mask (int k)
{
    vector<int> mask;
    while (k > 0)
    {
        mask.push_back(k % 2);
        k /= 2;
    }
//    reverse(all(mask));
    return mask;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    int sum = 0;
    vector<int> ans;
    while (sum + sum + 1 < k)
    {
        ans.push_back(sum + 1);
        sum += sum + 1;
    }
    int last = k - sum - 1;
    if (last != 0)
    {
        sum += last;
        ans.push_back(last);
    }
    sum += k + 1;
    ans.push_back(k + 1);
    ans.push_back(k + 1);
    while (sum < n)
    {
        ans.push_back(sum + 1);
        sum += sum + 1;
    }
    cout << ans.size() << endl;
    for (int el : ans)
    {
        cout << el << " ";
    }
    cout << endl;
}

int32_t main()
{
//    ofstream cout("std.out");
//    ifstream cin("std.in");
    ios::sync_with_stdio(false); cin.tie(nullptr);
//    cout << fixed;
//    cout.precision(7);
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