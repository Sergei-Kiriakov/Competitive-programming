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
    if (n % 2 == 0) {
        for (int i = 0; i < n / 2; ++i) {
            cout << i + 1 << " " << i + 1 << " ";
        }
        cout << endl;
        return;
    }
    if (n < 27){
        cout << -1 << endl;
        return;
    }
    vector<int> ans = {1, 2, 2, 3, 3, 4, 4, 5, 5, 1, 6, 6, 7, 7, 8, 8, 9, 9, 10, 10, 11, 11, 12, 13, 13, 1, 12};
    for (int el : ans) {
        cout << el << " ";
    }
    int cnt = 14;
    for (int i = 0; i < n - ans.size(); i += 2) {
        cout << cnt << " " << cnt << " ";
        ++cnt;
    }
    cout << endl;
//    cout << 1 << " ";
//    for (int i = 0; i < )
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