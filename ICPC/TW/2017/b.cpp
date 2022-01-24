#include <bits/stdc++.h>

using namespace std;

const int MAXLEN = 305;

int arr[MAXLEN][MAXLEN];

int main(){
  int tc, n;
  cin >> tc;
  while(tc--){
    cin >> n;
    int m = (n * (n - 1)) / 2;
    int i, j, val;
    memset(arr, 0, sizeof(arr));
    while(m--){
      cin >> i >> j >> val;
      arr[i][j] = arr[j][i] = val;
    }
    int ans = 0;
    for(int i = 1; i <= n; ++i){
      for(int j = i + 1; j <= n; ++j){
        for(int k = j + 1; k <= n; ++k){
          ans = max(ans, arr[i][j] + arr[j][k] + arr[i][k]);
        }
      }
    }
    cout << ans << endl;
  }
}

