//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

constexpr int mod = 1e9 + 7;
const int dx = 179, dy = 101;

//const int dx = 1000, dy = 1000;

int bin_pow(int a, int n) {
    int ans = 1;
    while (n) {
        if (n & 1) {
            ans = (ans * a) % mod;
        }
        a = (a * a) % mod;
        n >>= 1;
    }
    return ans;
}

int inverse_mod(int a) {
    return bin_pow(a, mod - 2);
}

void construct_hash(int n, int m, vector<vector<int> > & h, vector<string> & s) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i == 0 and j == 0) {
                continue;
            }
            if (i - 1 > -1) {
                h[i][j] = (h[i][j] + h[i - 1][j] * dx) % mod;
            }
            if (j - 1 > -1) {
                h[i][j] = (h[i][j] + h[i][j - 1] * dy) % mod;
            }
            h[i][j] = (h[i][j] + s[i][j]) % mod;
            if (j - 1 > -1 and i - 1 > -1) {
                h[i][j] = (h[i][j] + mod * mod - h[i - 1][j - 1] * dx * dy) % mod;
            }
        }
    }
}

void solve()
{
    int n1, m1;
    cin >> n1 >> m1;
    vector<string> s1(n1);
    for (int i = 0; i < n1; ++i) {
        cin >> s1[i];
    }

    vector<vector<int> > h1(n1, vector<int> (m1, 0));
    h1[0][0] = (int) s1[0][0];


    vector<int> v_dx(1e4, 1);
    vector<int> v_dy(1e4, 1);
    for (int i = 1; i < v_dx.size(); ++i) {
        v_dx[i] = (v_dx[i - 1] * dx) % mod;
        v_dy[i] = (v_dy[i - 1] * dy) % mod;
    }

    construct_hash(n1, m1, h1, s1);

    int n2, m2;
    cin >> n2 >> m2;
    vector<string> s2(n2);
    for (int i = 0; i < n2; ++i) {
        cin >> s2[i];
    }

    vector<vector<int> > h2(n2, vector<int> (m2, 0));
    h2[0][0] = (int) s2[0][0];

    construct_hash(n2, m2, h2, s2);

    vector<vector<bool> > ans(n2, vector<bool> (m2, false));

    for (int i = n1 - 1; i < n2; ++i) {
        for (int j = m1 - 1; j < m2; ++j) {
            int i1 = i, j1 = j;
            int i2 = i1 - n1 + 1, j2 = j1 - m1 + 1;
            int ll = h1[n1 - 1][m1 - 1];
//            int ll = h1[n1 - 1][m1 - 1] * v_dx[i2] % mod * v_dy[j2] % mod;
            int rr = h2[i1][j1];
            if (j2 - 1 > -1) {
                rr = (rr - h2[i1][j2 - 1] * v_dy[m1] + mod * mod) % mod;
            }
            if (i2 - 1 > -1) {
                rr = (rr - h2[i2 - 1][j1] * v_dx[n1] + mod * mod) % mod;
            }
            if (i2 - 1 > -1 and j2 - 1 > -1) {
                rr = (rr + h2[i2 - 1][j2 - 1] * v_dx[n1] % mod * v_dy[m1] + mod * mod) % mod;
            }
            if (ll == rr) {
                ans[i][j] = true;
            }
        }
    }

    vector<vector<bool> > used (n2, vector<bool> (m2, false));

    for (int i = 0; i < n2; ++i) {
        for (int j = 0; j < m2; ++j) {
            if (ans[i][j]) {
                int i1 = i, j1 = j;
                int i2 = i1 - n1 + 1, j2 = j1 - m1 + 1;
                while (j1 >= j2) {
                    i1 = i;
                    while (i1 >= i2) {
                        if (used[i1][j1])
                            break;
                        used[i1][j1] = true;
                        --i1;
                    }
                    if (i1 == i)
                        break;
                    --j1;
                }
            }
        }
    }

    for (int i = 0; i < n2; ++i) {
        for (int j = 0; j < m2; ++j) {
            if (used[i][j])
                cout << s2[i][j];
            else
                cout << '.';
        }
        cout << endl;
    }
}

int32_t main()
{
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