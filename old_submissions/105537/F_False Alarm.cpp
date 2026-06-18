//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

constexpr int mod = 1e9 + 7;

int time_in_seconds (string s) {
    int ans = 0;
    ans += (s[0] - '0') * 60 * 60;
    ans += ((s[2] - '0') * 10 + (s[3] - '0')) * 60;
    ans += (s[5] - '0') * 10 + (s[6] - '0');
    return ans;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> seconds(n);
    for (int i = 0; i < n; ++i) {
        string temp;
        cin >> temp;
        seconds[i] = time_in_seconds(temp);
    }
    sort(all(seconds));
    int delay = 60 * 10;
    int ans = 0;
    int r = 0;
    for (int i = 0; i < n; ++i) {
        r = max(r, i);
        while (r + 1 < n and seconds[r + 1] - seconds[i] <= delay) {
            ++r;
        }
        ans = max(ans, r - i + 1);
    }
    if (ans >= 3) {
        cout << 0 << endl;
        return;
    }
    cout << 3 - ans << endl;
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