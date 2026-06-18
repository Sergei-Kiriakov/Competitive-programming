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

int solve (int n, string s) {
    int cnt[3] = {0, 0, 0};
    int cur = 0;
    cnt[0] = 1;
    for (int i = 0; i < n; ++i) {
        cur += (s[i] == '1') ? 1 : -1;
        int r = ((cur % 3) + 3) % 3;
        ++cnt[r];
    }

    int total_pairs = (n + 1) * n / 2;
    int same = 0;
    for (int r = 0; r < 3; ++r) {
        same += cnt[r] * (cnt[r] - 1) / 2;
    }

    int alt_bad = 0;
    int alt = 1;
    for (int i = 0; i < n; ++i) {
        if (i > 0 && s[i] != s[i - 1]) {
            ++alt;
        }
        else {
            alt = 1;
        }
        alt_bad += (alt - 1) / 2;
    }

    int ans = total_pairs - same - alt_bad;
    return ans;
}

void input() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    auto ans = solve(n, s);
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
