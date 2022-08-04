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

const int MAXN = 1e7 + 5;
const ll MOD = 19260817;
const ll INF = 1e9;
const ld EPS = 1e-7;

long long read(){
	char c = getchar();

	while(!isdigit(c))
		c = getchar();
	long long res = 0;
	while(isdigit(c))
		res = (res * 10 + c - '0') % MOD, c = getchar();
	return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	long long a = read();
	long long b = read();

	long long x, y;

	function<ll(ll, ll)> exgcd = [&](ll a, ll b){
		if(!b)
			return x = 1, y = 0, a;
		ll d = exgcd(b, a % b);
		ll t = x;
		x = y;
		y = t - (a / b) * y;
		return d;
	};

	if(b == 0)
		return ((bool)(cout << "Angry!\n"));
	
	exgcd(b, MOD);

	cout << ((((x % MOD) + MOD) % MOD) * a % MOD) << '\n';




}
