#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()


using namespace std;

const int mod = 1e9 + 7;

int string_to_int(string s)
{
    int ans = 0;
    int n = s.size();
    for (int i = 0; i < n; ++i)
    {
        ans *= 10;
        ans += s[i] - '0';
    }
    return ans;
}

int f()
{
    string tr;
    cin >> tr;
    int a1 = 0;
    if (tr == "AD")
    {
        int n;
        cin >> n;
        a1 = n - 1;
    }
    else if (tr == "BC")
    {
        int n;
        cin >> n;
        a1 = -n;
    }
    else
    {
        string s;
        cin >> s;
        if (s == "AD")
        {
            a1 = string_to_int(tr) - 1;
        }
        else
        {
            a1 = -string_to_int(tr);
        }
    }
    return a1;
}

void solve()
{
    int a1 = f(), a2 = f();
    cout << abs(a1 - a2) << endl;
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
    //cin >> tt;
    while(tt-->0)
    {
        solve();
    }
}


/*
*/