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

vector<int> solve (int n, vector<int> a, vector<int> b) {
    vector<int> A(n + 1), B(n + 1);
    for (int i = 1; i <= n; ++i) {
        A[i] = a[i - 1];
        B[i] = b[i - 1];
    }

    vector<int> cyc_id(n + 1, -1);
    vector<int> pos_in(n + 1, 0);
    vector<int> min_elem;
    vector<int> cyc_len;
    vector<vector<int>> cyc_elems;

    int num_cyc = 0;
    for (int i = 1; i <= n; ++i) {
        if (cyc_id[i] == -1) {
            vector<int> cur;
            int x = i;
            while (cyc_id[x] == -1) {
                cyc_id[x] = num_cyc;
                pos_in[x] = (int) cur.size();
                cur.push_back(x);
                x = A[x];
            }
            int mn = n + 1;
            for (auto e : cur) {
                mn = min(mn, e);
            }
            min_elem.push_back(mn);
            cyc_len.push_back((int) cur.size());
            cyc_elems.push_back(cur);
            ++num_cyc;
        }
    }

    vector<int> target_cyc(num_cyc, -1);
    vector<int> off(num_cyc, 0);
    vector<int> claimed_by(num_cyc, -1);

    // prefilled entries fix the target cycle and offset of their source cycle
    for (int i = 1; i <= n; ++i) {
        if (B[i] != -1) {
            int v = B[i];
            int c = cyc_id[i];
            int tc = cyc_id[v];
            if (cyc_len[c] != cyc_len[tc]) {
                return {};
            }
            int len = cyc_len[c];
            int s = ((pos_in[v] - pos_in[i]) % len + len) % len;
            if (target_cyc[c] == -1) {
                target_cyc[c] = tc;
                off[c] = s;
            }
            else {
                if (target_cyc[c] != tc || off[c] != s) {
                    return {};
                }
            }
        }
    }

    // every target cycle may be claimed by at most one source cycle
    for (int c = 0; c < num_cyc; ++c) {
        if (target_cyc[c] != -1) {
            int tc = target_cyc[c];
            if (claimed_by[tc] != -1) {
                return {};
            }
            claimed_by[tc] = c;
        }
    }

    // per length, keep unclaimed target cycles ordered by their smallest element
    unordered_map<int, priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>> heaps;
    for (int c = 0; c < num_cyc; ++c) {
        if (claimed_by[c] == -1) {
            heaps[cyc_len[c]].push({min_elem[c], c});
        }
    }

    // assign free cycles greedily; the first index of a free cycle is its minimum
    for (int i = 1; i <= n; ++i) {
        int c = cyc_id[i];
        if (target_cyc[c] == -1 && min_elem[c] == i) {
            int len = cyc_len[c];
            auto &h = heaps[len];
            pair<int, int> top = h.top();
            h.pop();
            int tc = top.second;
            target_cyc[c] = tc;
            claimed_by[tc] = c;
            int s = ((pos_in[min_elem[tc]] - pos_in[i]) % len + len) % len;
            off[c] = s;
        }
    }

    vector<int> res(n);
    for (int i = 1; i <= n; ++i) {
        int c = cyc_id[i];
        int tc = target_cyc[c];
        int len = cyc_len[c];
        int p = (pos_in[i] + off[c]) % len;
        res[i - 1] = cyc_elems[tc][p];
    }

    return res;
}

void input() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    auto ans = solve(n, a, b);
    if (ans.empty()) {
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl;
        for (auto el : ans) {
            cout << el << " ";
        }
        cout << endl;
    }
}

int32_t main()
{
    int tt = 1;
    cin >> tt;

    while (tt-->0)
    {
        input();
    }
}
