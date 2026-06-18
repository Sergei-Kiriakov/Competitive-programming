//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

//#define int long long
//#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

constexpr int mod = 1e9 + 7;

int f(vector<int>& S) {
    if (S.size() == 0)
        return 0;
    if (S.size() == 1)
        return S[0] + 1;
    int n = S.size();
    sort(all(S));
    vector<int> st;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (st.empty()) {
            st.push_back(S[i]);
            continue;
        }
        int now = S[i];
        while (!st.empty() and st.back() <= now) {
            if (now == st.back()) {
                ++now;
                --cnt;
            }
            st.pop_back();
            ++cnt;
        }
        st.push_back(now);
    }
    return st[0] + (cnt != 0 or st.size() != 1);
}

int get_ans(int v, const vector<vector<int> > &g) {
    vector<int> S;
    for (auto u : g[v]) {
        S.push_back(get_ans(u, g));
    }
    return f(S);
}

void solve()
{
    int n;
    cin >> n;
    vector<vector<int> > g(n);
    for (int i = 1; i < n; ++i) {
        int p;
        cin >> p;
        --p;
        g[p].push_back(i);
    }
    cout << get_ans(0, g) << endl;
}

int main() {
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