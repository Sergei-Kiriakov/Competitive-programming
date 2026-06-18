#include <bits/stdc++.h>
#define int long long

using namespace std;

#define watch(x) cerr << setw(14) << #x << " = " << setw(14) << (x) << "\n"

constexpr int mod = 1e9 + 7;

vector<vector<int> > prod(vector<vector<int> > a, vector<vector<int> > b)
{
    int n = b.size();
    vector<vector<int> > ans(n, vector<int> (n, 0));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            for (int k = 0; k < n; ++k)
            {
                ans[i][j] = (ans[i][j] + a[i][k] * b[k][j]) % mod;
            }
        }
    }
    return ans;
}

vector<vector<int> > bin_pow(vector<vector<int> > mat, int n)
{
    int n1 = mat.size();
    vector<vector<int> > ans(n1, vector<int> (n1, 0));
    for (int i = 0; i < n1; ++i)
    {
        ans[i][i] = 1;
    }
    while (n)
    {
        if (n & 1)
            ans = prod(ans, mat);
        mat = prod(mat, mat);
        n >>= 1;
    }
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cerr.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<vector<int> > mat(n, vector<int> (n, 0));
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int sum = 0;
            int d = a[i] ^ a[j];
            int cnt = 0;
            while (d)
            {
                cnt += (d & 1);
                d >>= 1;
            }
            if (cnt % 3 == 0)
                mat[i][j] = 1;
        }
    }
    vector<vector<int> > abc = bin_pow(mat, k - 1);
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            sum = (sum + abc[i][j]) % mod;
        }
    }
    cout << sum << "\n";
    //watch(sum);
}
