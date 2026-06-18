#include <functional>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>
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
#include <random>
#include <chrono>
#include <cassert>
#include <memory>

using namespace std;

#define int long long

const int MOD = 1e9 + 7;

vector<int> solve (int n, int m, int k, vector<string> g, vector<int> qx, vector<int> qy) {
    vector<vector<int> > comp(n, vector<int>(m, -1));
    vector<int> cnt;
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (g[i][j] == '.' && comp[i][j] == -1) {
                int id = cnt.size();
                int paint = 0;
                queue<pair<int, int> > q;
                q.push({i, j});
                comp[i][j] = id;
                while (!q.empty()) {
                    auto [x, y] = q.front();
                    q.pop();
                    for (int d = 0; d < 4; ++d) {
                        int nx = x + dx[d], ny = y + dy[d];
                        if (g[nx][ny] == '*') {
                            ++paint;
                        }
                        else if (comp[nx][ny] == -1) {
                            comp[nx][ny] = id;
                            q.push({nx, ny});
                        }
                    }
                }
                cnt.push_back(paint);
            }
        }
    }
    vector<int> ans(k);
    for (int i = 0; i < k; ++i) {
        ans[i] = cnt[comp[qx[i] - 1][qy[i] - 1]];
    }
    return ans;
}

void input() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> g(n);
    for (int i = 0; i < n; ++i) {
        cin >> g[i];
    }
    vector<int> qx(k), qy(k);
    for (int i = 0; i < k; ++i) {
        cin >> qx[i] >> qy[i];
    }
    auto ans = solve(n, m, k, g, qx, qy);
    for (auto el : ans) {
        cout << el << endl;
    }
}

int32_t main()
{
    int tt = 1;
    // cin >> tt;

    while (tt-->0)
    {
        input();
    }
}
