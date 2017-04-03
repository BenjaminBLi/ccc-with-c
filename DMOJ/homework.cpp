#include <bits/stdc++.h>
using namespace std;

int N, MAXN = (int) 1e7, T, A, K, B, primacity[(int) 1e7+1];
bool prime[(int) 1e7+1];

void sieve(){
	int s = 1;
	prime[0] = true; prime[1] = true;
	primacity[0] = 1; primacity[1] = 1;
	for(int i = 2; i <= MAXN; i++){
		//printf("i: %d\n", i);
		if(primacity[i] == 0){
			//printf("j: %d\n", i);
			primacity[i]++;
			for(int j = i+i; j <= MAXN; j += i){
				//printf(" %d, ", j);
				//prime[j] = true;
				primacity[j]++;
			}
			
		}
	}
}

int main(){
	//cout << MAXN << endl;
	sieve();
	scanf("%d", &T); T++;
	long long cnt;
	//for(int i = 1; i <= 15; i++) printf("%d: %d\n", i, primacity[i]);
	for(int t = 1; t < T; t++){
		scanf("%d %d %d", &A, &B, &K);
		cnt = 0;
		for(int i = A; i <= B; i++){
			if (primacity[i] == K) cnt++;	
		}
		printf("Case #%d: %lld\n", t, cnt);
	}
	//cout << primacity[2] << endl;
}