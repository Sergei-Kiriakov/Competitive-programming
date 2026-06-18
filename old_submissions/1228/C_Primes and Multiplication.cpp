#include <bits/stdc++.h>
#define int long long

using namespace std;

const int mod = 1e9 + 7;

vector<int> prime(int x)
{
    int d = 2;
    vector<int> ans;
    while (d * d <= x)
    {
        if (x % d == 0)
        {
            ans.push_back(d);
            while (x % d == 0)
            {
                x /= d;
            }
        }
        d++;
    }
    if (x > 1)
        ans.push_back(x);
    return ans;
}

int binpow (int a, int n) {
	int res = 1;
	while (n)
		if (n & 1) {
			res = (res * a) % mod;
			--n;
		}
		else {
			a = (a * a) % mod;
			n >>= 1;
		}
	return res;
}


int32_t main() {
    int x, n, ans = 1;
    cin >> x >> n;
    vector<int> a = prime(x);
    for (int i = 0; i < a.size(); ++i)
    {
        int d = a[i], count1 = 1, fac = n / d;
        while (fac > 0)
        {
            ans = (ans * binpow(d, fac)) % mod;
            fac /= d;
        }
    }
    cout << ans << endl;
}
