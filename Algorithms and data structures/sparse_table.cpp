template<typename T = int>
class SparceTable
{
public:
    vector<vector<T> > tr;
    int n;

    // на минимумах
    SparceTable () {}
    SparceTable (vector<T> a)
    {
        n = a.size();
        tr = vector<vector<T> > (35, vector<T> (n));
        for (int i = 0; i < n; ++i) tr[0][i] = a[i];
        for (int j = 1; j <= __lg(n); j++)
        {
            tr[j].resize(n);
            for (int i = 0; i <= n - (1 << j); i++)
                tr[j][i] = min(tr[j - 1][i + (1 << (j - 1))], tr[j - 1][i]);
        }
    }
    // 0 индексация
    T get (int l, int r)
    {
        return min(tr[__lg(r - l + 1)][l], tr[__lg(r - l + 1)][r - (1 << (__lg(r - l + 1))) + 1]);
    }
};
