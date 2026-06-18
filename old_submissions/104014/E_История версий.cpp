#include <bits/stdc++.h>

using namespace std;

void solveA(){
  
}

void solveB(){
  
}

void solveC(){
  
}

void solveD(){
  
}
int main(){
  long long n;
  cin >> n;
  long long r=1;
  while (r*10+1<=n){
    r=r*10+1;
  }
  int ans = 1;
  while (n>1){
    while((2*r-(r-1)/10)<=n and n>1){
      n-=r;
      ans++;
    }
    if (n>=r and r*2>n and n!=(2*r-(r-1)/10)) break;
    r=(r-1)/10;
  }
  cout << ans;
}

int m() {
  int a, b;
  cin >> a >> b;
  int d = a - b;
  cout << abs(d - b) << endl;
}