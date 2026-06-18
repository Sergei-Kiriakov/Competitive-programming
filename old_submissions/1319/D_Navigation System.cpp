#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main()
{
    int n, m;
    cin >> n >> m;
    vector<int> c(n, 1e9);
    vector<vector<int> > a(n), b(n);
    for (int i = 0; i < m; ++i)
    {
        int v, w;
        cin >> v >> w;
        --v;
        --w;
        a[v].push_back(w);
        b[w].push_back(v);
    }
    int k;
    cin >> k;
    vector<int> p(k);
    for (int i = 0; i < k; ++i)
    {
        cin >> p[i];
        --p[i];
    }
    int fp = 0;
    vector<int> st;
    st.push_back(p[k - 1]);
    c[p[k - 1]] = 0;
    while (fp != st.size())
    {
        int v = st[fp];
        ++fp;
        for (int i = 0; i < b[v].size(); ++i)
        {
            int w = b[v][i];
            if (c[v] + 1 < c[w])
            {
                st.push_back(w);
                c[w] = c[v] + 1;
            }
        }
    }
    int count1 = 0, count2 = 0;
    for (int i = 0; i < k - 1; ++i)
    {
        int min1 = 1e10;
        int count_min = 0;
        int v = p[i];
        for (int j = 0; j < a[v].size(); ++j)
        {
            int w = a[v][j];
            if (min1 > c[w])
            {
                min1 = c[w];
                count_min = 1;
            }
            else if (min1 == c[w])
            {
                ++count_min;
            }
        }
        if (c[p[i + 1]] == min1)
        {
            if (count_min != 1)
            {
                ++count2;
            }
        }
        else
        {
            ++count1;
            ++count2;
        }
    }
    cout << count1 << " " << count2 << endl;
}
