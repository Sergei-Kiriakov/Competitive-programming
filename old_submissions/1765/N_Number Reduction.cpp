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
        string s;
        cin >> s;
        
        long k;
        cin >> k;

        long left = -1;
        string ans = "";

        vector<vector<int>> ind(10);

        for (int i = 0; i < s.size(); i++)
        {
            ind[s[i] - '0'].push_back(i);
        }

        for (int i = 0; i < 10; i++)
        {
            reverse(ind[i].begin(), ind[i].end());
        }

        for (int i = s.size() - k; i > 0; i--)
        {
            for (int c = (i == s.size() - k? 1 : 0); c <= 9; c++)
            {
                if (ind[c].size() == 0)
                    continue;

                while (ind[c].size() > 0 && ind[c].back() <= left)
                    ind[c].pop_back();

                if (ind[c].size() > 0 && s.size() - ind[c].back() >= i)
                {
                    left = ind[c].back();
                    ans.push_back(c + '0');
                    c = 10;
                }
            }
        }

        cout << ans << '\n';
    }

}