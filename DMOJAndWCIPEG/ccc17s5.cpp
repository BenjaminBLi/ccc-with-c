#include <bits/stdc++.h>
#define fori(i, n) for(int i =0; i < (int) n; i++)
#define f first
#define s second
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ii> vii;
typedef vector<int> vi;

/*
7 3 8
1 2 1 3 3 1 1
1 2 3 4 5 6 7

line[0]: {0 --> 2 --> 5 --> 6 --> 0}
line[1]: {1}
line[2]: {3 --> 4}

rght[0]: {}
rght[1]:
rght[2]:
*/

map<int, int> id, loc;
vi lines[150010];
int val[150010], N, M, Q, sBlock[400], cycle[150010], cntL[150010], sz;
int rght[150010][400];

int valAt(int idx){
	int cL = id[idx]; //line of the idx
	int cIdx = loc[idx];
	cIdx -= cycle[cL];
	cIdx += lines[cL].size();
	cIdx %= lines[cL].size();
	return val[lines[cL][cIdx]];
}

void genRight(){
	memset(rght, -1, sizeof(rght));
	for(int i =0;i < N; i++){
		rght[id[i]][i/sz]=loc[i];
	}
}

int main(){
	scanf("%d %d %d", &N,&M, &Q);
	sz = (int) sqrt(N);
	//cout << sz << endl;
	int nB = sz+1;
	if(sz*sz == N) nB--;
	int tmp;

	for(int i = 0; i < N; i++){
		scanf("%d", &tmp);
		lines[tmp].push_back(i);
		id[i] = tmp;
		loc[i] = cntL[tmp]++;
	}
	for(int i = 0; i < N; i++){
		scanf("%d", &val[i]);
		sBlock[i/sz] += val[i];
	}
	genRight();
	int id, l, r;
	for(;Q--;){
		scanf("%d", &id);
		if(id == 1){
			scanf("%d %d", &l, &r); l--; r--;
			int lb = l/sz, rb = r/sz;
			long long ans = 0;
			for(int i = lb; i < rb; i++) ans += sBlock[i];
			for(int i = lb*sz; i < l; i++) ans -= valAt(i);
			for(int i = rb*sz; i <= r; i++) ans += valAt(i);
			printf("%lld\n", ans);
		}else{
			scanf("%d", &l);
			//cout << "UPDATE" << endl;
			for(int i =0;i < nB; i++){
				if(rght[l][i] == -1) continue;
				//cout << valAt(lines[l][rght[l][i]]) << endl;
				sBlock[i] -= valAt(lines[l][rght[l][i]]);
			}
			cycle[l]++;
			cycle[l] %= lines[l].size();
			for(int i =0;i < nB; i++){
				if(rght[l][i] == -1) continue;
				//cout << valAt(lines[l][rght[l][i]]) << endl;
				sBlock[i] += valAt(lines[l][rght[l][i]]);
			}
			//cout << "END" << endl;
		}
	}
	return 0;
}