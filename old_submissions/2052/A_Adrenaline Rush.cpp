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

vector<vector<int> > solve (int n, vector<int> a) {
    vector<vector<int> > ans;
    set<int> first;
    for (int i = 0; i < n; ++i) {
        for (int j = a[i] + 1; j <= n; ++j) {
            if (first.contains(j))
                continue;
            ans.push_back({j, a[i]});
        }
        first.insert(a[i]);
        for (int j = n; j > 0; --j) {
            if (first.contains(j)) {
                continue;
            }
            ans.push_back({a[i], j});
        }
    }
    return ans;
}

void input() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    auto ans = solve(n, a);
    cout << ans.size() << endl;
    for (auto el : ans) {
        cout << el[0] << " " << el[1] << endl;
    }
    cout << endl;
}

int32_t main()
{
    int tt = 1;
//    cin >> tt;

    while (tt-->0)
    {
        input();
    }
}
