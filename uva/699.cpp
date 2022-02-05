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

const int MAXN = 1e4 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

int main() {
    int tc = 1;
    // cin >> tc;
    string line;
    int sum[MAXN];
    int start;
    function<void(int)> build = [&](int u){
        int val;
        cin >> val;
        if(val == -1)
            return ;
        start = min(start, u);
        sum[u] += val;
        build(u - 1);
        build(u + 1);
    };
    bool a = false;
    while(true){
        memset(sum, 0, sizeof(sum));
        if(a)
            cout << '\n';
        a = true;
        int val;
        start = MAXN >> 1;
        cin >> val;
        if(val == -1)
            break;
        sum[MAXN >> 1] += val;
        build((MAXN >> 1) - 1);
        build((MAXN >> 1) + 1);
        cout << "Case " << (tc++) << ":\n";
        cout << sum[start++];
        while(sum[start])
            cout << " " << sum[start++];
        cout << '\n';

    }  


}
