// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

constexpr int mod = 1e9 + 7;

string solve(int n, vector<int> a)
{
    vector<pair<int, int> > b;
    int i = 0;
    while (i < n) {
        int min_interval = a[i];
        int max_interval = a[i];
        while (i + 1 < n and a[i + 1] > a[i]) {
            max_interval = a[i + 1];
            ++i;
        }
        b.push_back({min_interval, max_interval});
        ++i;
    }
    auto [l1, r1] = b[0];
    auto [l2, r2] = b.back();
    if (l1 > r2) {
        return "NO";
    }
    return "YES";
}

void input()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
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