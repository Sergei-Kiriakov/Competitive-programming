// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

constexpr int mod = 1e9 + 7;

vector<vector<int> > g;
vector<bool> used;
vector<int> pred;

pair<int, int> find_far(int v, int p=-1) {
    pred[v] = p;
    int max_d = 0;
    int max_v = v;
    for (auto u : g[v]) {
        if (used[u])
            continue;
        if (u == p)
            continue;
        auto [w, d] = find_far(u, v);
        if (d > max_d) {
            max_v = w;
            max_d = d;
        }
        else if (d == max_d and w > max_v) {
            max_v = w;
            max_d = d;
        }
    }
    return {max_v, max_d + 1};
}

vector<int> find_diam (int w) {
    auto [u, d1] = find_far(w);
    auto [v, d2] = find_far(u);

    vector<int> path = {v};
    while (path.back() != u) {
        path.push_back(pred[path.back()]);
    }

    for (auto el : path) {
        used[el] = true;
    }

    return {d2, max(v, u) + 1, min(v, u) + 1};
}

vector<int> solve(int n, vector<pair<int, int> > edges)
{
    // init
    used = vector<bool> (n, false);
    pred = vector<int> (n, -1);
    g = vector<vector<int> > (n);
    for (int i = 0; i < n - 1; ++i) {
        int u = edges[i].first - 1, v = edges[i].second - 1;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int v = 0;
    set<vector<int> > ans;
    while(v < n) {
        while (!used[v]) {
            vector<int> temp = find_diam(v);
            temp[0] = -temp[0];
            temp[1] = -temp[1];
            temp[2] = -temp[2];
            ans.insert(temp);
        }
        ++v;
    }
    vector<int> anss;
    for (auto vec : ans) {
        anss.push_back(-vec[0]);
        anss.push_back(-vec[1]);
        anss.push_back(-vec[2]);
    }
    return anss;
}

void input()
{
    int n;
    cin >> n;
    vector<pair<int, int> > edges(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        cin >> edges[i].first >> edges[i].second;
    }
    vector<int> ans = solve(n, edges);
    for (auto el : ans) {
        cout << el << " ";
    }
    cout << endl;
}

int32_t main()
{
    // ofstream cout("");
    // ifstream cin("");
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed;
    cout.precision(7);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int tt = 1;
    cin >> tt;
    while(tt-->0)
    {
        input();
    }
}

/*
*/