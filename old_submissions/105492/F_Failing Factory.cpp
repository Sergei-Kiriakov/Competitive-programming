// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,fma")

#include <functional>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <map>
#include <list>
#include <math.h>
#include <cstdlib>
#include <fstream>
#include <queue>
#include <set>
#include <vector>
#include <stack>
#include <bitset>
#include <random>
#include <chrono>
#include <cassert>
#include <memory>

#define int long long
#define double long double
//#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

constexpr int mod = 1e9 + 7;

vector<vector<int> > g, gr, gg;
vector<int> order, component;
vector<bool> used;
vector<double> mem;

void dfs1 (int v, int p = -1) {
    used[v] = true;
    for (auto u : g[v]) {
        if (used[u])
            continue;
        dfs1(u);
    }
    order.push_back(v);
}

void dfs2 (int v) {
    used[v] = true;
    component.push_back(v);
    for (int u : gr[v]) {
        if (used[u])
            continue;
        dfs2(u);
    }
}

double dfs (int v, map<int, int> & ind, vector<double> & prob) {
    used[v] = true;
    double max_ans = -1;
    for (int u : gg[v]) {
        if (used[u]) {
            max_ans = max(max_ans, mem[u]);
            continue;
        }
        max_ans = fmax(dfs(u, ind, prob), max_ans);
    }
    if (max_ans == -1) {
        max_ans = prob[v];
    }
    mem[v] = max_ans;
    return max_ans;
}

double solve(int n, int m, vector<double> p, vector<vector<int> > edges)
{
    g = vector<vector<int> > (n);
    gr = vector<vector<int> > (n);
    order.clear();
    component.clear();
    used = vector<bool> (n, false);
    for (int i = 0; i < m; ++i) {
        int v = edges[i][0], u = edges[i][1];
        --v;
        --u;
        g[v].push_back(u);
        gr[u].push_back(v);
    }

    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            dfs1(i);
        }
    }

    used = vector<bool> (n, false);
    reverse(all(order));
    map<int, int> ind;
    vector<double> prob;
    int tt = 0;
    for (int i = 0; i < n; ++i) {
        int v = order[i];
        if (used[v])
            continue;
        dfs2(v);
        double prob_ok = 1;
        for (auto el : component) {
            ind[el] = tt;
            prob_ok *= (1 - p[el]);
        }
        ++tt;
        prob.push_back(prob_ok);
        component.clear();
    }

    gg = vector<vector<int> > (prob.size());
    for (int i = 0; i < m; ++i) {
        int u = edges[i][0], v = edges[i][1];
        --u; --v;
        u = ind[u], v = ind[v];
        if (u == v)
            continue;
        gg[u].push_back(v);
    }
    used = vector<bool> (n, false);
    mem = vector<double> (n, 0);

    double max_ans = 0;
    for (int i = 0; i < prob.size(); ++i) {
        if (used[i])
            continue;
        max_ans = fmax(dfs(i, ind, prob), max_ans);
    }
    return max_ans;
}

void input()
{
    int n, m;
    cin >> n >> m;
    vector<double> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    vector<vector<int> > edges(m, vector<int> (2));
    for (int i = 0; i < m; ++i) {
        cin >> edges[i][0] >> edges[i][1];
    }
    double ans = solve(n, m, p, edges);
    cout << ans << endl;
}

int32_t main()
{
    // ofstream cout("");
    // ifstream cin("");
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed;
    cout.precision(200);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int tt = 1;
//    cin >> tt;
    while(tt-->0)
    {
        input();
    }
}

/*
*/