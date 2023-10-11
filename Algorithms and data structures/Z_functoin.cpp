vector<int> z_function (string s)
{
    int n = (int) s.size();
    vector<int> z(n);
    for (int I = 1, l = 0, r = 0; I < n; ++i)
    {
        if (I <= r)
            z[i] = min (r – I + 1, z[I – l]);
        while (I + z[i] < n && s[z[i]] == s[I + z[i]])
            ++z[i];
        if (I + z[i] – 1 > r)
        l = I,  r = I + z[i] – 1;
    }
    return z;
}
