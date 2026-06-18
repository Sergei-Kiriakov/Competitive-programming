//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
//#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

constexpr int mod = 998244353;

string f(int x) {
    if (x >= 0) {
        string s = to_string(x);
        string ans = s + "+" + s + "-0";
        return ans;
    }
    string s = to_string(abs(x));
    string ans = "0-" + s + "-" + s;
    return ans;
}

void solve()
{
    int p, q;
    cin >> p >> q;
    string ans;
    if (abs(p) % 2 == 0 and abs(q) % 2 == 0) {
        for (int i = 0; i < 10; i += 2) {
            if ((p - i) % 10 != 0 and (q - i) % 10 != 0) {
                ans += to_string(i) + "+";
                p -= i;
                q -= i;
                break;
            }
        }
        string f1 = f(p / 2);
        string f2 = f(q / 2);
        reverse(all(f2));
        ans += f1 + "+" + f2;
        cout << ans << endl;
        return;
    }
    if (abs(p) % 2 == 1 and abs(q) % 2 == 0) {
        ans += "12+";
        p -= 12;
        q -= 21;
    }
    if (abs(p) % 2 == 0 and abs(q) % 2 == 1) {
        ans += "21+";
        p -= 21;
        q -= 12;
    }
    for (int i = 1; i < 10; i += 2) {
        if ((p - i) % 10 != 0 and (q - i) % 10 != 0) {
            ans += to_string(i) + "+";
            p -= i;
            q -= i;
            break;
        }
    }
    string f1 = f(p / 2);
    string f2 = f(q / 2);
    reverse(all(f2));
    ans += f1 + "+" + f2;
    cout << ans << endl;
}

int32_t main() {
//    ofstream cout("");
//    ifstream cin("");
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed;
    cout.precision(7);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    int tt = 1;
//    cin >> tt;
    while(tt-->0)
    {
        solve();
    }
}

/*
*/  