#include <iostream>
#include <vector>
#include <string>
#include <cassert>

using namespace std;
using vii = vector<vector<int>>;

int cells_left;
int n;

void examine(vii &field, int x_, int y_)
{
    int x = x_;
    int y = y_;

    while (x >= 0 && y >= 0 && field[x][y] >= 0)
    {
        if (field[x][y] == 0)
        {
            cout << x + 1 << " " << y + 1 << endl;
            string ans;
            cin >> ans;
            if (ans == "miss")
            {
                field[x][y] = -1;
                break;
            }
            else
            {
                cells_left--;
                field[x][y] = 1;
            }
        }
        x--;
    }

    x = x_;
    y = y_;
    while (x >= 0 && y >= 0 && field[x][y] >= 0)
    {
        if (field[x][y] == 0)
        {
            cout << x + 1 << " " << y + 1 << endl;
            string ans;
            cin >> ans;
            if (ans == "miss")
            {
                field[x][y] = -1;
                break;
            }
            else
            {
                cells_left--;
                field[x][y] = 1;
            }
        }
        y--;
    }

    x = x_;
    y = y_;
    while (x < n && y < n && field[x][y] >= 0)
    {
        if (field[x][y] == 0)
        {
            cout << x + 1 << " " << y + 1 << endl;
            string ans;
            cin >> ans;
            if (ans == "miss")
            {
                field[x][y] = -1;
                break;
            }
            else
            {
                cells_left--;
                field[x][y] = 1;
            }
        }
        x++;
    }

    x = x_;
    y = y_;
    while (x < n && y < n && field[x][y] >= 0)
    {
        if (field[x][y] == 0)
        {
            cout << x + 1 << " " << y + 1 << endl;
            string ans;
            cin >> ans;
            if (ans == "miss")
            {
                field[x][y] = -1;
                break;
            }
            else
            {
                cells_left--;
                field[x][y] = 1;
            }
        }
        y++;
    }
}

int main()
{
    // freopen("input.txt", "rt", stdin);
    // freopen("output.txt", "wt", stdout);
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(0);

    // int n;
    int k;
    cin >> n >> k;
    cells_left = 5 * k;
    // 0 - unknown, 1 - hit, -1 - miss
    vii field(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((i + j) % 5 == 4)
            {
                cout << i + 1 << " " << j + 1 << endl;
                string ans;
                cin >> ans;
                if (ans == "miss")
                {
                    field[i][j] = -1;
                }
                else
                {
                    cells_left--;
                    field[i][j] = 1;
                }
            }
        }
    }
    assert(cells_left == 4 * k);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (field[i][j] == 1 && (i + j) % 5 == 4)
            {
                examine(field, i, j);
            }
        }
    }


    return 0;
}