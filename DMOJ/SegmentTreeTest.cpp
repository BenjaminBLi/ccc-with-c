#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
int n;
int h = sizeof(int)*8 - __builtin_clz(n);
int freq[N], aGcd[2*N+1], rMinQ[2*N+1];
int sum[2*N+1];

//start of regular seg tree
int gcd(int a, int b){
	if(b == 0) return a;
	return gcd(b, a%b);
}

void build(){
	for(int i = n-1; i > 0; i--) {
		rMinQ[i] = min(rMinQ[i<<1], rMinQ[i<<1|1]);
		aGcd[i] = gcd(aGcd[i<<1], aGcd[i<<1|1]);
		if(aGcd[i] == aGcd[i<<1])   freq[i] += freq[i<<1];
		if(aGcd[i] == aGcd[i<<1|1]) freq[i] += freq[i<<1|1];
	}
}

void modify(int p, int val){
	for(rMinQ[p += n] = val, aGcd[p] = val; p > 1; p >>= 1) {
		rMinQ[p>>1] = min(rMinQ[p], rMinQ[p^1]);
		aGcd[p>>1] = gcd(aGcd[p], aGcd[p^1]);
		freq[p>>1] = 0;
		if(aGcd[p>>1] == aGcd[p]) freq[p>>1] += freq[p];
		if(aGcd[p^1] == aGcd[p>>1]) freq[p>>1] += freq[p^1];
	}
}


int rmqQuery(int l, int r){
	l += n, r+=n;
	int res = 2e9;
	for(; l < r; l >>= 1, r>>=1){
		if(l&1) res = min(res, rMinQ[l++]);
		if(r&1) res = min(res, rMinQ[--r]);
	}
	return res;
}

int gcdQuery(int l, int r){
	l += n, r += n;
	int res = aGcd[l];
	for(; l < r; l >>= 1, r>>= 1){
		if(l&1) res = gcd(res, aGcd[l++]);
		if(r&1) res = gcd(res, aGcd[--r]);
	}
	return res;
}
int freqQuery(int l, int r, int check){
	//int check = gcdQuery(l, r);
	l += n, r += n;
	int res = 0;
	//cout << check << endl;
	for(; l < r; l >>= 1, r >>= 1){
		//printf("l: %d ", l);
		if((l&1) && check == aGcd[l]) res += freq[l++];
		if((r&1) && check == aGcd[--r]) res += freq[r];
	}
	//cout << endl;
	return res;
}
//end of regular seg tree
int M, a, b;
char ch;
int main(){
	scanf("%d %d", &n, &M);
	for(int i =0; i < n; i++) {
		scanf("%d", rMinQ+n+i);
		aGcd[n+i] = rMinQ[n+i];
		freq[n+i] = 1;
	}
	build();
	//bool flag;
	for(int m = 1; m <= M; m++){
		//cout << "m: " << m << endl;
		getchar(); ch = getchar();
		scanf("%d %d", &a, &b);
		a--;
		//flag |= ch == 'C';
		if(ch == 'C') modify(a, b);
		if(ch == 'M') printf("%d\n",rmqQuery(a, b));
		if(ch == 'G') printf("%d\n", gcdQuery(a, b));
		if(ch == 'Q') {
			printf("%d\n", freqQuery(a, b,gcdQuery(a, b)));
		}
	}
}