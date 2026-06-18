//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

constexpr int mod = 1e9 + 7;

bool check (int k, vector<int> a) {
    int n = a.size();
    for (int i = 0; i <= k; ++i) {
        if (a[i] + a[i + 1] > a[n - k + i - 1]) {
            return true;
        }
    }
    return false;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(all(a));
    int l = -1, r = n - 2;
    while (r - l > 1) {
        int mid = (r + l) / 2;
        if (check(mid, a)) {
            r = mid;
        }
        else {
            l = mid;
        }
    }
    cout << r << endl;
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