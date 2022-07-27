#include <bits/stdc++.h>

using namespace std;

const int MAXN = 8e3 + 5;


int djs[MAXN];

inline void init(int n){
	for(int i = 0; i < n; ++i)
		djs[i] = i;
}

int find(int u){
	return djs[u] == u ? u : djs[u] = find(djs[u]);
}



int main(){
	int n;
	cin >> n;

	int colors[n];
	int recs[n][5];

	int xs[n << 1], ys[n << 1];


	memset(colors, 0, sizeof(colors));

	for(int i = 0; i < n; ++i)
		cin >> recs[i][0] >> recs[i][1] >> recs[i][2] >> recs[i][3] >> recs[i][4], xs[i << 1] = recs[i][0], xs[i << 1 | 1] = recs[i][2], ys[i << 1] = recs[i][1], ys[i << 1 | 1] = recs[i][3];

	sort(xs, xs + (n << 1)), sort(ys, ys + (n << 1));
	
	int xx = unique(xs, xs + (n << 1)) - xs, yy = unique(ys, ys + (n << 1)) - ys;
	
	for(int i = 0; i < n; ++i){
		recs[i][0] = lower_bound(xs, xs + xx, recs[i][0]) - xs;
		recs[i][1] = lower_bound(ys, ys + yy, recs[i][1]) - ys;
		recs[i][2] = lower_bound(xs, xs + xx, recs[i][2]) - xs;
		recs[i][3] = lower_bound(ys, ys + yy, recs[i][3]) - ys;
	}


	
	for(int i = 0; i < xx; ++i){
		init(yy);
		for(int j = n - 1; j >= 0; --j){
			if(recs[j][0] <= i && i < recs[j][2]){
				for(int k = recs[j][3]; k < recs[j][1]; k = find(k)){
					int p1 = find(k), p2 = find(k + 1);
					if(p1 == p2)
						continue;
					djs[p1] = p2;
					colors[recs[j][4] - 1] = 1;
				}
			}
		}
	}





	cout << count(colors, colors + n, 1) << '\n';
	



	
}
