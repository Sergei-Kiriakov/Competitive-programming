// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

constexpr int mod = 1e9 + 7;

vector<int> solve(int n, vector<int> a)
{
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            a[i] = -abs(a[i]);
        }
        else {
            a[i] = abs(a[i]);
        }
    }
    return a;
}

void input()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> ans = solve(n, a);
    for (auto el : ans) {
        cout << el << " ";
    }
    cout << endl;
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