#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for(int j = 0; j < t; ++j)
    {
        string s;
        cin >> s;
        vector<char> a;
        a.push_back(s[0]);
        for (int i = 0; i < s.size(); i += 2)
        {
            a.push_back(s[i + 1]);
        }
        for (int i = 0; i < a.size(); ++i)
        {
            cout << a[i];
        }
        cout << "\n";
    }
}
