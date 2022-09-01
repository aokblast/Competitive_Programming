#include <bits/stdc++.h>

using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif


#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAXN = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-7;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  ll p[64] = {0};

  int n, res = 0;

  cin >> n;
  
  pair<int, ll> ps[n];

  for(int i = 0; i < n; ++i) 
    cin >> ps[i].second >> ps[i].first;
 
  sort(ps, ps + n);

  for(int i = n - 1; i >= 0; --i) {
    auto insert = [&](ll x) {
      for(int i = 63; i + 1; --i) {
        if(!(x & (1ll << i)))
          continue;

        if(!p[i]) {
          p[i] = x;
          return true;
        }

        x ^= p[i];
      }
      return false;
    };
    if(insert(ps[i].second))
      res += ps[i].first;

  }

  cout << res << '\n';
 
}
