#include <bits/stdc++.h>

#define int long long int

using namespace std;

const int N = 1e7;

vector<bool> sieve(int n)
{
    vector<bool> prime (N+1, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i * i <= n; ++i)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                prime[j] = false;
            }
        }
    }
    return prime;
}

int32_t main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    vector<bool> prime = sieve(N);
    vector<int> mindiv(N + 1, 1);
    vector<pair<int, int> > ans(n);
    for (int i = 2; i <= N; ++i)
    {
        if (prime[i])
        {
            for (int j = i; j <= N; j += i)
            {
                mindiv[j] = i;
            }
        }
    }
    for (int i = 0; i < n; ++i)
    {
        int cnt = 0;
        int last = 0;
        int ans1 = 1, ans2 = 1;
        while (a[i] > 1)
        {
            if (mindiv[a[i]] != last)
            {
                ++cnt;
                last = mindiv[a[i]];
                if (cnt == 1)
                {
                    ans1 *= mindiv[a[i]];
                }
                else
                {
                    ans2 *= mindiv[a[i]];
                }
            }
            a[i] /= mindiv[a[i]];
        }
        if (cnt == 1)
        {
            ans[i] = {-1, -1};
        }
        else
        {
            ans[i] = {ans1, ans2};
        }
    }
    for (int i = 0; i < n; ++i)
    {
        cout << ans[i].first << " ";
    }
    cout << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << ans[i].second <<  " ";
    }
    cout << endl;
}

/*
*/