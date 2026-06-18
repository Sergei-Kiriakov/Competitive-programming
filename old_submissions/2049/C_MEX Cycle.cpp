//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

constexpr int mod = 1e9 + 7;

int mex(vector<int> a) {
    sort(all(a));
    int ans = 0;
    int i = 0;
    while (i < a.size() and ans == a[i]) {
        ++ans;
        ++i;
    }
    return ans;
}

void solve()
{
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> ans(n, -1);
    --x;
    --y;
    ans[x] = 0;
    ans[y] = 1;
    for (int i = x + 1; i < y; ++i) {
        vector<int> c;
        if (ans[i - 1] != -1)
            c.push_back(ans[i - 1]);
        if (ans[i + 1] != -1)
            c.push_back(ans[i + 1]);
        ans[i] = mex(c);
    }

    int now = (y + 1) % n;
    while (now != x) {
        int prev = (n + now - 1) % n;
        int next = (now + 1) % n;
        vector<int> c;
        if (ans[prev] != -1)
            c.push_back(ans[prev]);
        if (ans[next] != -1)
            c.push_back(ans[next]);
        ans[now] = mex(c);
        now = next;
    }

    for (auto el : ans) {
        cout << el << " ";
    }
    cout << endl;
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