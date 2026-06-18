//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

//#define int long long
//#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

constexpr int mod = 1e9 + 7;

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 1; i < n; ++i) {
        if (s[i] == s[i - 1]) {
            cout << s[i] << s[i - 1] << endl;
            return;
        }
    }
    for (int i = 2; i < n; ++i) {
        if (s[i] != s[i - 1] and s[i] != s[i - 2] and s[i - 1] != s[i - 2]) {
            cout << s[i - 2] << s[i - 1] << s[i] << endl;
            return;
        }
    }
    cout << -1 << endl;
}

int main() {
//    ofstream cout("");
//    ifstream cin("");
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed;
    cout.precision(7);
    int tt = 1;
    cin >> tt;
    while(tt-->0)
    {
        solve();
    }
}

/*
*/  