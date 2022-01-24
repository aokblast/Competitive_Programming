#include <bits/stdc++.h>

const int MAXLEN = 1e6 + 5;

using namespace std;

int djs[MAXLEN * 2];

int n, m;

vector<pair<int, pair<int, int>>> child[MAXLEN];

void init(){
  for(int i = 0; i < 2 * n; ++i)djs[i] = i;
  for(int i = 0; i < n; ++i) djs[i] = n + i;
}


int find(int id){return djs[id] == id ? id : djs[id] = find(djs[id]);}

void dfs(){
}


int main(){
  cin >> n >> m;
  init();
  int a, b, c, d;
  while(m--){
    cin >> a >> b;
    switch(a){
      case 1:
      case 3:
      case 4:
        cin >> c >> d;
        child[b].push_back({a, c, d});
        break;
      case 2:
      case 5:
        cin >> c;
        child[b].push_back({a, c, 0});
        break;
    }
  }
  dfs();
}
