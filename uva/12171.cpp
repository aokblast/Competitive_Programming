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

const int MAXN = 1e2 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;



struct E{
    int x,y, z;
};


int main() {
    const int MAXC = 1005;
    int tc = 1, n;
    cin >> tc;
    int boxes[MAXN][6];
    int xs[MAXN << 1], ys[MAXN << 1], zs[MAXN << 1], xt, yt, zt;
    int vis[MAXN][MAXN][MAXN];
    int v, s;

    int DIRS[6][3] = {1, 0, 0, -1, 0, 0, 0, 1, 0, 0, -1, 0, 0, 0, 1, 0, 0, -1};

    auto getArea = [&](const E &e, int d){
        if(DIRS[d][0])
            return (ys[e.y + 1] - ys[e.y]) * (zs[e.z + 1] - zs[e.z]);
        if(DIRS[d][1])
            return (xs[e.x + 1] - xs[e.x]) * (zs[e.z + 1] - zs[e.z]);
        return (xs[e.x + 1] - xs[e.x]) * (ys[e.y + 1] - ys[e.y]);
    };

    auto getCol = [&](const E &e){
        return (xs[e.x + 1] - xs[e.x]) * (ys[e.y + 1] - ys[e.y]) * (zs[e.z + 1] - zs[e.z]);
    };


    auto bfs = [&](){
        queue<E> q;
        q.push({0, 0, 0});
        vis[0][0][0] = 2;
        while(!q.empty()){
            E e = q.front(); q.pop();
            v += getCol(e);
            for(int i = 0; i < 6; ++i){
                E ne = {e.x + DIRS[i][0], e.y + DIRS[i][1], e.z + DIRS[i][2]};
                if(ne.x < 0 || ne.y < 0 || ne.z < 0 || ne.x >= xt - 1 || ne.y >= yt - 1 || ne.z >= zt - 1 )
                    continue;
                if(vis[ne.x][ne.y][ne.z] == 1)
                    s += getArea(ne, i);
                else if(vis[ne.x][ne.y][ne.z] == 0)
                    vis[ne.x][ne.y][ne.z] = 2, q.push(ne);
            }

        }
        v = MAXC * MAXC * MAXC - v;
    };

    for(int t = 1; t <= tc; ++t){
        cin >> n;
        
        
        for(int i = 0; i < n; ++i){
            cin >> boxes[i][0] >> boxes[i][1] >> boxes[i][2] >> boxes[i][3] >> boxes[i][4] >> boxes[i][5];
            boxes[i][3] += boxes[i][0], boxes[i][4] += boxes[i][1], boxes[i][5] += boxes[i][2];
            xs[i * 2] = boxes[i][0], xs[i * 2 + 1] = boxes[i][3];
            ys[i * 2] = boxes[i][1], ys[i * 2 + 1] = boxes[i][4];
            zs[i * 2] = boxes[i][2], zs[i * 2 + 1] = boxes[i][5];
        }
        ys[n * 2] = zs[n * 2] = xs[n * 2] = 0;
        ys[n * 2 + 1] = zs[n * 2 + 1] = xs[n * 2 + 1] = MAXC;
        
        sort(xs, xs + 2 * n + 2);
        sort(ys, ys + 2 * n + 2);
        sort(zs, zs + 2 * n + 2);
        xt = unique(xs, xs + 2 * n + 2) - xs;
        yt = unique(ys, ys + 2 * n + 2) - ys;
        zt = unique(zs, zs + 2 * n + 2) - zs;
        memset(vis, 0, sizeof(vis));
        

        for(int i = 0; i < n; ++i){
            int x1 = lower_bound(xs, xs + xt, boxes[i][0]) - xs, x2 = lower_bound(xs, xs + xt, boxes[i][3]) - xs;
            int y1 = lower_bound(ys, ys + yt, boxes[i][1]) - ys, y2 = lower_bound(ys, ys + yt, boxes[i][4]) - ys;
            int z1 = lower_bound(zs, zs + zt, boxes[i][2]) - zs, z2 = lower_bound(zs, zs + zt, boxes[i][5]) - zs;
            for(int x = x1; x < x2; ++x)
                for(int y = y1; y < y2; ++y)
                    for(int z = z1; z < z2; ++z)
                        vis[x][y][z] = 1;
        }

        v = 0, s = 0;
        
        bfs();

        cout << s << ' ' << v << '\n';

    } 
}
