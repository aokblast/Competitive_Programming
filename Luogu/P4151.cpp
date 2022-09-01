nclude <bits/stdc++.h>

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

  int n, m, f, t;
  ll val;
  cin >> n >> m;

  vector<pair<int, ll>> adjs[n + 1];
  while(m--) {
      cin >> f >> t >> val;

      adjs[f].push_back({t, val});
      adjs[t].push_back({f, val});
    }

  bool vis[n + 1];

  ll pre[n + 1];

  ll p[65] = {0};

  memset(pre, 0, sizeof(pre));
  memset(vis, 0, sizeof(vis));

  function<void(int, ll)> dfs = [&](int u, ll cur) {
      pre[u] = cur, vis[u] = true;

      auto insert = [&](ll x)  {
            for(int i = 63; i + 1; --i) {
                    if(!(x & (1ll << i)))
                      continue;
                    if(!p[i]) {
                              p[i] = x;
                              break;
                            }
                    x ^= p[i];
                  }
          }; 

      for(const auto [v, w] : adjs[u]) {
            if(vis[v]) {
                    insert(pre[v] ^ cur ^ w);
                  } else {
                          dfs(v, cur ^ w);
                        }
          }
    };

  dfs(1, 0);

  ll res = pre[n];

  for(int i = 63; i + 1; --i )
    res = max(res, res ^ p[i]);


  cout << res << '\n';



}

