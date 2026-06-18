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

struct Node {
    int o, c, m;
};

Node merge (Node a, Node b) {
    int t = min(a.o, b.c);
    return {a.o + b.o - t, a.c + b.c - t, a.m + b.m + t};
}

vector<int> solve (int n, string s, int m, vector<int> ql, vector<int> qr) {
    vector<Node> tree(4 * n);
    function<void(int, int, int)> build = [&](int node, int l, int r) {
        if (l == r) {
            if (s[l] == '(') {
                tree[node] = {1, 0, 0};
            }
            else {
                tree[node] = {0, 1, 0};
            }
            return;
        }
        int mid = (l + r) / 2;
        build(2 * node, l, mid);
        build(2 * node + 1, mid + 1, r);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    };
    build(1, 0, n - 1);

    function<Node(int, int, int, int, int)> query = [&](int node, int l, int r, int lq, int rq) -> Node {
        if (lq <= l && r <= rq) {
            return tree[node];
        }
        int mid = (l + r) / 2;
        if (rq <= mid) {
            return query(2 * node, l, mid, lq, rq);
        }
        if (lq > mid) {
            return query(2 * node + 1, mid + 1, r, lq, rq);
        }
        return merge(query(2 * node, l, mid, lq, rq), query(2 * node + 1, mid + 1, r, lq, rq));
    };

    vector<int> ans(m);
    for (int i = 0; i < m; ++i) {
        Node res = query(1, 0, n - 1, ql[i] - 1, qr[i] - 1);
        ans[i] = 2 * res.m;
    }
    return ans;
}

void input() {
    string s;
    cin >> s;
    int n = s.size();
    int m;
    cin >> m;
    vector<int> ql(m), qr(m);
    for (int i = 0; i < m; ++i) {
        cin >> ql[i] >> qr[i];
    }
    auto ans = solve(n, s, m, ql, qr);
    for (auto el : ans) {
        cout << el << endl;
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
