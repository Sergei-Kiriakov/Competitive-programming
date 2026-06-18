#include <bits/stdc++.h>

#define int long long

using namespace std;

int cut(vector<vector<int> > &pr_mat, int x1, int y1, int x2, int y2)
{
    return pr_mat[x2][y2] - pr_mat[x1 - 1][y2] - pr_mat[x2][y1 - 1] + pr_mat[x1 - 1][y1 - 1];
}

int f(vector<vector<int> > &pr_mat, int i, int j)
{
    int n = pr_mat.size() - 1;
    return cut(pr_mat, 1, i + 1, i, j + 1) + cut(pr_mat, j + 2, i + 1, n, j + 1);
}


void get_ans (vector<int> &ans, int l, int r, vector<vector<int> > &pred, int p=0)
{
    if (l > r)
        return;
    int k = pred[l][r];
    ans[k] = p;
    if (l == r)
        return;
    get_ans(ans, l, k - 1, pred, k + 1);
    get_ans(ans, k + 1, r, pred, k + 1);
}

void solve ()
{
    int n;
    cin >> n;
    vector<vector<int> > c(n, vector<int> (n, 0));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> c[i][j];
        }
    }
    vector<vector<int> > pr_mat(n + 1, vector<int> (n + 1, 0));
    for (int i = 1; i < n + 1; ++i)
    {
        for (int j = 1; j < n + 1; ++j)
        {
            pr_mat[i][j] = c[i - 1][j - 1] + pr_mat[i][j - 1] + pr_mat[i - 1][j] - pr_mat[i - 1][j - 1];
        }
    }
    vector<vector<int> > dp(n, vector<int> (n, 1e18)), pred(n, vector<int> (n, -1));
    for (int i = 0; i < n; ++i)
    {
        dp[i][i] = 0;
        pred[i][i] = i;
    } 
    for (int len = 1; len < n; ++len)
    {
        for (int i = 0; i + len < n; ++i)
        {
            int j = i + len;
            for (int k = i; k <= j; ++k)
            {
                int cnt = 0;
                if (i != k)
                {
                    cnt += f(pr_mat, i, k - 1) + dp[i][k - 1]; 
                }
                if (j != k)
                {
                    cnt += f(pr_mat, k + 1, j) + dp[k + 1][j];
                }
                if (cnt < dp[i][j])
                {
                    dp[i][j] = cnt;
                    pred[i][j] = k;
                }
            }
        }
    }
    vector<int> ans(n, -1);
    get_ans(ans, 0, n - 1, pred);
    for (int i = 0; i < n; ++i)
    {
        cout << ans[i] << " ";
    }
    cout << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cerr.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int tt;
    // cin >> tt;
    tt = 1;
    while (tt--)
    {
        solve();
    }  
}

/*
*/