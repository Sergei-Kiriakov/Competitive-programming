#include <functional>
#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <string>
#include <map>
#include <list>
#include <math.h>
#include <cstdlib>
#include <fstream>
#include <queue>
#include <set>
#include <vector>
#include <stack>
#include <bitset>

using namespace std;

#define long long long
#define MOD 1000000007ll

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(false);
    long n, m;
    cin >> n >> m;

    vector<long> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a.begin(), a.end());

    long ans = 0;
    long l = 0, r = n - 1;

    bool used = false;

    while (l <= r)
    {
        if (l == r)
        {
            if (l != 0 && a[l] + a[l - 1] <= m && !used)
                ans += a[r];
            else ans += a[r] + 1;

            r -= 1;
        }
        else
        {
            if (a[l] + a[r] <= m)
            {
                if (l == 0 || used)
                    ans += a[l] + a[r] + 1;
                else ans += a[l] + a[r];

                used = false;
                l += 1;
                r -= 1;
            }
            else
            {
                if (a[l] + a[r] <= m && !used)
                {
                    used = true;
                    ans += a[r];
                }
                else ans += a[r] + 1;

                r -= 1;
            }
        }
    }

    cout << ans << '\n';

}