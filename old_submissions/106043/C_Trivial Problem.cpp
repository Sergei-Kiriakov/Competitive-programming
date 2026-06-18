/*
-------------------------------------------------------------------------------------------------------------------------------
░░░░░░░░░░░▄▄▀▀▀▀▀▀▀▀▄▄
░░░░░░░░▄▀▀░░░░░░░░░░░░▀▄▄
░░░░░░▄▀░░░░░░░░░░░░░░░░░░▀▄
░░░░░▌░░░░░░░░░░░░░▀▄░░░░░░░▀▀▄
░░░░▌░░░░░░░░░░░░░░░░▀▌░░░░░░░░▌
░░░▐░░░░░░░░░░░░▒░░░░░▌░░░░░░░░▐
░░░▌▐░░░░▐░░░░▐▒▒░░░░░▌░░░░░░░░░▌
░░▐░▌░░░░▌░░▐░▌▒▒▒░░░▐░░░░░▒░▌▐░▐
░░▐░▌▒░░░▌▄▄▀▀▌▌▒▒░▒░▐▀▌▀▌▄▒░▐▒▌░▌
░░░▌▌░▒░░▐▀▄▌▌▐▐▒▒▒▒▐▐▐▒▐▒▌▌░▐▒▌▄▐
░▄▀▄▐▒▒▒░▌▌▄▀▄▐░▌▌▒▐░▌▄▀▄░▐▒░▐▒▌░▀▄
▀▄▀▒▒▌▒▒▄▀░▌█▐░░▐▐▀░░░▌█▐░▀▄▐▒▌▌░░░▀
░▀▀▄▄▐▒▀▄▀░▀▄▀░░░░░░░░▀▄▀▄▀▒▌░▐
░░░░▀▐▀▄▒▀▄░░░░░░░░▐░░░░░░▀▌▐
░░░░░░▌▒▌▐▒▀░░░░░░░░░░░░░░▐▒▐
░░░░░░▐░▐▒▌░░░░▄▄▀▀▀▀▄░░░░▌▒▐
░░░░░░░▌▐▒▐▄░░░▐▒▒▒▒▒▌░░▄▀▒░▐
░░░░░░▐░░▌▐▐▀▄░░▀▄▄▄▀░▄▀▐▒░░▐
░░░░░░▌▌░▌▐░▌▒▀▄▄░░░░▄▌▐░▌▒░▐
░░░░░▐▒▐░▐▐░▌▒▒▒▒▀▀▄▀▌▐░░▌▒░▌
░░░░░▌▒▒▌▐▒▌▒▒▒▒▒▒▒▒▐▀▄▌░▐▒▒
-------------------------------------------------------------------------------------------------------
*/

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

#define int long long
#define double long double
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int mod = 998244353;

int get_mex (vector<int> a) {
    int n = a.size();
    vector<int> cnt(n + 2, 0);
    for (int i = 0; i < n; ++i) {
        if (a[i] <= cnt.size()) {
            ++cnt[a[i]];
        }
    }
    int mex = 1e9;

    return mex;
}

vector<int> solve (int n, vector<int> a) {
    vector<int> left_max(n), right_max(n), g_max(n);

    vector<pair<int, int> > l_st;
    for (int i = 0; i < n; ++i) {
        while (!l_st.empty() and l_st.back().first <= a[i]) {
            l_st.pop_back();
        }
        if (l_st.empty()) {
            left_max[i] = i + 1;
        }
        else {
            left_max[i] = abs(l_st.back().second - i);
        }
        l_st.push_back({a[i], i});
    }

    vector<pair<int, int> > r_st;
    for (int i = n - 1; i > -1; --i) {
        while (!r_st.empty() and r_st.back().first <= a[i]) {
            r_st.pop_back();
        }
        if (r_st.empty()) {
            right_max[i] = n - i;
        }
        else {
            right_max[i] = abs(r_st.back().second - i);
        }
        r_st.push_back({a[i], i});
    }

    for (int i = 0; i < n; ++i) {
        int tt = 1;
//        if (left_max[i] == (int) 1e9 and right_max[i] == (int) 1e9) {
//            tt = 1e9;
//        }
        if (left_max[i] != (int) 1e9) {
            tt += left_max[i] - 1;
        }
        if (right_max[i] != (int) 1e9) {
            tt += right_max[i] - 1;
        }
//        g_max[i] = max(left_max[i], right_max[i]);
        g_max[i] = tt;
    }

    vector<pair<int, int> > ex(n);
    for (int i = 0; i < n; ++i) {
        ex[i] = {g_max[i], a[i]};
    }
    sort(ex.rbegin(), ex.rend());

    vector<int> cnt(n + 3, 0);
    for (int i = 0; i < n; ++i) {
        if (a[i] < cnt.size()) {
            ++cnt[a[i]];
        }
    }
    int mex = 1e9;
    for (int i = 0; i < cnt.size(); ++i) {
        if (cnt[i] == 0) {
            mex = i;
            break;
        }
    }

    vector<int> ans(n, 0);
    ans[0] = mex;
    for (int i = 1; i < n; ++i) {
        while (!ex.empty() and ex.back().first <= i) {
            int v = ex.back().second;
            if (v < cnt.size()) {
                --cnt[v];
            }
            if (cnt[v] == 0 and v < mex) {
                mex = v;
            }
            ex.pop_back();
        }
        ans[i] = mex;
    }
    return ans;
}

void input()
{
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
    // ofstream cout("");
    // ifstream cin("");
    ios::sync_with_stdio(false); cin.tie(nullptr);
//    cout << fixed;
//    cout.precision(9);
    int tt = 1;
//    cin >> tt;


    while(tt-->0)
    {
        input();
    }
//    stress();
}

/*
2 1 1000000000
* 1
!
*/