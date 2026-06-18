#include <bits/stdc++.h>
#define int int64_t
#define double long double

typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
typedef std::vector<vvi> vvvi;
typedef std::vector<std::string> vs;
typedef std::vector<bool> vb;
typedef std::vector<vb> vvb;
typedef std::vector<double> vd;
typedef std::vector<vd> vvd;
typedef std::pair<int, int> pii;
typedef std::vector<pii> vpii;
typedef std::vector<vpii> vvpii;

using namespace std;

constexpr int mod = 1e9 + 7, p = 179, MAXN = 1000000;

int32_t main()
{
    //ofstream cout("cutting.out");
    //ifstream cin("cutting.in");
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cerr.tie(0);
    string s;
    cin >> s;
    string s1 = "abc";
    string ans = "";
    ans += s[0];
    int n = s.size();
    for (int i = 1; i < n; ++i)
    {
        if (s[i] == ans[i - 1])
        {
            int j = 0;
            for (; s1[j] == s[i] || (i + 1 < n && s1[j] == s[i + 1]); ++j);
            ans += s1[j];
        }
        else
        {
            ans += s[i];
        }
    }
    cout << ans << "\n";
}

/*
5
1 2 3 4 5
1 3
2 3
*/
