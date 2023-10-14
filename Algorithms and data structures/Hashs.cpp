constexpr int mod1 = 1e9 + 7, mod2 = 1e9 + 9;

class Hash
{
public:
    int h1, h2;
    Hash (int h1_, int h2_) {h1 = h1_; h2 = h2_; };
    Hash (int a) {h1 = a % mod1; h2 = a % mod2; };
    Hash () {h1 = 0; h2 = 0; };

    Hash operator+ (Hash h)
    {return Hash((h1 + h.h1) % mod1, (h2 + h.h2) % mod2); }
    Hash operator- (Hash h)
    {return Hash((h1 - h.h1 + mod1) % mod1, (h2 - h.h2 + mod2) % mod2); }
    Hash operator* (Hash h)
    {return Hash((h1 * h.h1) % mod1, (h2 * h.h2) % mod2); }
    bool operator== (Hash h) {return h1 == h.h1 and h2 == h.h2; }
    bool operator< (Hash h) {return h1 * h2 < h.h1 * h.h2; }

    friend Hash operator/ (Hash a, Hash b);
};

int bin_pow (int a, int n, int mod)
{
    int ans = 1;
    while (n)
    {
        if (n & 1)
            ans = ans * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return ans;
}

Hash inverse_mod(Hash a)
{
    int a1 = bin_pow(a.h1, mod1 - 2, mod1);
    int a2 = bin_pow(a.h2, mod2 - 2, mod2);
    return Hash(a1, a2);
}

Hash operator/ (Hash a, Hash b)
{
    return a * inverse_mod(b);
}

class PolyHash
{
public:
    // Важно! Для дебага удобно использовать d = 10 и s[i] = s[i] – ‘a’ + 1, на маленьком алфавите
    vector<Hash> h;
    vector<Hash> p;
    int n;
    Hash d;

    PolyHash (string s)
    {
//        for (int i = 0; i < s.size(); ++i)
//            s[i] = s[i] - 'a' + 1;
        d = Hash(179, 179);
        n = s.size();
        p = vector<Hash> (n + 1, 1);
        for (int i = 1; i <= n; ++i) p[i] = p[i - 1] * d;
        h = vector<Hash> (n, 0);
        h[0] = s[0];
        for (int i = 1; i < n; ++i) h[i] = h[i - 1] * d + s[i];
    }
    // 0 индексация
    Hash hash_substring (int l, int r)
    {
        if (l == 0)
            return h[r];
        return h[r] - h[l - 1] * p[r - l + 1];
    }
    Hash del_ind (int ind)
    {
        if (ind == 0)
            return (h.back() - h[0] * p[n - 1]);
        return (h.back() - h[ind] * p[n - 1 - ind]) + h[ind - 1] * p[n - 1 - ind];
    }
};