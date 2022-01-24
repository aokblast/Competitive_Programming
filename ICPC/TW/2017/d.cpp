#include <bits/stdc++.h>

using namespace std;

const int MAXLEN = 2e2 + 5;

int v[MAXLEN][MAXLEN];


int main(){

  int n, m;
  
  while(cin >> n && n && cin >> m){
    memset(v, 0x3f, sizeof(v));
  
    map<int, int> va;

    int s, t;

    while(m--){
      cin >> s >> t;
      v[s][t] = 1;
      v[t][s] = 1;
    }
    for(int k = 0; k < n; ++k){
      for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
          v[i][j] = min(v[i][j], v[i][k] + v[k][j]);

        }
      }
    }
    for(int i = 0; i < n; ++i){
      for(int j = i + 1; j < n; ++j){
        va[v[i][j]] += 2;
      }
    }

    for(const auto & p : va){
      if(p.first < 1000)cout << p.first << " " << p.second << '\n';
    }


  }
}
