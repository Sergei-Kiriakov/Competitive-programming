// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

constexpr int mod = 1e9 + 7;

int calc_mex(vector<int> & cnt) {
    int mex = 0;
    while (cnt[mex] != 0) {
        ++mex;
    }
    return mex;
}

pair<int, vector<int> > solve(int n, vector<int> a)
{
    vector<int> ans;
    vector<bool> right(n);
    vector<int> cnt(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        ++cnt[a[i]];
        if (a[i] == i) {
            right[i] = true;
        }
    }
    int mex = calc_mex(cnt);

    int ind = 0;
    while (ind < n) {
        while (ind < n and right[ind]) {
            ++ind;
        }
        if (ind == n)
            return {ans.size(), ans};
        if (mex == n) {
            ans.push_back(ind + 1);
            --cnt[a[ind]];
            swap(a[ind], mex);
            ++cnt[a[ind]];
        }
        else {
            ans.push_back(mex + 1);
            --cnt[a[mex]];
            a[mex] = mex;
            ++cnt[a[mex]];
            right[mex] = true;
        }
        mex = calc_mex(cnt);
    }
}

void input()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    pair<int, vector<int> > ans = solve(n, a);
    cout << ans.first << endl;
    for (auto el : ans.second) {
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