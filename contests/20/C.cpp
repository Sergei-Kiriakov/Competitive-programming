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

using namespace std;

#define int long long

const int MOD = 1e9 + 7;

vector<int> solve (int n, int m, vector<vector<pair<int, int>  >> g) {
    vector<int> dist(n + 1, 1e18);
    vector<int> pr(n + 1, -1);
    dist[1] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    while (!pq.empty()) {
        auto [d, v] = pq.top();
        pq.pop();
        if (d > dist[v]) {
            continue;
        }
        for (auto [u, w] : g[v]) {
            if (dist[v] + w < dist[u]) {
                dist[u] = dist[v] + w;
                pr[u] = v;
                pq.push({dist[u], u});
            }
        }
    }
    vector<int> ans;
    if (dist[n] == (int) 1e18) {
        return ans;
    }
    int cur = n;
    while (cur != -1) {
        ans.push_back(cur);
        cur = pr[cur];
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

void input() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int> > > g(n + 1);
    for (int i = 0; i < m; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        g[a].push_back({b, w});
        g[b].push_back({a, w});
    }
    auto ans = solve(n, m, g);
    if (ans.empty()) {
        cout << -1 << endl;
    }
    else {
        for (auto el : ans) {
            cout << el << " ";
        }
        cout << endl;
    }
}

int32_t main()
{
    int tt = 1;
    // cin >> tt;

    while (tt-->0)
    {
        input();
    }
}
