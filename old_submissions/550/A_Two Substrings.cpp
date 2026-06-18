#include <bits/stdc++.h>
#define int int64_t

typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
typedef std::pair<int, int> pii;

using namespace std;

const int MAXN = 1e5 + 5;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cerr.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    bool ans1 = false, ans2 = false;
    for (int i = 1; i < n; ++i)
    {
        if (s[i] == 'A' && s[i - 1] == 'B')
        {
            ans1 = true;
            i += 2;
        }
        if (ans1 && s[i] == 'B' && s[i - 1] == 'A')
        {
            ans2 = true;
        }
    }
    bool ans3 = false, ans4 = false;
    for (int i = 1; i < n; ++i)
    {
        if (s[i] == 'B' && s[i - 1] == 'A')
        {
            ans3 = true;
            i += 2;
        }
        if (ans3 && s[i] == 'A' && s[i - 1] == 'B')
        {
            ans4 = true;
        }
    }
    if ((ans1 && ans2) || (ans3 && ans4))
    {
        cout << "YES" << "\n";
    }
    else
    {
        cout << "NO" << "\n";
    }
}
