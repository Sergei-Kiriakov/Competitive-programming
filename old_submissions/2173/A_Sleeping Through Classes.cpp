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

int solve (int n, int k, string s) {
    int last = -1;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            last = i + k;
        }
        else {
            if (i > last) {
                ++ans;
            }
        }
    }
    return ans;
}

void input() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    auto ans = solve(n, k, s);
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
