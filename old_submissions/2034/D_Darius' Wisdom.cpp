//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
//#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

constexpr int mod = 998244353;

int f_min (const set<int> & ind) {
    int ans = 1e9;
    if (!ind.empty()) {
        ans = *ind.begin();
    }
    return ans;
}

int f_max (const set<int> & ind) {
    int ans = -1;
    if (!ind.empty()) {
        ans = *(--ind.end());
    }
    return ans;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    set<int> ind0, ind1, ind2;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == 0) {
            ind0.insert(i);
        }
        if (a[i] == 1) {
            ind1.insert(i);
        }
        if (a[i] == 2) {
            ind2.insert(i);
        }
    }
    vector<pair<int, int> > ans;
    for (int i = n - 1; i > -1; --i) {
        int max0 = f_max(ind0);
        int max1 = f_max(ind1);
        int max2 = f_max(ind2);
        int min0 = f_min(ind0);
        int min1 = f_min(ind1);
        int min2 = f_min(ind2);
//        auto it0 = --ind0.end();
//        auto it1 = --ind1.end();
//        auto it2 = --ind2.end();
        if (max0 < min1 and max1 < min2) {
            break;
        }
        if (a[i] == 1) {
            if (!ind2.empty() and !ind1.empty() and *(--ind1.end()) > *ind2.begin()) {
                int j = *ind2.begin();
                --a[j];
                ans.push_back({i, j});
                ind1.erase(i);
                ind1.insert(*ind2.begin());
                ind2.erase(ind2.begin());
                ind2.insert(i);
                ++a[i];
            }
        }
        if (a[i] == 0) {
            if (!ind1.empty() and !ind0.empty() and *(--ind0.end()) > *ind1.begin()) {
                int j = *ind1.begin();
                ans.push_back({i, j});
                --a[j];
                ind0.erase(i);
                ind0.insert(j);
                ind1.erase(ind1.begin());
                ind1.insert(i);
                ++a[i];
            }
            if (!ind2.empty() and !ind1.empty() and *(--ind1.end()) > *ind2.begin()) {
                int j = *ind2.begin();
                --a[j];
                ans.push_back({i, j});
                ind1.erase(i);
                ind1.insert(j);
                ind2.erase(ind2.begin());
                ind2.insert(i);
                ++a[i];
            }
        }
    }
    cout << ans.size() << endl;
    for (auto el : ans) {
        cout << el.first + 1 << " " << el.second + 1 << endl;
    }
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