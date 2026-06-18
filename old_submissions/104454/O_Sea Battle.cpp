#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;
using ll = long long;
void input(vector <ll> &val, vector <vector <pair <int, int> > > &roads, int ind){
    ll m, g;
    cin >> m >> g;
    for (int i=0; i<m; i++){
        ll x;
        cin >> x;
        val[x]++;
    }
    for (int i=0; i<g; i++){
        int x, y;
        cin >> x >> y;
        roads[ind].push_back({x, y});
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    char field[10][10];
    for (int i=0; i<10; i++){
        for (int j=0; j<10; j++){
            cin >> field[i][j];
        }
    }
    int q;
    cin >> q;
    int lived = 10, hurt = 0, died = 0;
    for (int i=0; i<q; i++){
        string s;
        cin >> s;
        if (s=="SHOW"){
            cout << lived << " " << hurt << " " << died << '\n';
        }else{
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            if (field[x][y]=='#'){
                string xship, yship;
                int cx = x, cy = y;
                while (x>0 && field[x-1][y]!='*'){
                    x--;
                }
                while (y>0 && field[x][y-1]!='*'){
                    y--;
                }
                int bx = x, by = y;
                while (x<=9 && field[x][y]!='*'){
                    xship.push_back(field[x][y]);
                    x++;
                }
                x = bx;
                while (y<=9 && field[x][y]!='*'){
                    yship.push_back(field[x][y]);
                    y++;
                }
                field[cx][cy] = 'h';
                if (xship.size()<yship.size()) xship = yship;
                int h = 0;
                for (int i=0; i<xship.size(); i++){
                    if (xship[i]=='h') h++;
                }
                if (h>0){
                    if (h+1==xship.size()){
                        hurt--;
                        died++;
                    }
                }else {
                    if (h+1==xship.size()){
                        lived--;
                        died++;
                    }else {
                        lived--;
                        hurt++;
                    }
                }
            }
        }
    }
}
