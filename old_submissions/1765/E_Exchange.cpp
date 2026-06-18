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
        long n, a, b;
        cin >> n >> a >> b;

        if (b >= a)
        {
            cout << (n / a + (n % a > 0)) << '\n';
        }
        else
        {
            cout << "1\n";
        }
    }
}