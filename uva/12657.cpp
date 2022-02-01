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

int main() {
    int tc = 1;
    int n, m;
    int right[MAXN];
    int left[MAXN];


    auto link = [&](const int l, const int r){
        right[l] = r;
        left[r] = l;
    };

    while(cin >> n >> m){
        int  op, a, b; 
        bool inv = false;
        
        for(int i = 1; i <= n; ++i)
            right[i] = (i + 1) % (n + 1), left[i] = i - 1;
        right[0] = 1, left[0] = n;
        while(m--){
            cin >> op;
            if(op == 4){
                inv = !inv;
                continue;
            }    
            cin >> a >> b;
            if(op == 3 && a == right[b]) swap(a, b);
            if(op != 3 && inv)
                op =  3 - op;
            if(op == 1 && a == left[b])
                continue;
            if(op == 2 && a == right[b])
                continue;        
        
            
            int la = left[a], lb = left[b], ra = right[a], rb = right[b];
            
            switch(op){
                case 1:
                    link(la, ra), link(lb, a), link(a, b);
                    break;
                case 2:
                    link(la, ra), link(b, a), link(a, rb);
                    break;
                case 3:
                    if(right[a] == b)
                        link(la, b), link(b, a), link(a, rb); 
                    else 
                        link(la, b), link(b, ra), link(lb, a), link(a, rb);
                    break;
            }

        }
        int cur = 0;
        long long res = 0; 
        for(int i = 1; i <= n; ++i){
            cur = right[cur];
	    if(i % 2 == 1)
                res += cur;
        }


        cout << "Case " << (tc++) << ": " << (inv ? (long)n * (n + 1) / 2 - res : res) << '\n'; 
    }
}
