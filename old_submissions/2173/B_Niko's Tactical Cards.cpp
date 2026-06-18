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

int solve (int n, vector<int> a, vector<int> b) {
    int max1 = 0, min1 = 0;
    for (int i = 0; i < n; ++i) {
        vector<int> res;
        res.push_back(max1 - a[i]);
        res.push_back(min1 - a[i]);
        res.push_back(b[i] - max1);
        res.push_back(b[i] - min1);
        sort(res.begin(), res.end());
        min1 = res[0];
        max1 = res.back();
    }
    return max1;
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
    cout << ans << endl;
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
