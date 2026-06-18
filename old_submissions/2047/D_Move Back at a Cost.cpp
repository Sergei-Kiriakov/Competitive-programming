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
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> pr_r_min(n);
    pr_r_min[n - 1] = a[n - 1];
    for (int i = n - 2; i > -1; --i) {
        pr_r_min[i] = min(pr_r_min[i + 1], a[i]);
    }
    vector<int> ans;
    vector<int> b;
    for (int i = 0; i < n; ++i) {
        if (pr_r_min[i] == a[i]) {
            ans.push_back(a[i]);
        }
        else {
            b.push_back(a[i] + 1);
        }
    }
    if (b.empty()) {
        for (auto el : ans)
            cout << el << " ";
        cout << endl;
        return;
    }
    sort(all(b));
    while (!ans.empty() and ans.back() > b[0]) {
        b.push_back(ans.back() + 1);
        ans.pop_back();
    }
    sort(all(b));
    for (auto el : b) {
        ans.push_back(el);
    }
    for (auto el : ans) {
        cout << el << " ";
    }
    cout << endl;
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
 * set<pair<int, int> > b;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        b.insert({a[i], i});
    }
    vector<int> pr_r(n);
    pr_r[n - 1] = a[n - 1];
    for (int i = n - 2; i > -1; --i) {
        pr_r[i] = max(pr_r[i + 1], a[i]);
    }
    vector<int> ans;
    int ind_b = 0;
    set<pair<int, int> > c;
    int last_ind = -1;
    for (int i = 0; i < n; ++i) {
        while (!c.empty() and (*c.begin()).first <= (*b.begin()).first) {
            ans.push_back((*c.begin()).first);
            b.erase({(*c.begin()).first - 1, (*c.begin()).second});
            c.erase(c.begin());
        }
        if ((*b.begin()).first == a[i]) {
            ans.push_back(a[i]);
            ++ind_b;
            last_ind = i;
            continue;
        }
        c.insert(a[i] + 1);
    }
    while (!c.empty()) {
        ans[ind] = *c.begin();
        c.erase(c.begin());
        ++ind;
    }
    for (auto el : ans) {
        cout << el << " ";
    }
    cout << endl;
*/