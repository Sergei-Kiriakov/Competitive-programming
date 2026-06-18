#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <optional>
#include <algorithm>
#include <map>

using namespace std;

using ll = long long;

bool is_number(const string &s)
{
    for (auto c : s)
    {
        if (c < '0' || c > '9')
        {
            return false;
        }
    }
    return true;
}

bool is_coord_valid(const vector<vector<string>> &data, ll i, ll j)
{
    ll n = data.size();
    ll m = data.at(0).size();
    if (i < 0 || i >= n || j < 0 || j >= m)
    {
        return false;
    }
    return true;
}

std::optional<pair<ll, ll>> get_connector_coord(const vector<vector<string>> &data, ll i, ll j)
{
    if (!is_number(data[i][j]))
    {
        return std::nullopt;
    }
    vector<pair<ll, ll>> candidates_coord = {
        {i - 1, j},
        {i + 1, j},
        {i, j - 1},
        {i, j + 1}};
    for (const auto [cand_i, cand_j] : candidates_coord)
    {
        if (is_coord_valid(data, cand_i, cand_j) && data[cand_i][cand_j]=="#")
        {
            return make_pair(cand_i, cand_j);
        }
    }
    return std::nullopt;
}

std::optional<vector<pair<ll, ll>>> get_operands_coord(const vector<vector<string>> &data, ll i, ll j)
{
    if (data[i][j] != "+" && data[i][j] != "*" && data[i][j] != "-" && data[i][j] != "/")
    {
        return std::nullopt;
    }
    vector<pair<ll, ll>> candidates_coord = {
        {i - 1, j},
        {i + 1, j},
        {i, j - 1},
        {i, j + 1}};
    vector<pair<ll, ll>> operands_coord;
    for (const auto [cand_i, cand_j] : candidates_coord)
    {
        if (is_coord_valid(data, cand_i, cand_j) && is_number(data[cand_i][cand_j]))
        {
            operands_coord.emplace_back(cand_i, cand_j);
        }
    }
    if (operands_coord.size() < 2)
    {
        return std::nullopt;
    }
    // if (operands_coord.size() > 2)
    // {
    //     throw std::logic_error("fail logic");
    // }
    return operands_coord;
}

std::string calculate_expression(const vector<vector<string>> &data, ll i, ll j, const vector<pair<ll, ll>> &operands_coord)
{
    const auto [first_operand_i, first_operand_j] = operands_coord.at(0);
    const auto [second_operand_i, second_operand_j] = operands_coord.at(1);
    ll first_value = std::stoll(data[first_operand_i][first_operand_j]);
    ll second_value = std::stoll(data[second_operand_i][second_operand_j]);
    if (first_value < second_value)
    {
        std::swap(first_value, second_value);
    }
    if (data[i][j] == "+")
    {
        return to_string(first_value + second_value);
    }
    if (data[i][j] == "-")
    {
        return to_string(first_value - second_value);
    }
    if (data[i][j] == "*")
    {
        return to_string(first_value * second_value);
    }
    if (second_value==0){
        return "0";
    }
    return to_string(first_value / second_value);
}

std::optional<string> get_printer_value(const vector<vector<string>> &data, ll i, ll j)
{
    if (data[i][j] != "P")
    {
        return std::nullopt;
    }
    vector<pair<ll, ll>> candidates_coord = {
        {i - 1, j},
        {i + 1, j},
        {i, j - 1},
        {i, j + 1}};
    for (const auto [cand_i, cand_j] : candidates_coord){
        if (is_coord_valid(data, cand_i, cand_j) && is_number(data[cand_i][cand_j]))
        {
            return data[cand_i][cand_j];
        }
    }
    return std::nullopt;
}

void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<string> raw_data(n);
    for (int i = 0; i < n; i++)
    {
        cin >> raw_data[i];
    }
    // cerr << "flag one";
    vector<vector<string>> data;
    for (int i = 0; i < n; i++)
    {
        vector<string> line;
        for (int j = 0; j < m; j++)
        {
            string tmp;
            tmp.push_back(raw_data[i][j]);
            line.push_back(tmp);
        }
        data.push_back(line);
    }
    // cerr << "flag two";

    while (1)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                const auto maybe_connector_coord = get_connector_coord(data, i, j);
                if (maybe_connector_coord.has_value())
                {
                    const auto [connector_coord_i, connector_coord_j] = maybe_connector_coord.value();
                    data[connector_coord_i][connector_coord_j] = data[i][j];
                    data[i][j] = ".";
                    continue;
                }
                // cerr << "flag three";

                const auto maybe_operands_coord = get_operands_coord(data, i, j);
                if (maybe_operands_coord.has_value())
                {
                    const auto operands_coord = maybe_operands_coord.value();
                    const auto expr_val = calculate_expression(data, i, j, operands_coord);
                    data[i][j] = expr_val;
                    const auto [first_operand_i, first_operand_j] = operands_coord.at(0);
                    const auto [second_operand_i, second_operand_j] = operands_coord.at(1);
                    data[first_operand_i][first_operand_j] = ".";
                    data[second_operand_i][second_operand_j] = ".";
                    continue;
                }
                // cerr << "flag four";

                const auto maybe_printer_value = get_printer_value(data, i, j);
                if (maybe_printer_value.has_value())
                {
                    cout << maybe_printer_value.value() << '\n';
                    return;
                }
                // cerr << "flag five";
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}

/*
6 8
3.......
#....P..
#....#.2
#.###*#+
##-....#
..1...4#
*/

/*
4 3
.4.
./P
9*.
.#7
*/

/*
5 11
8...8.....8
#.###...###
#.#...P.#..
#**##-*+/##
.4...3.0..1
*/

/*
5 11
6##########
..........#
########P.#
#.........#
###########
*/

/*
2 3
.P.
2/0
*/

/*
1 2
5P
*/

/*
1 6
5####P
*/
