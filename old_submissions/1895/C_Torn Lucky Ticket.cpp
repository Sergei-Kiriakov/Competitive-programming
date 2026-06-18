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

void solve()
{
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; ++i) cin >> s[i];
    int ans = 0;
    int ans_same = 0;
    for (int len = 2; len <= 10; len += 2)
    {
        int lenn = len / 2;
        map<pair<int, int>, int> small;
        for (int i = 0; i < n; ++i)
        {
            string name = s[i];
            if (name.size() <= lenn)
            {
                int sum = 0;
                for (auto el : name)
                {
                    sum += el - '0';
                }
                ++small[{name.size(), sum}];
            }
        }
        for (int i = 0; i < n; ++i)
        {
            string name = s[i];
            if (name.size() >= lenn)
            {
                int all_sum = 0;
                for (auto el : name) all_sum += el - '0';
                int sum_left = 0;
                for (int j = 0; j < lenn; ++j) sum_left += name[j] - '0';
                int sum_right = 0;
                for (int j = 0; j < lenn; ++j) sum_right += name[name.size() - 1 - j] - '0';
                if (name.size() == lenn)
                {
                    ans_same += small[{len - name.size(), sum_right - (all_sum - sum_right)}];
                    ans_same += small[{len - name.size(), sum_left - (all_sum - sum_left)}];
                }
                else
                {
                    ans += small[{len - name.size(), sum_right - (all_sum - sum_right)}];
                    ans += small[{len - name.size(), sum_left - (all_sum - sum_left)}];
                }
            }
        }
    }
    cout << ans + ans_same / 2 << endl;
}

int32_t main()
{
//    ofstream cout("std.out");
//    ifstream cin("std.in");
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed;
    cout.precision(7);
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