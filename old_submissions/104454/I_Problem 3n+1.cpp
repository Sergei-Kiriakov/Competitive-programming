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

long t(long n)
{
    long cnt = 0;

    while (n != 1)
    {
        if (n % 2 == 0)
        {
            n /= 2;
        }
        else
        {
            n = n * 3 + 1;
        }

        cnt += 1;
    }

    return cnt;
}

int32_t main()
{
    cin.tie(0);
    cin.sync_with_stdio(false);

    long s, w;
    cin >> s >> w;

    vector<pair<long, pair<long, long>>> arr;

    long nmax = 0;

    for (long i = s; i < s + w; i++)
    {
        long sz = t(i);

        if (arr.size() == 0)
        {
            arr.push_back({ sz, {1, i} });
        }
        else
        {
            if (arr.back().first == sz)
            {
                arr.back().second.first += 1;
            }
            else
            {
                arr.push_back({ sz, {1, i} });
            }
        }
    }

    long pupa = -1;

    for (long i = 0; i < arr.size(); i++)
    {
        if (nmax < arr[i].second.first)
        {
            nmax = arr[i].second.first;
            pupa = arr[i].second.second;
        }
    }

    cout << nmax << ' ' << pupa;
}