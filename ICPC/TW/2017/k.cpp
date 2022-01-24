#include <bits/stdc++.h>

using namespace std;


const int MAXLEN = 25;

vector<int> adjs[MAXLEN];

int color[MAXLEN];
int n;
bool dfs(int id){
  if(id == n)return true;
  for(int i = 0; i < 3; ++i){
    color[id] = i;
    for(const int &adj : adjs[id]){
      if(adj < id && color[adj] == color[id]){
        goto end;
      }
    }
    if(dfs(id  +1)) return true;

end: 
1;

  }
  return false;
}


int main(){
  int tc, fr, to, m;
  cin >> tc;
  while(tc--){
      cin >> n >> m;
      for(int i = 0; i < n; ++i) adjs[i].clear();
      while(m--){
        cin >> fr >> to;
        adjs[fr].push_back(to);
        adjs[to].push_back(fr);
      }
      memset(color, 0, sizeof(color));
      cout << (dfs(1) ? "Y\n"  : "N\n");

  }
}
