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
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(all(a));
    vector<int> b;
    b.push_back(1);
    for (int i = 1; i < a.size(); ++i) {
        if (a[i] == a[i - 1]) {
            ++b.back();
        }
        else {
            b.push_back(1);
        }
    }
    sort(all(b));
    int ind = 0;
    while (ind < b.size() and k >= b[ind]) {
        k -= b[ind];
        ++ind;
    }
    cout << max((int) b.size() - ind, 1ll) << endl;
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