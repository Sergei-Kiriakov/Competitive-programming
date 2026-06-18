//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
//#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

constexpr int mod = 998244353;

vector<vector<int> > g, g2;
vector<int> color;
vector<int> top_sort;

bool cycle;

void is_cycle (int v, int del_ver=-1) {
    color[v] = 1;
    for (auto u : g[v]) {
        if (u == del_ver)
            continue;
        if (color[u] == 1) {
            cycle = true;
        }
        if (color[u] == 0)
            is_cycle(u, del_ver);
    }
    color[v] = 2;
    top_sort.push_back(v);
}

vector<int> comp;

void calc_comp(int v) {
    color[v] = 2;
    for (auto u : g2[v]) {
        if (color[u] == 0)
            calc_comp(u);
    }
    comp.push_back(v);
}

void clear_used(const vector<int> & top_sort) {
    for (auto v : top_sort) {
        color[v] = 0;
    }
}

void add_ans(vector<pair<int, int> > &ans, vector<int> & top_sort, int del_ver=-1) {
    reverse(all(top_sort));
    if (del_ver != -1)
        ans.push_back({del_ver, top_sort[0]});
    for (int i = 0; i + 1 < top_sort.size(); ++i) {
        ans.push_back({top_sort[i], top_sort[i + 1]});
    }
    if (del_ver != -1)
        ans.push_back({top_sort.back(), del_ver});
}

void solve()
{
    int n, m;
    cin >> n >> m;

    g = vector<vector<int> > (n);
    g2 = vector<vector<int> > (n);
    color = vector<int> (n, 0);

    for (int i = 0; i < m; ++i) {
        int v, u;
        cin >> v >> u;
        --v; --u;
        g[v].push_back(u);
        g2[u].push_back(v);
        g2[v].push_back(u);
    }
    vector<pair<int, int> > ans;
    for (int i = 0; i < n; ++i) {
        if (color[i] == 0) {
            comp.clear();
            calc_comp(i);
            clear_used(comp);

            cycle = false;
            top_sort.clear();
            for (auto v : comp)
                if (color[v] == 0)
                    is_cycle(v);
            if (!cycle) {
                add_ans(ans, top_sort);
            }
            else {
                for (auto del_ver : comp) {
                    clear_used(top_sort);
                    top_sort.clear();

                    cycle = false;
                    for (auto v : comp)
                        if (color[v] == 0 and v != del_ver)
                            is_cycle(v, del_ver);

                    if (!cycle) {
                        add_ans(ans,top_sort, del_ver);
                        break;
                    }
                }
                if (cycle) {
                    cout << -1 << endl;
                    return;
                }
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
//    cin >> tt;
    while(tt-->0)
    {
        solve();
    }
}

/*
*/  