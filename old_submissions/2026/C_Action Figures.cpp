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
    string a;
    cin >> a;
    int ans = (n + 1) * n / 2;
    deque<int> q;
    for (int i = n - 1; i > -1; --i) {
        if (a[i] == '0') {
            if (!q.empty()) {
                ans -= q.front();
                q.pop_front();
            }
            continue;
        }
        q.push_back(i + 1);
    }
    while (q.size() >= 2) {
        ans -= q.front();
        q.pop_front();
        q.pop_back();
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