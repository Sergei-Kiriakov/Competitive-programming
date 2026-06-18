#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

using ll = long long;

int count_dist(const vector<int>& lhs, const vector<int>& rhs) {
    int ans = 0;
    for (int i = 0; i<lhs.size(); i++){
        ans+=abs(lhs[i]-rhs[i]);
    }
    return ans;
}

void solve(){
    ll n, l, k;
    cin >> n >> l >> k;
    vector<string> protein_names(n);
    vector<vector<int>> protein_embendings(n, vector<int>(l));
    for (int i=0; i<n; i++) {
        cin >> protein_names[i];
        for (int j=0; j<l; j++) {
            cin >> protein_embendings[i][j];
        }
    }

    vector<int> distances(n, 1000000);
    vector<int> added_indexes;
    int best_dist = 0;
    int best_ind = 0;
    for (int i=1; i<n; i++){
        int dist = count_dist(protein_embendings[i], protein_embendings[0]);
        if (dist>best_dist){
            best_dist = dist;
            best_ind = i;
        }
    }
    added_indexes.push_back(best_ind);

    for (int i=0; i<k-1; i++){
        int last_added_index = added_indexes.back();
        best_dist = 0;
        best_ind = last_added_index;
        for (int j=0; j<n; j++){
            distances[j] = min(distances[j], count_dist(protein_embendings[last_added_index], protein_embendings[j]));
            if (distances[j] > best_dist) {
                best_dist = distances[j];
                best_ind = j;
            }
        }
        added_indexes.push_back(best_ind);
    }

    for (const auto ind: added_indexes){
        cout << protein_names[ind] << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
