constexpr int mod1 = 1e9 + 7, mod2 = 1e9 + 93;

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
    {return Hash((h1 – h.h1 + mod1) % mod1, (h2 – h.h2 + mod2) % mod2); }
    Hash operator* (Hash h)
    {return Hash((h1 * h.h1) % mod1, (h2 * h.h2) % mod2); }
    bool operator== (Hash h) {return h1 == h.h1 and h2 == h.h2; }
};
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
        d = Hash(179, 179);
        n = s.size();
        p = vector<Hash> (n + 1, 1);
        for (int I = 1; I <= n; ++i) p[i] = p[I – 1] * d;
        h = vector<Hash> (n, 0);
        h[0] = s[0]; //(s[0] – ‘a’ + 1);
        for (int I = 1; I < n; ++i) h[i] = h[I – 1] * d + s[i];
    }
    // 0 индексация
    Hash hash_substring(int l, int r)
    {
        if (l == 0)
            return h[r];
        return h[r] – h[l – 1] * p[r – l + 1];
    }
};
