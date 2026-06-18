//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
//#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

constexpr int mod = 1e9 + 7;

bool ask(int a, int b) {
    cout << "? " << a << " " << b << endl;
    bool x;
    cin >> x;
    return !x;
}

void solve()
{
    int n;
    cin >> n;
    vector<vector<int> > ans;
    ans.push_back({n - 1});
    set<pair<int, int> > key;
    for (int i = n - 2; i >= 1; --i) {
        bool flag = ask(n - 1, i);
        if (flag) {
            ans[0].push_back(i);
            continue;
        }
        if (key.size() == 0) {
            key.insert({i, ans.size()});
            ans.push_back({i});
            continue;
        }
        auto it = --(key.end());
        pair<int, int> temp = *it;
        int big = temp.first;
        int ind = temp.second;
        flag = ask(big, i);
        if (flag) {
            key.erase(--key.end());
            key.insert({i, ind});
            ans[ind].push_back(i);
            continue;
        }
        key.insert({i, ans.size()});
        ans.push_back({i});
    }
    vector<int> anss(n + 1, -1);
    for (int i = 0; i < ans.size(); ++i) {
        for (int j = 0; j < ans[i].size() - 1; ++j) {
            anss[ans[i][j]] = ans[i][j + 1];
        }
        anss[ans[i].back()] = 0;
    }
    cout << "! ";
    for (int i = 1; i < n; ++i) {
        cout << anss[i] << " ";
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
    int tt = 1;
    cin >> tt;
    while(tt-->0)
    {
        solve();
    }
}

/*
*/  