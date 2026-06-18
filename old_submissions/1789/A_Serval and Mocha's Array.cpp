#include <bits/stdc++.h>

#define int long long
#define endl "\n"
#define double long double

using namespace std;

constexpr int MAXN = 1e6 + 6, mod = 1e9 + 7, d = 179;

int gcd (int a, int b) 
{
	while (b) {
		a %= b;
		swap (a, b);
	}
	return a;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    int min1 = 1e9;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            min1 = min(gcd(a[i], a[j]), min1);
        }
    }
    if (min1 <= 2)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cerr.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solve();
    }
}

/*
...
*/