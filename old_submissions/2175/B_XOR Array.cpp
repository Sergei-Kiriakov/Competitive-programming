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

vector<int> solve (int n, int l, int r) {
    --l; --r;
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        b[i] = i + 1;
    }
    if (l == 0) {
        b[r] = 0;
    }
    else {
        b[r] = l;
    }
    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            ans[i] = b[i];
            continue;
        }
        ans[i] = b[i] ^ b[i - 1];
    }
    return ans;
}

void input() {
    int n, l, r;
    cin >> n >> l >> r;
    auto ans = solve(n, l, r);
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
