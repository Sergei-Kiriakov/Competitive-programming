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

vector<int> solve (int n, vector<int> a) {
    int cnt_even = 0;
    int cnt_odd = 0;
    int big_odd = 0;
    vector<int> evens;
    for (int i = 0; i < n; ++i) {
        cnt_even += (a[i] % 2 == 0);
        cnt_odd += (a[i] % 2 == 1);
        if (a[i] % 2 == 1) {
            big_odd = max(a[i], big_odd);
        }
        else {
            evens.push_back(a[i]);
        }
    }
    vector<int> ans(n, 0);
    if (cnt_odd == 0) {
        return ans;
    }
    if (cnt_even == 0) {
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) {
                ans[i] = big_odd;
            }
        }
        return ans;
    }
    sort(evens.begin(), evens.end());
    int j = (int) evens.size() - 1;
    int sum_even = 0;
    int sum_ans = big_odd;
    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            ans[i] = sum_ans;
            continue;
        }
        if (j > 0) {
            sum_ans += evens[j];
            --j;
            ans[i] = sum_ans;
        }
        else {
            int dif = i - evens.size() + 1;
            if (dif % 2 == 1) {
                ans[i] = sum_ans + evens[j];
            }
            else {
                ans[i] = sum_ans;
            }
        }
    }
    if (cnt_odd % 2 == 0) {
        ans.back() = 0;
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
    for (auto el : ans) {
        cout << el << " ";
    }
    cout << endl;
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
