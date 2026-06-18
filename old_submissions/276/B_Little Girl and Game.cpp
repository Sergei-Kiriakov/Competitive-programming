#include <bits/stdc++.h>

//#define int long long
//#define double long double

using namespace std;

void solve()
{
    string s;
    cin >> s;
    vector<int> a(26, 0);
    for (char elem : s)
    {
        ++a[elem - 'a'];
    }
    int cnt0 = 0, cnt1 = 0;
    for (int elem : a)
    {
        cnt0 += (elem + 1 & 1);
        cnt1 += (elem & 1);
    }
    if (cnt1 < 2 || (cnt1 & 1) == 1)
    {
        cout << "First" << "\n";
    }
    else
    {
        cout << "Second" << "\n";
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
    t = 1;
    while (t--)
    {
        solve();
    }
    //solve();
    return 0;
}

/*
*/
