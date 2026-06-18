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

string solve (string s, string t) {
    vector<int> cnt(30, 0);
    for (int i = 0; i < t.size(); ++i) {
        ++cnt[t[i] - 'a'];
    }
    for (int i = 0; i < s.size(); ++i) {
        --cnt[s[i] - 'a'];
        if (cnt[s[i] - 'a'] < 0) {
            return "Impossible";
        }
    }
    int ind = 0;
    string ans;
    for (int i = 0; i < s.size(); ++i) {
        while (ind < s[i] - 'a') {
            for (int j = 0; j < cnt[ind]; ++j) {
                ans += 'a' + ind;
            }
            cnt[ind] = 0;
            ++ind;
        }
        ans += s[i];
    }
    for (int i = ind; i < cnt.size(); ++i) {
        for (int j = 0; j < cnt[i]; ++j) {
            ans += 'a' + i;
        }
    }
    return ans;
}

void input() {
    string s, t;
    cin >> s >> t;
    auto ans = solve(s, t);
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
