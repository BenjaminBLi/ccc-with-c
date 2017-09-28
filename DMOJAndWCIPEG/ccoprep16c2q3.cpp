#include <bits/stdc++.h>
using namespace std;

int N, arr[200010], hops[200010], nxt[200010], Q, sz;

void update(int i){
	int st = (i+1)*sz-1;
		hops[st] = 1;
	for(int j= 0; j < sz; j++){
		if((st-j) + arr[st-j] > st || (st-j)+arr[st-j] >= N) {
			hops[st-j] = 1;
			nxt[st-j] = min(N, st-j+arr[st-j]);
		}
		else{
			hops[st-j] = 1 + hops[st-j+arr[st-j]];
			nxt[st-j] = nxt[st-j+arr[st-j]];
		}
	}
}

void edgeUpdate(int i){
	for(int i = N-1; i >= i*sz; i--){
		if(i+arr[i] >= N){
			hops[i] = 1;
			nxt[i] = N;
		}else{
			hops[i] = 1+hops[i+arr[i]];
			nxt[i] = nxt[i+arr[i]];
		}
	}
}

int main(){
	scanf("%d", &N);
	for(int i= 0;i < N; i++) scanf("%d", arr+i);
	sz = (int) sqrt(N);
	int i;
	int last;
	for(i =0; i*sz < N; i++){
		update(i);
	}
	edgeUpdate(i);
	last = i;
	
	scanf("%d", &Q);
	int id;
	int a, b;
	for(;Q--;){
		scanf("%d", &id);
		if(id == 1){
			scanf("%d", &a);
			int ans = 0;
			for(int i = a; i < N; i = nxt[i]){
				ans += hops[i];
			}
			printf("%d\n", ans);
		}else{
			scanf("%d %d", &a, &b);
			arr[a] = b;
			int block = a/sz;
			if(block < last){
				update(block);
			}else{
				for(int i = N-1; i >= i*sz; i--){
					if(i+arr[i] >= N){
						hops[i] = 1;
						nxt[i] = N;
					}else{
						hops[i] = 1+hops[i+arr[i]];
						nxt[i] = nxt[i+arr[i]];
					}
				}
			}
		}
	}

	return 0;
}