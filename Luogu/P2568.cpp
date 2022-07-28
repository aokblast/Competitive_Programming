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
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-7;

bool vis[MAXN] = {false};
int primes[MAXN];
ll sum[MAXN] = {0};
int phi[MAXN];


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	
	int n = 0;
	cin >> n;

	int tot = 0;

	phi[1] = 1;
	sum[1] = 2;
	for(int i = 2; i <= n; ++i){
		if(!vis[i]){
			primes[tot++] = i;
			phi[i] = i - 1;
		}
		for(int j = 0; j < tot && i * primes[j] <= n; ++j){
			vis[i * primes[j]] = true;
			if(i % primes[j])
				phi[i * primes[j]] = phi[i] * phi[primes[j]];
			else{
				phi[i * primes[j]] = primes[j] * phi[i];
				break;
			}
		}

		sum[i] = sum[i - 1] + phi[i] * 2;

	}

	
	ll res = 0;

	for(int i = 0; i < tot; ++i){
		res += sum[n / primes[i]] - 1;
	}

	cout << res << '\n';



	
}
