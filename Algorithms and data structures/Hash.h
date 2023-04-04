class Hash
{
protected:
    pair<long long, long long> hash;
    constexpr static long long mod1 = 1e9 + 271, mod2 = 1e9 + 87, d = 179;
public:
    Hash ()
    {
        hash.first = 0;
        hash.second = 0;
    }
    Hash (int h)
    {
        hash.first = (h + mod1 * mod1) % mod1;
        hash.second = (h + mod2 * mod2) % mod2;
    }
    Hash (int h1, int h2)
    {
        hash.first = (h1 + mod1 * mod1) % mod1;
        hash.second = (h2 + mod2 * mod2) % mod2;
    }
    Hash (string s)
    {
        int n = s.size();
        hash.first = 0;
        hash.second = 0;
        for (int i = 0; i < n; ++i)
        {
            hash += s[i];
        }
    }

    Hash operator+(char s)
    {
        return Hash((hash.first * d + s) % mod1, (hash.second * d + s) % mod2);
    }
    Hash operator+(int a)
    {
        return Hash((hash.first * d + a) % mod1, (hash.second * d + a) % mod2);
    }
    Hash operator+(Hash h)
    {
        return Hash((hash.first + h.first) % mod1, (hash.second + h.second) % mod2);
    }
    bool operator==(Hash h)
    {
        return h.first == hash.first && h.second == hash.second;
    }
    bool operator<(Hash h)
    {
        return h.first < hash.first || (h.first == hash.first && h.second < hash.second);
    } 
};