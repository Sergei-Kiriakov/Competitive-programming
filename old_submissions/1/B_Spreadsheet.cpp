#include <bits/stdc++.h>
#define int long long
#define double long double

typedef std::vector<int> vi;

using namespace std;

constexpr int mod = 1e9 + 7, p = 179;

int get_numb(int &i, string s)
{
    int n = s.size();
    int ans = 0;
    while (i < n && s[i] >= '0' && s[i] <= '9')
    {
        ans *= 10;
        ans += s[i] - '0';
        ++i;
    }
    return ans;
}

void solve()
{
    string s;
    cin >> s;
    int i = 1;
    string ans;
    int n = s.size();
    if (s[0] == 'R' && get_numb(i, s) && i < n && s[i] == 'C')
    {
        i = 1;
        int r = get_numb(i, s);
        ++i;
        int c = get_numb(i, s);
        //cerr << r << " " << c << endl;
        while (c != 0)
        {
            --c;
            ans.push_back(c % 26 + 'A');
            c /= 26;
        }
        reverse(ans.begin(), ans.end());
        cout << ans << r << endl;
        //cerr << -1;
    }
    else
    {
        i = 0;
        int c = 0;
        while(i < n && s[i] >= 'A' && s[i] <= 'Z')
        {
            c *= 26;
            c += (s[i] - 'A' + 1);
            ++i;
        }
        int r = 0;
        while (i < n)
        {
            r *= 10;
            r += (s[i] - '0');
            ++i;
        }
        cout << "R" << r << "C" << c << endl;
    }
}

int32_t main()
{
    //ofstream cout("test.txt");
    //ifstream cin("joseph.in");
    //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cerr.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    //solve();
    return 0;
}
/*
1
R228C494

RZ228
*/
