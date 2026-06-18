//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

constexpr int mod = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    vector<vector<int> > a(n, vector<int> (3));
    set<int> b;
    map<int, vector<int> > inds;
    for (int i = 0; i < n; ++i) {
        cin >> a[i][1] >> a[i][2];
        b.insert(a[i][1]);
        b.insert(a[i][2]);
        inds[a[i][1]].push_back(i);
        inds[a[i][2]].push_back(i);
    }
    int ind = 0;
    for (auto el : b) {
        for (auto ind_ : inds[el]) {
            a[ind_][0] += ind;
        }
        ++ind;
    }
    sort(all(a));
    for (int i = 0; i < n; ++i) {
        cout << a[i][1] << " " << a[i][2] << " ";
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