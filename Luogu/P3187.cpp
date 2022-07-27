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

struct Point{
	double x, y;


	bool operator<(const Point &p) const {
		return x == p.x ? y < p.y : x < p.x;
	}
	
	Point operator-(const Point &p) const {
		return {x - p.x, y - p.y};
	}

	Point operator+(const Point &p) const {
		return {x + p.x, y + p.y};
	}

	double operator^(const Point &p) const {
		return x * p.y - y * p.x;
	}

	double operator*(const Point &p) const {
		return x * p.x + y * p.y;
	}

	Point operator*(const double d) const {
		return {x * d, + y * d};
	}

	double dis() const {
		return sqrt(x * x + y * y);
	}
	Point(double x, double y) : x(x), y(y){

	}

	Point() = default;
};

ostream &operator<<(ostream &os, const Point &p){
	return os << '(' << p.x << ' ' << p.y << ')';
}

inline int sgn(double d){
	if(fabs(d) <= EPS)
		return 0;
	if(d > 0)
		return 1;
	return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	Point ps[n], hull[n + 1];

	for(int i = 0; i < n; ++i)
		cin >> ps[i].x >> ps[i].y;

	sort(ps, ps + n);
	
	int idx = 0;
	
	for(int i = 0; i < n; ++i){
		while(idx >= 2 && ((hull[idx - 1] - hull[idx - 2]) ^ (ps[i] - hull[idx - 2])) <= 0)
			--idx;
		hull[idx++] = ps[i];
	}
	int lim = idx;
	for(int i = n - 2; i >= 0; --i){
		while(idx > lim && ((hull[idx - 1] - hull[idx - 2]) ^ (ps[i] - hull[idx - 2])) <= 0)
			--idx;
		hull[idx++] = ps[i];
	}

	int l = 0, r = 0, u = 0;

	double res = 1e18;

	Point p[4];

	for(int i = 1; i < idx; ++i){
		while(sgn(((hull[i] - hull[i - 1]) ^ (hull[(u + 1) % idx] - hull[i - 1])) - ((hull[i] - hull[i - 1]) ^ (hull[u] - hull[i - 1]))) >= 0 ) u = (u + 1) % idx;
		while(sgn(((hull[i] - hull[i - 1]) * (hull[(r + 1) % idx] - hull[i - 1]) - (hull[i] - hull[i - 1]) * (hull[r] - hull[i - 1]))) >= 0)
			r = (r + 1) % idx;
		if(i == 1)
			l = r;
		while(sgn((hull[i - 1] - hull[i]) * (hull[(l + 1) % idx] - hull[i]) - (hull[i - 1] - hull[i]) * (hull[l] - hull[i])) >= 0)
			l = (l + 1) % idx;

		double d = (hull[i] - hull[i - 1]).dis();
		double ldd = (hull[i - 1] - hull[i]) * (hull[l] - hull[i]) / d;
		double rdd = (hull[i] - hull[i - 1]) * (hull[r] - hull[i - 1]) / d;
		double h = ((hull[i] - hull[i - 1]) ^ (hull[u] - hull[i - 1])) / d;
		double a = (ldd + rdd - d) * h;
		if(a < res){
			res = a;
			p[0] = hull[i] + (hull[i - 1] - hull[i]) * (ldd / d);
			p[1] = hull[i - 1] + (hull[i] - hull[i - 1]) * (rdd / d);
			double w = (p[1] - p[0]).dis();
			Point k = p[1] - p[0];
			Point f = {-k.y, k.x};
			p[2] = p[1] + f * (h / w);
			p[3] = p[0] + f * (h / w);
		}
	}

	auto xyzz = [](double d){
		return (fabs(d) <= EPS) ? 0.0 : d;
	};

	cout << setprecision(5) << fixed << xyzz(res) << '\n';
	idx = 0;
	for(int i = 1; i < 4; ++i)
		if((p[idx].y == p[i].y && p[i].x < p[idx].x) || p[i].y < p[idx].y)
		   idx = i;	

	for(int i = 0; i < 4; ++i)
		cout << xyzz(p[(idx + i) % 4].x) << ' ' << xyzz(p[(idx + i) % 4].y) << '\n';


}

