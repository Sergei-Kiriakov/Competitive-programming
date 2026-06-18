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
    vector<int> l(n);
    for (int i = 0; i < n; ++i) {
        int lo = 0;
        int hi = n;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (b[mid] >= a[i]) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }
        l[i] = lo;
    }

    vector<bool> free_pos(n, true);
    int ans = 0;
    for (int v = 0; v < n; ++v) {
        int left_free = 0;
        bool placed = false;
        for (int i = 0; i < n; ++i) {
            if (free_pos[i]) {
                if (l[i] <= v) {
                    free_pos[i] = false;
                    ans += left_free;
                    placed = true;
                    break;
                }
                else {
                    ++left_free;
                }
            }
        }
        if (!placed) {
            return -1;
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
    vector<int> b(n);
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
