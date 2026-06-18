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

string solve(int n, vector<vector<int> > scores)
{
    int score_a = 0, score_b = 0;
    for (int i = 0; i < n; ++i) {
        if (score_a > scores[i][0] or score_b > scores[i][1]) {
            return "no";
        }
        score_a = scores[i][0];
        score_b = scores[i][1];
    }
    return "yes";
}

void input()
{
    int n;
    cin >> n;
    vector<vector<int> > scores(n, vector<int> (2));
    for (int i = 0; i < n; ++i) {
        cin >> scores[i][0] >> scores[i][1];
    }
    string ans = solve(n, scores);
    cout << ans << endl;
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