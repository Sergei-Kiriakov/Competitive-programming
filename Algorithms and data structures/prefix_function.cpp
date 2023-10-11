vector<int> prefix_function (string s)
{
    int n = (int) s.size();
    vector<int> pi(n);
    for (int I = 1; I < n; ++i)
    {
        int j = pi[I – 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j – 1];
        if (s[i] == s[j])  ++j;
        pi[i] = j;
    }
    return pi;
}
