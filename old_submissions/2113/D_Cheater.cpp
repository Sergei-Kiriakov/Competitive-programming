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

bool check(int n, int mid, vector<int> & a, vector<int> & b) {
    int k = n - mid;
    int min_b = 1e9;
    for (int i = 0; i < k + 1; ++i) {
        min_b = min(min_b, b[i]);
    }
    int min_a = 1e9, second_min_a = 1e9;
    for (int i = 0; i < mid; ++i) {
        if (min_a >= a[i]) {
            second_min_a = min_a;
            min_a = a[i];
        }
        else if (second_min_a > a[i]) {
            second_min_a = a[i];
        }
    }
    int max_a = -1;
    for (int i = mid; i < n; ++i) {
        max_a = max(max_a, a[i]);
    }
    if (max_a > min_a) {
        swap(max_a, min_a);
    }
    if (max_a > second_min_a)
        swap(max_a, second_min_a);
    return min(second_min_a, min_a) > min_b;
}

int solve(int n, vector<int> a, vector<int> b)
{
    int l = 0, r = n + 1;
    while (r - l > 1) {
        int mid = (r + l) / 2;
        if (check(n, mid, a, b)) {
            l = mid;
        }
        else {
            r = mid;
        }
    }
    return l;
}

void input()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> b(n);
    for (int j = 0; j < n; ++j) {
        cin >> b[j];
    }
    cout << solve(n, a, b) << endl;
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
    cin >> tt;
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