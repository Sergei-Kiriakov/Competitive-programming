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

int solve (int r, int g, int b) {
    vector<int> a = {r, g, b};
    sort(a.begin(), a.end());
    return min((a[0] + a[1] + a[2]) / 3, a[0] + a[1]);
}

void input() {
    int r, g, b;
    cin >> r >> g >> b;
    auto ans = solve(r, g, b);
    cout << ans << endl;
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
