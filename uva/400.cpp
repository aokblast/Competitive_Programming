#include <bits/stdc++.h>

using namespace std;

const int maxn = 100 + 5;

string arr[maxn];



int main(){
  int n;
  string nLine(60, '-');
  string line;

  while(cin >> n){
    int ma = 0;
    for(int i = 0; i < n; ++i){
      cin >> arr[i];
      ma = max(ma, (int)arr[i].size());
    }
    cout << nLine << '\n';
    int cols = (60 - ma) / (ma + 2) + 1, rows = (n - 1)  / cols + 1;
    sort(arr, arr + n);
    for(int i = 0; i < rows; ++i){
      for(int j = 0; j < cols; ++j ){
          int idx = j * rows + i;
          if(idx >= n)continue;
          cout << arr[idx];
          for(int k = 0; k < (j == cols - 1 ? ma : ma + 2) - arr[idx].size(); ++k){
            cout << ' ';
          }
      }
      cout << '\n';
    }
    
  }
}
