#include <bits/stdc++.h>
using namespace std;
const int N = 1<<20;
const int inf = (int)1e6+1;

/*
TEST CASE:
2 17
30
20
10
40
W
R 2 12
W
R 3 41
W
R 4 9
W
R 1 1
S 2
R 4 50
S 1
R 2 35
W
R 3 20
W
R 3 10
W
*/

map<int, int> pwr;
int sz, n, m;
int a[N*2];
int wins[N+1];

void init(){
	for(int i =0; i < sz<<1; i++) a[i] = -1;
}

void st(int pos, int x){
	//printf("set: %d to: %d\n", x, pos);
	pwr[x] = pos;
	a[pos+sz-1] = x;
	int l = pos&1 ? pos : pos-1, r = l+1;
	l += sz-1, r += sz-1;
	//cout << l << ", " << r << endl;

	for(; l > 1; l >>= 1) {
		if(l&1) l--;
		r= l+1;
		//cout << pwr[a[l]] << ", " << pwr[a[r]] << endl;
		
		wins[pwr[a[l>>1]]]--;
		int best = max(a[l], a[r]);
		a[l>>1] = best;
		wins[pwr[a[l>>1]]]++;
		//cout << l << ", "<<r << endl;
	}
	//cout << endl;
}

void build(){
	for(int lvl = n; lvl > 0; lvl--){
		int extra = 1<<lvl;
		for(int i = 1; i < 1<<lvl; i+= 2){
			int pos = extra+i, pos2 = extra+i-1;
			a[pos>>1] = max(a[pos], a[pos2]);
			wins[pwr[a[pos>>1]]]++;
		}
	}
}

int main(){
	scanf("%d %d", &n, &m);
	sz =  1 << n;
	//cout << sz << endl << endl;
	//n <<= 1;
	int l;
	for(int i = 0; i < sz; i++){
		scanf("%d", &l);
		pwr[l] = i+1;
		//cout << i+sz << endl;
		a[i+sz] = l;
		//st(i, l);
	}
	build();
	//st(16, 0);
	//for(int i = 1; i < sz<<1; i++) printf("%d, ", pwr[a[i]]); cout << endl;
	//for(int i =0; i < sz; i++) printf("%d, ", wins[i+1]); cout << endl;
	
	char ch;
	int r;
	for(int M = 0; M < m; M++){
		//printf("%d: \n", M+1);
		getchar(); ch = getchar();
		if(ch == 'W') printf("%d\n", pwr[a[1]]);
		else if(ch == 'S'){
			scanf("%d", &l);
			printf("%d\n", wins[l]);
		}else{
			scanf("%d %d", &l, &r);
			st(l, r);
		}
		//for(int i = 1; i < sz<<1; i++) printf("%d, ", pwr[a[i]]); cout << endl;
		//for(int i =0; i < sz; i++) printf("%d, ", wins[i+1]); cout << endl;
	}
	
	return 0;
}