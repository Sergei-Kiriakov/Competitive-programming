// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

constexpr int mod = 1e9 + 7;

vector<int> get_bit(int n) {
    vector<int> ans;
    for (int i = 0; i < 62; ++i) {
        ans.push_back(n % 2);
        n /= 2;
    }
    reverse(all(ans));
    vector<int> anss(62 - ans.size(), 0);
    for (int i = 0; i < ans.size(); ++i)
        anss.push_back(ans[i]);
    return anss;
}

void solve()
{
    int b, c, d;
    cin >> b >> c >> d;
    vector<int> b_ = get_bit(b), c_ = get_bit(c), d_ = get_bit(d);
    vector<int> a(62, 0);
    for (int i = 0; i < a.size(); ++i) {
        if (b_[i] == 0 and c_[i] == 0) {
            if (d_[i] == 0)
                a[i] = 0;
            else
                a[i] = 1;
        }
        else if (b_[i] == 0 and c_[i] == 1) {
            if (d_[i] == 0)
                a[i] = 0;
            else {
                cout << -1 << endl;
                return;
            }
        }
        else if (b_[i] == 1 and c_[i] == 0) {
            if (d_[i] == 0) {
                cout << -1 << endl;
                return;
            }
            a[i] = 0;
        }
        else {
            if (d_[i] == 0)
                a[i] = 1;
            else
                a[i] = 0;
        }
    }
    int ans = 0;
    int dd = 1;
    for (int i = a.size() - 1; i >= 0; --i) {
        ans += dd * a[i];
        dd *= 2;
    }
    cout << ans << endl;
}

int32_t main()
{
    // ofstream cout("");
    // ifstream cin("");
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed;
    cout.precision(7);
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