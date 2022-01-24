#include <bits/stdc++.h>

using namespace std;

const int MAXLEN = 1e4 + 5;

char str[MAXLEN];
char tmp[MAXLEN];
int f[MAXLEN];
int cnt[MAXLEN];

void fail(char s[]){
  int i = 0, j = -1;
  int n = strlen(s);
  f[0] = -1;
  while(i < n){
    if(j == -1 || s[i] == s[j]){
      f[++i] = ++j;
    }else{
      j = f[j];
    }
  }



}

int main(){
  int tc;
  scanf(" %d", &tc);
  while(tc--){
    scanf(" %s", str);
  }
}
