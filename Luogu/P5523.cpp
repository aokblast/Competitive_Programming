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

const int MAXN = 2e7 + 16;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-7;

namespace Maker {

typedef unsigned int uit;

bool __sp;
uit __x, __y, __z;
int __type, __k, __m;

const int L = 1 << 21;
char buf[L], *front=buf, *end=buf;
char GetChar() {
  if (front == end) {
    end = buf + fread(front = buf, 1, L, stdin);
    if (front == end) return -1;
  }
  return *(front++);
}

template <typename T>
inline void qr(T &x) {
  char ch = GetChar(), lst = ' ';
  while ((ch > '9') || (ch < '0')) lst = ch, ch = GetChar();
  while ((ch >= '0') && (ch <= '9')) x = (x << 1) + (x << 3) + (ch ^ 48), ch = GetChar();
  if (lst == '-') x = -x;
}

template <typename T>
inline void Begin(const T &x) {
  __type = x % 10;
  qr(__x); qr(__y); qr(__z); qr(__m);
  __sp = (__type == 3) || (__type == 4); __type &= 1;
}

inline uit __Next_Integer() {
  __x ^= __y << (__z & 31);
  __y ^= __z >> (__x & 31);
  __z ^= __x << (__y & 31);
  __x ^= __x >> 5; __y ^= __y << 13; __z ^= __z >> 6;
  return __x;
}

inline uit Rand() { return __Next_Integer(); }

template <typename Tx, typename Ty, typename Tz>
inline void Get_Nextline(Tx &x, Ty &y, Tz &z) {
  if (__m) {
    --__m;
    x = 0; y = 0; z = 0;
    qr(x); qr(y); qr(z);
    if (x == 0) {
      ++__k;
    }
  } else {
    x = Rand() & 1; y = Rand() & 1;
    if (__k == 0) { x = 0; }
    if (x == 0) {
      ++__k;
      if (__sp) {
        z = __type;
      } else {
        z = Rand() & 1;
      }
    } else {
      int dk = __k >> 1;
      if (dk == 0) {
        z = 1;
      } else {
        z = Rand() % dk + dk;
      }
    }
  }
}

}

int lq[MAXN], rq[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

	int n;


	scanf("%d", &n);
	Maker::Begin(n);


	int x, y, z;	
	int l = 1e7 + 6, r = 1e7 + 5, ans0 = 0, ans1 = 0, ans2 = 0, ans3 = 0;
	memset(lq, -1, sizeof(lq));
	memset(rq, -1, sizeof(rq));
	
	for(int t = 1; t <= n; ++t){
		Maker::Get_Nextline(x, y, z);
		if(x == 0){
			if(y == 0 && z == 1){
				l--;
				lq[l] = -1;
				rq[l] = rq[l + 1];
			}else if(y == 0 && z == 0){
				l--;
				rq[l] = l;
				for(int i = l; i <= r && lq[i] == -1; ++i)
					lq[i] = l;
			}else if(y == 1 && z == 0){
				++r;
				lq[r] = r;
				for(int i = r; i >= l && rq[i] == -1; --i)
					rq[i] = r;
			}else{
				++r;
				rq[r] = -1;
				lq[r] = lq[r - 1];
			}
		}else{
			int res = 0;
			int z2;
			if(y == 0){
				z = z + l - 1;
				z2 = lq[z];
				if(z == l)
					res = lq[z] == -1 ? 1 : 0;
				else{
					if(z2 == l)
						--z2;
					if(z2 == -1)
						z2 = l;
					if((z - z2) % 2 == 0)
						res = 1;
				}
			}else{
				z = r - z + 1;
				z2 = rq[z];
				if(z == r)
					res = rq[z] == -1 ? 1 : 0;
				else{
					if(z2 == r)
						++z2;
					if(z2 == -1)
						z2 = r;
					if((z2 - z) % 2 == 0)
						res = 1;
				}
			}
			ans0 += res;
			ans1 += (t % 2) && !res;
			ans2 += (!(t % 2)) && res;
			ans3 += (!(t % 1024)) && !res;
		}
	}

	printf("%d %d %d %d\n", ans0, ans1, ans2, ans3);


}
