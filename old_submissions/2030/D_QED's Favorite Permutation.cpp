//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

constexpr int mod = 1e9 + 7;

bool check(int ind, const vector<pair<int, int> > & ot) {
    int l = -1, r = ot.size();
    while (r - l > 1) {
        int mid = (r + l) / 2;
        if (ot[mid].second < ind) {
            l = mid;
        }
        else {
            r = mid;
        }
    }
    return (ot[r].first < ind and ot[r].second >= ind);
}

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    string s;
    cin >> s;
    vector<pair<int, int> > ot;
    int l = 0, r = 0;
    int min1 = 1e9, max1 = -1;
    while (l < n) {
        r = l + 1;
        set<int> ss;
        ss.insert(a[l]);
        while (r < n and (*ss.begin() != l + 1 or *(--ss.end()) != r or ss.size() != r - l)) {
            ss.insert(a[r]);
            ++r;
        }
        ot.push_back({l, r - 1});
        min1 = 1e9;
        max1 = -1;
        l = r;
    }
    map<int, bool> c;
    int cnt_bad = 0;
    for (int i = 1; i < n; ++i) {
        if (s[i] == 'R' and s[i - 1] == 'L') {
            bool flag = check(i, ot);
            c[i] = flag;
            if (flag)
                ++cnt_bad;
        }
    }
    for (int i = 0; i < q; ++i) {
        int ind;
        cin >> ind;
        --ind;
        char new_el = 'L';
        if (s[ind] == 'L') {
            new_el = 'R';
        }
        if (ind != 0 and s[ind - 1] == 'L' and s[ind] == 'R') {
            if (c.contains(ind) and c[ind]) {
                --cnt_bad;
            }
            c.erase(ind);
        }
        if (ind != n - 1 and s[ind] == 'L' and s[ind + 1] == 'R') {
            if (c.contains(ind + 1) and c[ind + 1]) {
                --cnt_bad;
            }
            c.erase(ind + 1);
        }
        s[ind] = new_el;
        if (ind != 0 and s[ind - 1] == 'L' and s[ind] == 'R') {
            bool flag = check(ind, ot);
            c[ind] = flag;
            if (flag)
                ++cnt_bad;
        }
        if (ind != n - 1 and s[ind] == 'L' and s[ind + 1] == 'R') {
            bool flag = check(ind + 1, ot);
            c[ind + 1] = flag;
            if (flag)
                ++cnt_bad;
        }
        if (cnt_bad == 0) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
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
 *
1
5 2
2 1 4 3 5
RLRLL
3
3
*/  