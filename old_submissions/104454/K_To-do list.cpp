#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>
#include <bitset>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <numeric>
#include <iterator>
#include <math.h>
#include <set>
#include <functional>
#include <fstream>
#include <chrono>
#include <random>
#include <assert.h>

using namespace std;
#define MOD 998244353
#define eps 0.000001

int32_t main()
{
    cin.tie(0);
    cin.sync_with_stdio(false);

    long n, k;
    cin >> n >> k;

    vector<long> a(1e5 + 2);

    for (int i = 0; i < n; i++)
    {
        long nm;
        cin >> nm;

        a[nm + 1] += 1;
    }

    for (int i = 1; i <= k; i++)
    {
        vector<long> divs;

        for (int j = 1; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                if (j * j == i)
                {
                    divs.push_back(j);
                }
                else
                {
                    divs.push_back(i / j);
                    divs.push_back(j);
                }
            }
        }

        long ans = 0;

        for (auto& el : divs)
        {
            ans += a[el];
        }

        cout << ans << ' ';
    }
}