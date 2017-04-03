#include <bits/stdc++.h>
#define fori(i, N) for(int i =0; i < N; i++)
#define f first
#define s second
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ii> vii;
typedef vector<int> vi;

/*
each edge also has a flag: new or old edge, always favouring the old edges...
do normal kruskals.

the value of D only applies to the edges currently in set-up.
if D is not zero,
the value is either cnt or cnt-1...

look at all edges from N-1 to the end, checking if the edge is in the set, or if it's in the old set?

same idea of 2nd best MST

*/


int p[100010], rnk[100010], sz[100010], nsets, N, M, D;

int fs(int i){return (p[i] == i) ? i : (p[i] = fs(p[i]));}
bool ss(int i, int j){return fs(i) == fs(j);};
void us(int i, int j){
	if(!ss(i, j)){
		int x = fs(i), y = fs(j);
		if(rnk[x] > rnk[y]){
			sz[fs(x)] += sz[fs(y)];
			p[y] = x;
		}else{
			sz[fs(y)] += sz[fs(x)];
			p[x] = y;
			if(rnk[x] == rnk[y]) rnk[y]++;
		}
		nsets++;
	}
}

struct edge{
	int u, v, w, id;
	bool operator<(const edge& rhs) const{
		if(w == rhs.w){
			return id > rhs.id;
		}
        return w > rhs.w;
    }
};
edge lst[200010];
bool comp(edge a, edge b){
	if(a.w == b.w){
		return a.id < b.id;
	}
	return a.w<b.w;
}

int main(){
	scanf("%d %d %d", &N, &M, &D);
	edge tmp;
	priority_queue<edge> pq, pq2;
	for(int i = 1; i <= N; i++){
		p[i] = i;
	}

	for(int i =0; i < M; i++){
		scanf("%d %d %d", &tmp.u, &tmp.v, &tmp.w);
		tmp.id = 1;
		if(i < N-1) tmp.id = 0;
		//lst[i] = tmp;
		lst[i] = tmp;
		pq.push(tmp);
		pq2.push(tmp);
		//printf("%d %d %d %d\n", tmp.u, tmp.v, tmp.w, tmp.id);
	}
	sort(lst, lst+M, comp);
	int cnt = 0;
	int taken = 0;
	int largest = -1;
	int i =0;
	while(taken < N-1){
		edge a = lst[i++];
		if(!ss(a.u, a.v)){
			us(a.u, a.v);
			cnt += a.id;
			taken++;
			largest = max(largest, a.w);
		}
	}
	//scan through all possible edges left?
	//printf("%d %d %d %d\n", c.u, c.v, c.w, c.id);

	//cout << "YES" << endl;
	//cout << cnt << endl;
	if(lst[i-1].id == 0) printf("%d", cnt);
	else{
		for(i = 1; i <= N; i++)
			p[i] = i;
		
		memset(rnk, 0, sizeof(rnk));

		taken = 0;
		i = 0;
		bool found = false;
		while(i < M){
			edge a = lst[i++];
			if(!ss(a.u, a.v)){
				if(a.w < largest || (a.w == largest && a.id == 0)) us(a.u, a.v);
				else if(a.w <= D && a.id == 0){
					found = true;
					break;
				}
				taken++;
			}
		}
		if(found) printf("%d", cnt-1);
		else printf("%d", cnt);
		
		//printf("%d\n", cnt);
	}
	return 0;
}