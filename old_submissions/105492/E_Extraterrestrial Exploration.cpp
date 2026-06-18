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
//#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

constexpr int mod = 1e9 + 7;

const int maxn = 2e5 + 5;

int ask(int n) {
    cout << "? " << n << endl;
    int ans;
    cin >> ans;
    return ans;
}

void solve(int n)
{
    int min1 = ask(1);
    int max1 = ask(n);
    double bord = (min1 + max1) / 2;
    int l = 2, r = n;
    while (r - l > 1) {
        int mid = (r + l) / 2;
        int mid_res = ask(mid);
        if (mid_res > bord) {
            r = mid;
        }
        else {
            l = mid;
        }
    }
    int mid_l = ask(l), mid_r = ask(r);
    int mid_ans = l;
    if (fabs(mid_l - bord) > fabs(mid_r - bord) and r != n) {
        mid_ans = r;
    }
    cout << "! " << 1 << " " << mid_ans << " " << n << endl;
}

void input()
{
    int n;
    cin >> n;
    solve(n);
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