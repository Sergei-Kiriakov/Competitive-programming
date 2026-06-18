//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;


const int mod = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int ans = 0;
    set<int> win, lose;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        if ((lose.size() > 0 and *lose.begin() < a[i]) || (win.empty() || *win.begin() > a[i]))
        {
            win.insert(a[i]);
        }
        else
        {
            lose.insert(a[i]);
        }
    }
    cout << lose.size() << endl;
}

int32_t main()
{
    //ofstream cout("sum.out");
    //ifstream cin("sum.in");
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed;
    cout.precision(15);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int tt = 1;
    cin >> tt;
    while(tt-->0)
    {
        solve();
    }
}


/*
*/