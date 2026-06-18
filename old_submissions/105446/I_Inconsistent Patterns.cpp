//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

constexpr int mod = 1e9 + 7;
const int dx = 179, dy = 101;

//const int dx = 1000, dy = 1000;

int bin_pow(int a, int n) {
    int ans = 1;
    while (n) {
        if (n & 1) {
            ans = (ans * a) % mod;
        }
        a = (a * a) % mod;
        n >>= 1;
    }
    return ans;
}

int inverse_mod(int a) {
    return bin_pow(a, mod - 2);
}

void construct_hash(int n, int m, vector<vector<int> > & h, vector<string> & s) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i == 0 and j == 0) {
                continue;
            }
            if (i - 1 > -1) {
                h[i][j] = (h[i][j] + h[i - 1][j] * dx) % mod;
            }
            if (j - 1 > -1) {
                h[i][j] = (h[i][j] + h[i][j - 1] * dy) % mod;
            }
            h[i][j] = (h[i][j] + s[i][j]) % mod;
            if (j - 1 > -1 and i - 1 > -1) {
                h[i][j] = (h[i][j] + mod * mod - h[i - 1][j - 1] * dx * dy) % mod;
            }
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int> > ans(n, vector<int> (4));
    int mx = m;
    for (int i = 0; i < n - 1; ++i) {
        mx -= 1;
        ans[i][0] = 1;
        ans[i][1] = 1;
    }
    int d = m / n;
    ans[n - 1][1] = mx;
    int my = m;
    for (int i = 0; i < n - 1; ++i) {
        ans[i][3] = d;
        ans[i][2] = d - 1;
        my -= d;
    }
    ans[n - 1][3] = my;
    ans[n - 1][2] = 1;

    ans[n - 1][0] = mx / my + 1;

    for (int i = 0; i < n; ++i) {
        cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << " " << ans[i][3] << endl;
    }
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
//    cin >> tt;
    while(tt-->0)
    {
        solve();
    }
}

/*
*/