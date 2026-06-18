//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
//#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

constexpr int mod = 998244353;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    if (n == 1) {
        cout << 1 << endl;
        return;
    }
    if (n % 2 == 0) {
        int ans = 0;
        for (int i = 1; i < n; i += 2)
            ans = max(ans, a[i] - a[i - 1]);
        cout << ans << endl;
        return;
    }

    int ans = 1e18;
    auto get_ans = [&] (vector<int> a) {
        sort(all(a));
        for (int i = 1; i < a.size(); i += 2) {
            if (a[i] == a[i - 1])
                return;
        }
        int max1 = 0;
        for (int i = 1; i < a.size(); i += 2) {
            max1 = max(max1, a[i] - a[i - 1]);
        }
        ans = min(ans, max1);
    };
    for (int i = 0; i < n; ++i) {
        for (int x : {-1, 1}) {
            a.push_back(a[i] + x);
            get_ans(a);
            a.pop_back();
        }
    }
    cout << ans << endl;
}

int32_t main() {
//    ofstream cout("");
//    ifstream cin("");
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