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

const int MAXN = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-7;


ll vals[MAXN << 2] = {0};
ll tag[MAXN << 2] = {0};
ll arr[MAXN];


void build(int u, int l, int r) {
  if(l == r)
    return void(vals[u] = arr[l]);
  int mid = l + (r - l) / 2;

  build(u << 1, l, mid);
  build(u << 1 | 1, mid + 1, r);
  vals[u] = vals[u << 1] + vals[u << 1 | 1];
}

void push_down(int u, int l, int r) {
  vals[u] += tag[u >> 1] * (r - l + 1);
  tag[u] += tag[u >> 1];
}

void insert(int u, int l, int r, int ul, int ur, int val) {

  if(l >= ul && r <= ur)
    return void((vals[u] += (r - l + 1) * val, tag[u] += val));

  int mid = l + (r - l) / 2;
  
  push_down(u << 1, l, mid);
  push_down(u << 1 | 1, mid + 1, r);

  tag[u] = 0;

  if(ul <= mid)
    insert(u << 1, l, mid, ul, ur, val);
  if(mid < ur)
    insert(u << 1 | 1, mid + 1, r, ul, ur, val);

  vals[u] = vals[u << 1] + vals[u << 1 | 1];
}

ll query(int u, int l, int r, int ul, int ur) {
  if(l >= ul && r <= ur)
    return vals[u];


  
  int mid = l + (r - l) / 2;
  push_down(u << 1, l, mid);
  push_down(u << 1 | 1, mid + 1, r);
  tag[u] = 0;

  ll sum = 0;

  if(ul <= mid)
    sum += query(u << 1, l, mid, ul, ur);
  if(mid < ur)
    sum += query(u << 1 | 1, mid + 1, r, ul, ur);
  return sum;
}



int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  
  int n, m, q, l, r, val;

  cin >> n >> m;

  for(int i = 0; i < n; ++i)
    cin >> arr[i];

  build(1, 0, n - 1);

  while(m--) {
    cin >> q >> l >> r;
    if(q == 1)
      cin >> val, insert(1, 0, n - 1, l - 1, r - 1, val);
    else
      cout << query(1, 0, n - 1, l - 1, r - 1) << '\n';
  }

}
