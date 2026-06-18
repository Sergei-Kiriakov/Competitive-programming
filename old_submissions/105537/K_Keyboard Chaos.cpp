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
    string al = "qwertyuiopasdfghjklzxcvbnm";
    sort(all(al));
    int n, e;
    cin >> n >> e;
    vector<string> a(n);
    set<char> used;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        a[i] = s;
        bool ful = true;
        for (int j = 1; j < s.size(); ++j) {
            if (s[j] != s[j - 1]) {
                ful = false;
            }
        }
        if (ful) {
            used.insert(s[0]);
        }
    }
    bool flag = true;
    for (int i = 0; i < e; ++i) {
        if (!used.contains(al[i])) {
            flag = false;
        }
    }
    if (flag) {
        cout << "NO" << endl;
        return;
    }
    vector<int> counter(e);
    for (int i = 0; i < e; ++i) {
        char c = al[i];
        for (int j = 0; j < n; ++j) {
            for (auto el : a[j]) {
                if (el != c)
                    break;
                ++counter[i];
            }
        }
    }
    int min1 = 1e9;
    char ans;
    for (int i = 0; i < e; ++i) {
        if (min1 > counter[i] and !used.contains(al[i])) {
            min1 = counter[i];
            ans = al[i];
        }
    }
    for (int i = 0; i < min1 + 1; ++i) {
        cout << ans;
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
//    cin >> tt;
    while(tt-->0)
    {
        solve();
    }
}

/*
*/  