#include <bits/stdc++.h>
#define sz (int)1e7
using namespace std;

int N;
bool prime[sz+10];
set<int> primes;

void gen(){
	memset(prime, true, sizeof(prime));
	prime[0] = false, prime[1] = false;
	for(int i = 2; i*i < (int)1e7; i++){
		if(prime[i]){
			for(int j = i*i; j < sz; j+=i){
				prime[j] = false;
			}
		}
	}
}

int main(){
	gen();
	int T = 5;
	for(;T--;){
		scanf("%d", &N);
		printf("%d = ", N);
		if(prime[N]){
			printf("%d", N);
		}else{
			//?????
		}
		printf("\n");
	}
	return 0;
}