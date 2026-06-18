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
    int n, k;
    cin >> n >> k;
    if (n == 1) {
        cout << 1 << endl;
        cout << 1 << endl;
        return;
    }
    if (k == n or k == 1) {
        cout << -1 << endl;
        return;
    }
    if (k % 2 == 0) {
        cout << 3 << endl;
        cout << 1 << " " << k << " " << k + 1 << endl;
        return;
    }
    cout << 3 << endl;
    cout << 1 << " " << k - 1 << " " << k + 2 << endl;
}

int32_t main()
{
//    ofstream cout("");
//    ifstream cin("");
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed;
    cout.precision(7);
    int tt = 1;
    cin >> tt;
    while(tt-->0)
    {
        solve();
    }
}

/*
*/  