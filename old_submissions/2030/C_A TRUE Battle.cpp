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
    string s;
    cin >> s;
    if (s[0] == '1' or s.back() == '1') {
        cout << "YES" << endl;
        return;
    }
    int cnt1 = 0;
    for (int i = 0; i < n; ++i) {cnt1 += s[i] == '1';}
    if (cnt1 == 0) {
        cout << "NO" << endl;
        return;
    }
    bool flag = false;
    for (int i = 1; i < n; ++i) {
        if (s[i] == s[i - 1] and s[i] == '1') {
            flag = true;
        }
    }
    if (flag) {
        cout << "YES" << endl;
        return;
    }
    if (cnt1 * 2 >= n) {
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
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