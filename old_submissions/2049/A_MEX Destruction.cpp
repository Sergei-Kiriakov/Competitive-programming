//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

constexpr int mod = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int cnt0 = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        cnt0 += a[i] == 0;
    }
    if (cnt0 == a.size()) {
        cout << 0 << endl;
        return;
    }
    if (cnt0 == 0) {
        cout << 1 << endl;
        return;
    }
    int i = 0;
    while (i < n and a[i] == 0) {
        ++i;
        --cnt0;
    }
    int i_ = n - 1;
    while (i_ > -1 and a[i_] == 0) {
        --i_;
        --cnt0;
    }
    if (cnt0 == 0) {
        cout << 1 << endl;
        return;
    }
    cout << 2 << endl;
}

int32_t main()
{
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