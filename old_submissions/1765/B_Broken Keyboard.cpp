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

    long t;
    cin >> t;

    for (int t1 = 0; t1 < t; t1++)
    {
        long n;
        cin >> n;

        string s;
        cin >> s;

        long c = 0;
        bool yes = true;

        for (int i = 0; i < n; i++)
        {
            if (c == 0)
            {
                c = (c + 1) % 2;
                continue;
            }
            else
            {
                if(i + 1 == n || s[i] != s[i + 1])
                {
                    yes = false;
                }

                c = (c + 1) % 2;
                i += 1;
            }
        }

        if (yes)
            cout << "YES\n";
        else cout << "NO\n";
    }
}