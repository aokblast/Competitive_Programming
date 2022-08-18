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


using lll = __int128;

const int MAXN = 1e5 + 5;
const ll MOD = 999911659;
const ll INF = 1e9;
const ld EPS = 1e-7;



signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	int arr[n];

	int tmp = 0;
	for(int i = 0; i < n; ++i)
		cin >> arr[i], tmp ^= arr[i];

	if(tmp == 0){
		cout << "lose\n";
		return 0;
	}


	for(int i = 0; i < n; ++i){
		if((arr[i] ^ tmp) < arr[i]){
			cout << (arr[i] - (arr[i] ^ tmp)) << ' ' << (i + 1) << '\n';
			arr[i] ^= tmp;
			break;
		}
	}

	for(int i = 0; i < n; ++i)
		cout << arr[i] << ' ';

	cout << '\n';



}

