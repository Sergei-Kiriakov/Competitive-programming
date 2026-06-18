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

bool check(int x, int p, int ost) {
    int bord = 1 << p;
    int free = bord - x;
    free /= 2;
    int al_free = 0;
    int d = 0;
    while (free != 0) {
        if (free & 1) {
            al_free += (1 << (d + 1)) - 1;
        }
        free >>= 1;
        ++d;
    }
    return al_free + ost >= x;
}

int solve (int n) {
    int p = -1;
    while (n >= (1 << (p + 1)) - 1) {
        ++p;
    }
    int ost = n - ((1 << p) - 1);
    int ans = 1 << (p - 1);
    int l = ost, r = (1 << p) + 1;
    while (r - l > 1) {
        int mid = (r + l) / 2;
        if (check(mid, p, ost)) {
            l = mid;
        }
        else {
            r = mid;
        }
    }
    return max(ans, l);
}

void input()
{
    int n;
    cin >> n;
    cout << solve(n) << endl;
}

int32_t main()
{
    // ofstream cout("");
    // ifstream cin("");
    ios::sync_with_stdio(false); cin.tie(nullptr);
//    cout << fixed;
//    cout.precision(9);
    int tt = 1;
    cin >> tt;


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