// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,fma")

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

//#define int long long
//#define double long double
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

constexpr int mod = 1e9 + 7;

const int maxn = 2e5 + 5;

int solve(int n, vector<float> costs)
{
    vector<int> new_costs(n);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        new_costs[i] = round(costs[i] * 100);
        ans += new_costs[i] - new_costs[i] % 5;
        new_costs[i] %= 5;
    }
    int cnt3 = 0, cnt4 = 0;
    for (int i = 0; i < n; ++i) {
        cnt3 += (new_costs[i] == 3);
        cnt4 += (new_costs[i] == 4);
    }
    int delta = min(cnt3, cnt4);
    ans += delta * 5;
    cnt3 -= delta;
    cnt4 -= delta;
    ans += (cnt3) / 2 * 5;
    ans += (cnt4) / 3 * 10;
    ans += cnt3 % 2 * 3;
    ans += cnt4 % 3 * 4;
    return ans;
}

void input()
{
    int n;
    cin >> n;
    vector<float> costs(n);
    for (int i = 0; i < n; ++i) {
        cin >> costs[i];
    }
    int ans = solve(n, costs);
    string cents = to_string(ans % 100);
    if (cents.size() == 1) {
        cents = '0' + cents;
    }
    cout << ans / 100 << "." << cents << endl;
}

int32_t main()
{
    // ofstream cout("");
    // ifstream cin("");
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed;
    cout.precision(7);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int tt = 1;
//    cin >> tt;
    while(tt-->0)
    {
        input();
    }
}

/*
1
3
6 4 5
1 2 3
*/