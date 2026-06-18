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

vector<int> solve (int n, int k, vector<int> a) {
    sort(a.begin(), a.end());
    vector<int> b;
    b.push_back(a[0]);
    for (int i = 1; i < n; ++i) {
        if (a[i] != a[i - 1]) {
            b.push_back(a[i]);
        }
    }
    a = b;
    n = a.size();
    map<int, int> kk;
    for (int i = 0; i < n; ++i) {
        kk[a[i]] = i;
    }
    vector<bool> used(n);
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        if (used[i]) {
            continue;
        }
        ans.push_back(a[i]);
        used[i] = true;
        int next = a[i] * 2;
        while (next <= k and kk.contains(next)) {
            int ind = kk[next];
            used[ind] = true;
            next += a[i];
        }
        if (next <= k) {
            return {};
        }
    }
    return ans;
}

void input() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    auto ans = solve(n, k, a);
    if (ans.empty()) {
        cout << -1 << endl;
        return;
    }
    cout << ans.size() << endl;
    for (auto el : ans) {
        cout << el << " ";
    }
    cout << endl;
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
