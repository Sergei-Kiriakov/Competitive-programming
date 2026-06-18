// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

//#define int long long
//#define double long double
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

constexpr int mod = 1e9 + 7;

string solve(int n, string s)
{
    int cntW = 0;
    int cntR = 0;
    for (int i = 0; i < n; ++i) {
        cntW += s[i] == 'W';
        cntR += s[i] == 'R';
    }
    if (cntW % 2 == 1) {
        return "NO";
    }
    string s1, s2;
    int br_cntW_s1 = cntW / 2;
    int br_cntW_s2 = n - br_cntW_s1;
    int cntW_s1 = 0,  cntW_s2 = 0;
    for (int i = 0; i < 2 * n; ++i) {
        if (s[i] == 'W') {
            if (cntW_s1 < br_cntW_s1) {
                ++cntW_s1;
                s1 += s[i];
            }
            else {
                ++cntW_s2;
                s2 += s[i];
            }
        }
        else {
            if (s1.size() < n) {
                if (cntW_s1 < br_cntW_s1) {
                    return "NO";
                }
                s1 += s[i];
            }
            else {
                if (cntW_s2 < br_cntW_s2) {
                    return "NO";
                }
                s2 += s[i];
            }
        }
    }
    return "YES";
}

void input()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    string ans = solve(n, s);
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
    cin >> tt;
    while(tt-->0)
    {
        input();
    }
}

/*
*/