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
#define long long long
#define MOD 998244353
#define eps 0.000001

int32_t main()
{
    cin.tie(0);
    cin.sync_with_stdio(false);

    long n;
    cin >> n;

    vector<long> dels;
    multiset<long> cnts;

    for (int i = 2; i <= 1e8; i++)
    {
        while (n % i == 0)
        {
            cnts.insert(i);
            n /= i;
        }
    }

    if (n != 1)
        cnts.insert(n);

    if (cnts.size() == 6)
    {
        for (auto& el : cnts)
        {
            if (cnts.count(el) > 1)
            {
                cout << "-1";
                exit(0);
            }
        }

        for (auto& el : cnts)
        {
            cout << el << ' ';
        }
    }
    else cout << "-1";
}