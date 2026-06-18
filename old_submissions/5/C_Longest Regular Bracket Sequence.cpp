#include <bits/stdc++.h>

#define Please return
#define Accepted 0
#define int long long
#define endl "\n"
#define double long double

using namespace std;

constexpr int MAXN = 1e6 + 6, mod = 1e8;

void solve ()
{
    string s;
    cin >> s;
    int ans = 0, cnt = 1;
    vector<int> st = {1};
    int n = s.size();
    int now = 0;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == '(')
        {
            st.push_back(1);
        }
        else
        {
            if (st.size() > 1)
            {
                int now = st.back();
                st.pop_back();
                st.back() += now;
                now = st.back() - 1;
                if (now > ans)
                {
                    ans = now;
                    cnt = 1;
                }
                else if (ans == now)
                {
                    ++cnt;
                }
            }
            else
            {
                st.back() = 1;
            }
        }
    }
    if (ans == 0)
    {
        cout << 0 << " " << 1 << endl;
        return;
    }
    cout << ans * 2 << " " << cnt << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cerr.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int tt = 1;
    // cin >> tt;
    while (tt--)
    {
        solve();
    }
}

/*
No brain
*/
