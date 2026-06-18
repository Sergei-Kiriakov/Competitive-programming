// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

constexpr int mod = 1e9 + 7;

string solve(int n, vector<int> s)
{
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == s[i + 1] and s[i] == 0) {
            return "YES";
        }
    }
    int cnt_1 = 0;
    for (int i = 0; i < n; ++i) {
        cnt_1 += (s[i] == 1);
    }
    if (cnt_1 == n or cnt_1 == 0 or cnt_1 < n / 2) {
        return "YES";
    }
    return "NO";
}

void input()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    string ans = solve(n, a);
    cout << ans << endl;
}

int32_t main()
{
    // ofstream cout("");
    // ifstream cin("");
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed;
    cout.precision(7);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int tt = 1;
    cin >> tt;
    while(tt-->0)
    {
        input();
    }
}

/*
*/