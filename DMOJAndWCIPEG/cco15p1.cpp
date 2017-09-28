#include <bits/stdc++.h>
using namespace std;

int N;
long long W, T[100010];

int main(){
	scanf("%d %lld", &N, &W);
	//cout << N << ", " << W << endl;
	for(int i = 1; i <= N; i++) scanf("%lld", &T[i]);
	long long big = 0, small = 0;
	//T[N] = W;
	sort(T+1, T+N+1);
	T[0] = W;
	//printf("%d, ", T[0]); for(int i =1; i <= N; i++) printf("%d, ", T[i]); cout << endl;
	if(W < T[1]) small = abs(T[N]-W);
	else if(W > T[N]) small = abs(W-T[1]);
	else small = T[N] - T[1];
	//cout << small << endl;
	int ys = 1;
	long long diff;
	int l = N, r = 1;
	big = abs(W-T[1]);
	while( l != r){
		if(ys) diff = abs(W-T[l]);
		else diff = abs(W-T[r]);
		diff = max(diff, abs(1LL*T[l]-T[r]));
		//printf("%d %d: %lld\n", T[l], T[r], diff);
		big += diff;
		if(!ys) l--;
		else r++;
		ys = (ys+1)&1;
	}
	//cout << big << endl << endl;
	//big += max( abs(T[0]-T[N]), abs(T[0]-T[1]));
	long long oB = abs(W-T[N]);
	ys = 1;
	l = N, r = 1;
	while(l != r){
		if(ys) diff = abs(W-T[r]);
		else diff = abs(W-T[l]);
		diff = max(diff, abs(1LL*T[l]-T[r]));
		//printf("%d %d: %lld\n", T[l], T[r], diff);
		oB += diff;
		if(ys) l--;
		else r++;
		ys = (ys+1)&1;
	}
	//cout << oB << endl << endl;
	big = max(big, oB);
	//big += max(abs(W-T[N]), abs(W-T[1]));
	printf("%lld %lld\n", small, big);
	return 0;
}