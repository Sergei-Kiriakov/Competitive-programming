vector<int> z_function (string s)
{
    int n = (int) s.size();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i)
    {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (I + z[i] < n && s[z[i]] == s[I + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
        l = I,  r = i + z[i] - 1;
    }
    return z;
}
