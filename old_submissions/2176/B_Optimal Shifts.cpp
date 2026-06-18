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
    int ans = 0;
    int now = 0;
    int ind_first_one = 0;
    while (ind_first_one < n and s[ind_first_one] == '0') {
        ++ind_first_one;
    }
    for (int i = ind_first_one; i < n + ind_first_one; ++i) {
        int j = i % n;
        if (s[j] == '0') {
            ++now;
        }
        else {
            ans = max(ans, now);
            now = 0;
        }
    }
    ans = max(ans, now);
    now = 0;
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
