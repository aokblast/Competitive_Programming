#include <bits/stdc++.h>

using namespace std;

int arr[6][6];

int dir[2][2][2] = {{{1, 0}, {-1, 0}}, {{0, 1}, {0, -1}}};

int len[12];

int d[12], tcar;
bool vis[6][6];

bool inbound(int x, int y){
  return x >= 0 && x < 6 && y >= 0 && y < 6;
}

int calc(){
  for(int i = 0; i < 6; ++i){
    if(arr[2][i] == 1){
      return 6 - i;
    }
  }
  return 0;
}

int dfslen(int x, int y, int id){
  vis[x][y]  = true;
  int ans = 0;
  for(int i = 0; i < 2; ++i){
    int nx = dir[d[id]][i][0] + x, ny = dir[d[id]][i][1] + y;
    if(inbound(nx, ny) && id == arr[nx][ny] &&  !vis[nx][ny]){
      ans +=  dfslen(nx, ny, id);
    }
  }
  return ans + 1;
}


bool dfs(int step, int cur){
  int p = calc();
  if(p + cur > step)return false;
  if(p == len[1])return true;

  for(int i = 0; i < 6; ++i){
    for(int j = 0; j < 6; ++j){
      if(arr[i][j]){
        int bianhao = arr[i][j];
        for(int k = 0; k < 2; ++k){
          int nx = dir[d[bianhao]][k][0] * len[bianhao] + i, ny = dir[d[bianhao]][k][1] * len[bianhao] + j;
          int nnx = dir[d[bianhao]][k][0] * (len[bianhao] - 1) + i, nny= dir[d[bianhao]][k][1] * (len[bianhao] - 1) + j;
          if(arr[nnx][nny] == bianhao && inbound(nx, ny) && !arr[nx][ny]){
            arr[nx][ny] = bianhao;
            arr[i][j] = 0;
            if(dfs(step, cur + 1))return true;
            arr[i][j] = bianhao;
            arr[nx][ny] = 0;
          }
        }
      }
    }
  }
  return false;
}

int main(){
  for(int i = 0; i < 6; ++i){
    for(int j = 0; j < 6; ++j){
      cin >> arr[i][j];
      tcar = max(tcar, arr[i][j]);
    }  
  }
  memset(d, -1, sizeof(d));
  for(int i = 0; i < 6; ++i){
    for(int j = 0;j < 6; ++j){
      if(arr[i][j] && !len[arr[i][j]]){
        if(d[arr[i][j]] == -1)d[arr[i][j]] = ((inbound(i - 1, j) && arr[i - 1][j] == arr[i][j]) || (inbound(i + 1, j) && (arr[i + 1][j] == arr[i][j])) ? 0 : 1);
        len[arr[i][j]] = dfslen(i, j, arr[i][j]);
      }
    }
  }
  for(int i = 1; i <= 10; ++i){
    if(dfs(i, 0)){
      cout << i << endl;
      return 0;
    }
  }
  cout << -1 << endl;

}
