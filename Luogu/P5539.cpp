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

const int MAXN = 3e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-7;

unsigned long long bs[15625001] = {0};

unsigned long long tmp[64];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

	int n, s;
	cin >> n >> s;

	int cur;

	int q = n / 64;
	while(s--){
		cin >> cur;
		if(cur < 64){
			memset(tmp, 0, sizeof(tmp));
			for(int i = 0; i < (cur << 6); i += cur)
				tmp[i >> 6] |= 1ull << (i & 63);
			
			for(int i = 0; i <= q + 1; i += cur)
				for(int j = 0; j < cur; ++j)
					bs[i + j] |= tmp[j];
		}else
			for(int i = cur; i <= n; i += cur)
				bs[i >> 6] |= 1ull << (i & 63);
	}



	auto cnt = [](unsigned long long i){
	i=(i&0x5555555555555555)+(i>>1&0x5555555555555555),
	i=(i&0x3333333333333333)+(i>>2&0x3333333333333333),
	i=(i&0x0f0f0f0f0f0f0f0f)+(i>>4&0x0f0f0f0f0f0f0f0f),
	i=(i&0x00ff00ff00ff00ff)+(i>>8&0x00ff00ff00ff00ff),
	i=(i&0x0000ffff0000ffff)+(i>>16&0x0000ffff0000ffff);
	return i+(i>>32);
	};

	bs[0] &= -2ull;

	if((n & 63) != 63)
		bs[q] &= (1ull << (n + 1 - (q << 6))) - 1;
	int res = 0;
	for(int i = 0; i <= q; ++i)
		res += cnt(bs[i] & (bs[i] << 1) & (bs[i] << 2));

	for(int i = 1; i <= q; ++i)
		res += cnt(bs[i] & (bs[i - 1] >> 62) & ((bs[i] << 1) | (bs[i - 1] >> 63)));
	cout << res << '\n';



}

