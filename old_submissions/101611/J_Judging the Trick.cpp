#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

//#define int long long
//#define double long double
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

constexpr int mod = 998244353;

double cross_prod(pair<double, double> &p1, pair<double, double> &p2)
{
    return p1.first * p2.second - p1.second * p2.first;
}

vector<double> make_line (pair<double, double> &a1, pair<double, double> &a2)
{
    vector<double> line(3);
    line[0] = a1.second - a2.second;
    line[1] = a2.first - a1.first;
    line[2] = a1.second * (a1.first - a2.first) - a1.first * (a1.second - a2.second);
    return line;
}

pair<double, double> inter_x (vector<double> &line, double x)
{
    pair<double, double> p = {x, 0};
    p.second = (-line[2] - line[0] * x) / line[1];
    return p;
}

pair<double, double> inter_y (vector<double> &line, double y)
{
    pair<double, double> p = {0, y};
    p.first = (-line[2] - line[1] * y) / line[0];
    return p;
}

double tri_square (pair<double, double> p1, pair<double, double> p2, pair<double, double> p3)
{
    pair<double, double> v1 = {p2.first - p1.first, p2.second - p1.second}, v2 = {p3.first - p1.first, p3.second - p1.second};
    double S = abs(cross_prod(v1, v2)) / 2.0;
    return S;
}

void solve()
{
    int n, w, h;
    cin >> n >> w >> h;
    vector<vector<double> > tri(n, vector<double> (7));
    for (int i = 0; i < n; ++i)
    {
        double x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        tri[i] = {x1, y1, x2, y2, x3, y3, tri_square({x1, y1}, {x2, y2}, {x3, y3})};
    }
    double x = w / 2., y = h / 2.;
    double lx = 0, rx = w, ly = 0, ry = h;
    bool free = false;
    for (int i1 = 0; i1 < 30; ++i1)
    {
        bool flag = true;
        // x / 2
        if (x == (int) x)
            x += 1e-9;
        vector<vector<double> > new_tri_right, new_tri_left;
        double left_s = 0, right_s = 0;
        for (int i = 0; i < tri.size(); ++i)
        {
            vector<pair<double, double> > left, right;
            for (int j = 0; j < 3; ++j)
            {
                if (tri[i][2 * j] < x)
                    left.emplace_back(tri[i][2 * j], tri[i][2 * j + 1]);
                else
                    right.emplace_back(tri[i][2 * j], tri[i][2 * j + 1]);
            }
            if (right.empty())
            {
                new_tri_left.push_back(tri[i]);
                left_s += tri[i][6];
                continue;
            }
            if (left.empty())
            {
                new_tri_right.push_back(tri[i]);
                right_s += tri[i][6];
                continue;
            }
            flag = false;
            pair<double, double> a1, a2, a3;
            if (left.size() == 1)
            {
                a1 = left[0];
                a2 = right[0];
                a3 = right[1];
            }
            else
            {
                a1 = right[0];
                a2 = left[0];
                a3 = left[1];
            }
            vector<double> line_a1_a2 = make_line(a1, a2), line_a1_a3 = make_line(a1, a3);
            pair<double, double> b1 = inter_x(line_a1_a2, x), b2 = inter_x(line_a1_a3, x);
            if (left.size() == 1)
            {
                new_tri_left.push_back({a1.first, a1.second, b1.first, b1.second, b2.first, b2.second, tri_square(a1, b1, b2)});
                left_s += tri_square(a1, b1, b2);
                new_tri_right.push_back({b1.first, b1.second, a2.first, a2.second, b2.first, b2.second, tri_square(b1, a2, b2)});
                right_s += tri_square(b1, a2, b2);
                new_tri_right.push_back({a2.first, a2.second, a3.first, a3.second, b2.first, b2.second, tri_square(a2, a3, b2)});
                right_s += tri_square(a2, a3, b2);
            }
            else
            {
                new_tri_right.push_back({a1.first, a1.second, b1.first, b1.second, b2.first, b2.second, tri_square(a1, b1, b2)});
                right_s += tri_square(a1, b1, b2);
                new_tri_left.push_back({b1.first, b1.second, a2.first, a2.second, b2.first, b2.second, tri_square(b1, a2, b2)});
                left_s += tri_square(b1, a2, b2);
                new_tri_left.push_back({a2.first, a2.second, a3.first, a3.second, b2.first, b2.second, tri_square(a2, a3, b2)});
                left_s += tri_square(a2, a3, b2);
            }
        }
        if (flag)
        {
            free = true;
            break;
        }
        if (right_s < left_s)
        {
            tri = new_tri_right;
            lx = x;
        }
        else
        {
            tri = new_tri_left;
            rx = x;
        }
        x = (lx + rx) / 2.;

        // y / 2
        if (y == (int) y)
            y += 1e-9;
        new_tri_right.clear();
        new_tri_left.clear();
        left_s = 0;
        right_s = 0;
        for (int i = 0; i < tri.size(); ++i)
        {
            vector<pair<double, double> > left, right;
            for (int j = 0; j < 3; ++j)
            {
                if (tri[i][2 * j + 1] < y)
                    left.emplace_back(tri[i][2 * j], tri[i][2 * j + 1]);
                else
                    right.emplace_back(tri[i][2 * j], tri[i][2 * j + 1]);
            }
            if (right.empty())
            {
                new_tri_left.push_back(tri[i]);
                left_s += tri[i][6];
                continue;
            }
            if (left.empty())
            {
                new_tri_right.push_back(tri[i]);
                right_s += tri[i][6];
                continue;
            }
            flag = false;
            pair<double, double> a1, a2, a3;
            if (left.size() == 1)
            {
                a1 = left[0];
                a2 = right[0];
                a3 = right[1];
            }
            else
            {
                a1 = right[0];
                a2 = left[0];
                a3 = left[1];
            }
            vector<double> line_a1_a2 = make_line(a1, a2), line_a1_a3 = make_line(a1, a3);
            pair<double, double> b1 = inter_y(line_a1_a2, y), b2 = inter_y(line_a1_a3, y);
            if (left.size() == 1)
            {
                new_tri_left.push_back({a1.first, a1.second, b1.first, b1.second, b2.first, b2.second, tri_square(a1, b1, b2)});
                left_s += tri_square(a1, b1, b2);
                new_tri_right.push_back({b1.first, b1.second, a2.first, a2.second, b2.first, b2.second, tri_square(b1, a2, b2)});
                right_s += tri_square(b1, a2, b2);
                new_tri_right.push_back({a2.first, a2.second, a3.first, a3.second, b2.first, b2.second, tri_square(a2, a3, b2)});
                right_s += tri_square(a2, a3, b2);
            }
            else
            {
                new_tri_right.push_back({a1.first, a1.second, b1.first, b1.second, b2.first, b2.second, tri_square(a1, b1, b2)});
                right_s += tri_square(a1, b1, b2);
                new_tri_left.push_back({b1.first, b1.second, a2.first, a2.second, b2.first, b2.second, tri_square(b1, a2, b2)});
                left_s += tri_square(b1, a2, b2);
                new_tri_left.push_back({a2.first, a2.second, a3.first, a3.second, b2.first, b2.second, tri_square(a2, a3, b2)});
                left_s += tri_square(a2, a3, b2);
            }
        }
        if (flag)
        {
            free = true;
            break;
        }
        if (right_s < left_s)
        {
            tri = new_tri_right;
            ly = y;
        }
        else
        {
            tri = new_tri_left;
            ry = y;
        }
        y = (ly + ry) / 2.;
    }
    cout << x << " " << y << endl;
}

int32_t main()
{
//    ofstream cout("sum.out");
//    ifstream cin("sum.in");
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed;
    cout.precision(9);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int tt = 1;
//    cin >> tt;
    while(tt-->0)
    {
        solve();
    }
}


/*
*/  