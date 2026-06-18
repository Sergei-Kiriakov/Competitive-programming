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
    string s;
    cin >> s;
    int n = s.size();
    int bal = 0;
    bool flag = true;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[' || s[i] == '<')
            ++bal;
        else
            --bal;
        if (bal < 0)
            flag = false;
    }
    if (!flag || bal != 0)
    {
        cout << "Impossible" << endl;
        return 0;
    }
    int ans = 0;
    vi st = {};
    map<char, char> m;
    m['['] = ']';
    m['{'] = '}';
    m['<'] = '>';
    m['('] = ')';
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[' || s[i] == '<')
        {
            st.push_back(s[i]);
        }
        else
        {
            if (m[st.back()] != s[i])
                ++ans;
            st.pop_back();
        }
    }
    cout << ans << endl;
}

/*
*/
