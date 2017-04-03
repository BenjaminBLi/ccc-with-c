#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
int K, D, sa, sb, pa, pb;
bool prime[10000];

void gen(){
	memset(prime, true, sizeof(prime));
	prime[0] = prime[1] = false;
	for(int i = 2; i*i < 10000; i++){
		if(prime[i]){
			for(int j = i*i; j < 10000; j+=i){
				prime[j] = false;
			}
		}
	}
}

bool isPrime(int n){
	return prime[n];
}

int main(){
	scanf("%d %d", &K, &D);
	scanf("%d %d %d %d", &sa, &sb, &pa, &pb);
	gen();
	int ca = pa, cb = pb;
	if(abs(ca-cb) < D || abs(ca-cb+K) < D){
		if(ca >= cb) cb = (ca-D+K)%K;
		else cb = (ca+D)%K;
	}
	//cout << prime[2] << endl;
	ca += sa, cb += sb;
	ca %= K, cb %= K;
	bool ok = false;
	int tDist, turns = 0;
	while(turns++ < 1000000){
		if(abs(ca-cb) < D || abs(ca-cb+K) < D){
			if(ca >= cb) cb = (ca-D+K)%K;
			else cb = (ca+D)%K;
		}
		tDist = min(abs(K-ca), ca) + min(abs(K-cb), cb);
		if(isPrime(tDist)){
			ok = true;
			break;
		}
		ca += sa; cb += sb;
		ca %= K, cb %= K;
	}
	if(!ok){
		printf("Bob\n");
	}else printf("Alice\n");

	return 0;
}