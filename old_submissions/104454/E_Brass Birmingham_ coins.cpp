#pragma GCC optimize("Ofast,fast-math,unroll-loops")
#pragma GCC target("avx2,bmi2")
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

    vector<vector<long>> tw(4);

    for (int i = 0; i < 4; i++)
    {
        long sz;
        cin >> sz;

        tw[i].resize(sz);
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < tw[i].size(); j++)
        {
            cin >> tw[i][j];
        }
    }

    char dp[31][31][31][31];

    for (char i = 0; i < 31; i++)
        for (char j = 0; j < 31; j++)
            for (char k = 0; k < 31; k++)
                for (char m = 0; m < 31; m++)
                    dp[i][j][k][m] = 121;

    dp[tw[0].size()][tw[1].size()][tw[2].size()][tw[3].size()] = 0;

    queue<pair<pair<char, char>, pair<char, char>>> q;

    q.push({ {tw[0].size(), tw[1].size()}, { tw[2].size(), tw[3].size() } });

    while (q.size() > 0)
    {
        auto up = q.front();
        q.pop();

        for (int i = 1; i <= n; i++)
        {
            vector<char> arr = { up.first.first, up.first.second, up.second.first, up.second.second };

            for (int j = 0; j < 4; j++)
            {
                long cur = arr[j];

                while (cur != 0 && tw[j][cur - 1] == i)
                {
                    arr[j] -= 1;
                    cur -= 1;
                }
            }

            if (dp[arr[0]][arr[1]][arr[2]][arr[3]] == 121)
            {
                q.push({ {arr[0], arr[1]}, {arr[2], arr[3]} });
                dp[arr[0]][arr[1]][arr[2]][arr[3]] = dp[up.first.first][up.first.second][up.second.first][up.second.second] + 1;
            }
        }
    }

    cout << (int)dp[0][0][0][0];
}