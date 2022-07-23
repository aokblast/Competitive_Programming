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
const ld EPS = 1e-9;


vector<int> adjs[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	

	int n, k, a, b;
	cin >> n >> k;

	int rd[n + 1];
	memset(rd, 0, sizeof(rd));

	for(int i = 1; i < n; ++i){
		cin >> a >> b;
		adjs[a].push_back(b);
		adjs[b].push_back(a);
		rd[a]++, rd[b]++;
	}

	k = n - k;

	queue<int> q;
	int res = 1;

	for(int i = 1; i <= n; ++i)
		if(rd[i] == 1)
			q.push(i);

	while(!q.empty()){
		int sz = q.size();

		while(sz--){
			int t = q.front(); q.pop();
			--k;
			if(k == 0)
				goto result;
			for(const int adj : adjs[t])
				if(--rd[adj] == 1)
					q.push(adj);
		}

		++res;
	}

result:

	cout << res << '\n';

}
