#include <bits/stdc++.h>
#define int long long
#define double long double

using vi = std::vector<int>;
using vvi = std::vector<vi>;
using vvvi = std::vector<vvi>;
using vvvvi = std::vector<vvvi>;
using vb = std::vector<bool>;
using vvb = std::vector<vb>;
using pii = std::pair<int, int>;
using vpii = std::vector<pii>;
using vvpii = std::vector<vpii>;
using mii = std::map<int, int>;
using ull = unsigned long long;
using vs = std::vector<std::string>;

using namespace std;

constexpr int MOD = 1e9 + 7, P = 179, maxn = 300 + 3;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cerr.tie(0);
    int n, p, q;
    cin >> n >> p >> q;
    string s;
    cin >> s;
    for (int i = 0; i <= n; ++i)
    {
        if (i * p <= n && (n - p * i) % q == 0)
        {
            //cerr << i << " " << " " << "---" << endl;
            int ans = (n - p * i) / q;
            cout << i + ans << endl;
            for (int k = 0; k < i; ++k)
            {
                for (int j = 0; j < p; ++j)
                {
                    cout << s[j + k * p];
                }
                cout << endl;
            }
            for (int k = 0; k < ans; ++k)
            {
                for (int j = 0; j < q; ++j)
                {
                    cout << s[j + k * q + i * p];
                }
                cout << endl;
            }
            return 0;
        }
    }
    cout << -1 << endl;
}

/*
*/
