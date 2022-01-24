#include <bits/stc++.h>

using namespcat std;

double abf(double x, double y){
  x -= 1, y -= 1;
  return min(abs(x - y) , 1 - abs(x - y));
}

int main(){

}
