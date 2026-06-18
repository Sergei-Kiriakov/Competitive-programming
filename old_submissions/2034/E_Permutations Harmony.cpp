//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

//#define int long long
//#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

constexpr int mod = 998244353;

vector<int> oposite(const vector<int> &a) {
    int n = a.size();
    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
        ans[i] = (n + 1) - a[i];
    }
    return ans;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    int fact = 1;
    for (int d = 2; d <= n and d <= 15; ++d) {
        fact *= d;
    }
    if ((k == 1 && n > 1) or (k % 2 == 1 && n % 2 == 0) or fact < k) {
        cout << "NO" << endl;
        return;
    }
    if (k == 1 and n == 1) {
        cout << "YES" << endl;
        cout << 1 << endl;
        return;
    }
    vector<vector<int> > ans;
    if (k % 2 == 0) {
        vector<int> start(n);
        iota(all(start), 1);
        do {
            vector<int> op = oposite(start);
            ans.push_back(start);
            ans.push_back(op);
            k -= 2;
        }
        while (k > 0 and next_permutation(all(start)));
        cout << "YES" << endl;
        for (int i = 0; i < ans.size(); ++i) {
            for (int j = 0; j < ans[i].size(); ++j) {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
        return;
    }
    set<vector<int> > s;
    vector<int> a_(n);
    for (int i = 0; i < n; ++i)
        a_[i] = i + 1;
    s.insert(a_);
    ans.push_back(a_);
    vector<int> b_(n);
    for (int i = 0; i < n; i += 2) {
        b_[i] = n - i / 2;
    }
    for (int i = 1; i < n; i += 2) {
        b_[i] = n - (n + 1) / 2 - i / 2;
    }
    s.insert(b_);
    ans.push_back(b_);
    vector<int> c_(n);
    for (int i = 0; i < n; ++i) {
        c_[i] = (n + 1) * 3 / 2 - a_[i] - b_[i];
    }
    s.insert(c_);
    ans.push_back(c_);
    k -= 3;
    vector<int> start(n);
    iota(all(start), 1);
    while (k > 0 and next_permutation(all(start))) {
        vector<int> op = oposite(start);
        if (!s.contains(start) and !s.contains(op)) {
            ans.push_back(start);
            ans.push_back(op);
            s.insert(start);
            s.insert(op);
            k -= 2;
        }
    }
    if (k != 0) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    for (int i = 0; i < ans.size(); ++i) {
        for (int j = 0; j < ans[i].size(); ++j) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
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