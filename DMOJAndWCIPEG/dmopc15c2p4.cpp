#include <bits/stdc++.h>
#define sz (int)2e5+10
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
int N;
long long memo[sz];
bool hasAnime[sz];
ll R[sz], L[sz], H[sz];

ll solve(int idx){
	if(idx >= N) return 0;
	if(memo[idx] != -1) return memo[idx];
	int nxt;
	int lo = idx+1, hi = N-1, mid;
	while(hi >= lo){
		mid = lo + (hi-lo)/2;
		if(R[mid] < R[idx]+L[idx]){
			lo = mid+1;
		}else{
			hi = mid-1;
		}
	}
	nxt = lo;
	if(nxt == N) return memo[idx] = max(solve(idx+1), H[idx]);
	return memo[idx] = max(memo[idx], max(solve(idx+1), solve(nxt)+H[idx]));
}

int main(){
	scanf("%d", &N);
	//int r, l, h;
	for(int i = 0; i < N; i++){
		scanf("%lld %lld %lld", R+i, L+i, H+i);
	}
	memset(memo, -1, sizeof(memo));
	printf("%lld\n", solve(0));
	return 0;
}