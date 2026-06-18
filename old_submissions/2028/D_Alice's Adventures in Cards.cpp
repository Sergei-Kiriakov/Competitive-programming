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
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    int max_a = a[0];
    int max_ind_a = 0;
    int max_b = b[0];
    int max_ind_b = 0;
    int max_c = c[0];
    int max_ind_c = 0;
    vector<pair<int, int> > parent(n, {-1, -1});
    for (int i = 1; i < n; ++i) {
        if (max_a > a[i]) {
            parent[i] = {max_ind_a, 0};
        }
        if (max_b > b[i]) {
            parent[i] = {max_ind_b, 1};
        }
        if (max_c > c[i]) {
            parent[i] = {max_ind_c, 2};
        }
        if (max_a > a[i] or max_b > b[i] or max_c > c[i]) {
            if (max_a < a[i]) {
                max_a = a[i];
                max_ind_a = i;
            }
            if (max_b < b[i]) {
                max_b = b[i];
                max_ind_b = i;
            }
            if (max_c < c[i]) {
                max_c = c[i];
                max_ind_c = i;
            }
        }
    }
    if (parent[n - 1].first == -1 and parent[n - 1].second == -1) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    vector<pair<char, int> > ans;
    int last_p = n - 1;
    int p = parent[n - 1].first;
    int ind = parent[n - 1].second;
    map<int, char> tr;
    tr[0] = 'q';
    tr[1] = 'k';
    tr[2] = 'j';
    while (p != -1) {
        ans.push_back({tr[ind], last_p + 1});
        ind = parent[p].second;
        last_p = p;
        p = parent[p].first;
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (auto el : ans) {
        cout << el.first << " " << el.second << endl;
    }
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