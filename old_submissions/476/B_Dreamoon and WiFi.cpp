#include <bits/stdc++.h>
#define int long long
#define double long double

typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
typedef std::vector<vvi> vvvi;
typedef std::vector<vvvi> vvvvi;
typedef std::vector<std::string> vs;
typedef std::vector<bool> vb;
typedef std::vector<vb> vvb;
typedef std::vector<double> vd;
typedef std::vector<vd> vvd;
typedef std::pair<int, int> pii;
typedef std::vector<pii> vpii;
typedef std::vector<vpii> vvpii;
using ull = unsigned long long;

using namespace std;

const int mod = 1e9 + 7, MAXN = 1e6 + 6;
vector<bool> primes;

int get_fac(int n)
{
    int ans = 1;
    for (int i = 1; i < n + 1; ++i)
    {
        ans *= i;
    }
    return ans;
}

void solve()
{
    string s1, s2;
    cin >> s1 >> s2;
    int bal_1 = 0, bal_2 = 0;
    int cnt_q = 0;
    int n = s1.size();
    for (int i = 0; i < n; ++i)
    {
        if (s1[i] == '+')
        {
            ++bal_1;
        }
        else
        {
            --bal_1;
        }
        if (s2[i] == '+')
        {
            ++bal_2;
        }
        else if (s2[i] == '-')
        {
            --bal_2;
        }
        else
        {
            ++cnt_q;
        }
    }
    int dif = abs(bal_1 - bal_2);
    if (dif > cnt_q || abs(dif - cnt_q) % 2 == 1)
    {
        cout << 0 << "\n";
    }
    else
    {
        int pow_2 = 1;
        for (int i = 0; i < cnt_q; ++i)
        {
            pow_2 <<= 1;
        }
        double fac_top = get_fac(cnt_q);
        double fac_bot1 = get_fac((cnt_q - dif) / 2), fac_bot2 = get_fac(cnt_q - (cnt_q - dif) / 2);
        //cerr << fac_top << " " << fac_bot1 << " " << fac_bot2 << " " << pow_2 << "\n";
        double ans = fac_top / (fac_bot1 * fac_bot2 * pow_2);
        cout << setprecision(9) << ans << "\n";
    }
}

int32_t main()
{
    //ofstream cout("test.txt");
    //ifstream cin("joseph.in");
    //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cerr.tie(0);
    solve();
}
