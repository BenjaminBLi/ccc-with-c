#include <bits/stdc++.h>
using namespace std;

int N, K, B, a[100010], d[100010], l[100010], r[100010];

int main(){
	//freopen("maxcross.in", "r", stdin);
	//freopen("maxcross.out", "w", stdout);

	scanf("%d %d %d", &N, &K, &B);
	int r, c, r1, c1;
	for(int i = 1; i <= B; i++){
		scanf("%d", a+i);
	}
	sort(a, a+B);
	a[0] = a[1]; a[B] = a[B-1]
	if(N == 1){
		if(max(N-a[1], a[1])+1 >= K) cout << 0 << endl;
		else cout << 1 << endl;
	}else{
		int best = 0, b2 = 0;;
		for(int i =1; i <= B; i++){
			l[i] = a[i]-a[i-1]+1;
			r[i] = a[i+1]-a[i]+1;
			best = max(best, max(l[i], r[i]));
			d[i] = l[i]+r[i]-1;
			best = max(best, d[i]);
		}
		if(best >= K) cout << 0 << endl;
		if(b2 >= K) cout << 1 << endl;
		for(int sz = 2; sz <= N; sz++){
			best = 0;
			for(int i = sz; i <= B-sz; i++){
				//
			}
		}
	}
}