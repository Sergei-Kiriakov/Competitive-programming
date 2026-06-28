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
#define double long double
#define endl "\n"
#define all(x) (x).begin(), (x).end()

const int mod = 1e9 + 7;

int solve (int n, vector<int> a) {
    int ans = 0;

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
    cout << ans << endl;
}

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int tt = 1;
    cin >> tt;

    while (tt-->0)
    {
        input();
    }
}
