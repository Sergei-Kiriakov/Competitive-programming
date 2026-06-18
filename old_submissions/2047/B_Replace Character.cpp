//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
#define double long double
//#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

constexpr int mod = 998244353;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> cnt('z' - 'a' + 1, 0);
    for (int i = 0; i < n; ++i) {
        ++cnt[s[i] - 'a'];
    }
    int max1 = -1, ind_max = -1;
    int min1 = 1e9, ind_min = 1e9;
    for (int i = 0; i < cnt.size(); ++i) {
        if (cnt[i] == 0)
            continue;
        if (max1 < cnt[i]) {
            max1 = cnt[i];
            ind_max = i;
        }
        if (min1 >= cnt[i]) {
            min1 = cnt[i];
            ind_min = i;
        }
    }
    int f1 = 0, f2 = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'a' + ind_min) {
            f1 = i;
        }
        if (s[i] == 'a' + ind_max) {
            f2 = i;
        }
    }
    s[f1] = s[f2];
    cout << s << endl;
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