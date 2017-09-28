#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;
int N, Q;
ll x, y, zeroes[11][2], tmp[20], final[20];

ll gcd(ll a, ll b){
	if(b == 0) return a;
	return gcd(b, a%b);
}

ii calc(int deg){
	ll tX = 0;
	for(int i =0; i < deg; i++){
		tX += pow(x, i)*final[i];
	}
	ll g = gcd(y, tX);
	return ii(y/g, tX/g);
}

int main(){
	scanf("%d", &Q);
	for(;Q--;){
		scanf("%d", &N);
		for(int i =0; i < N; i++) zeroes[i][1] = 1;
		for(int i = 0; i < N; i++) {
			scanf("%lld", &zeroes[i][0]);
			zeroes[i][0] *= -1;
		}
		scanf("%lld %lld", &x, &y);
		//for(int i =0; i < N; i++) printf("(%lld, %lld)\n", zeroes[i][0], zeroes[i][1]);
		final[0] = zeroes[0][0]; final[1] = 1;
		int cSz = 2;
		//for(int i =0; i < 2; i++) printf("%lld ", final[i]); cout << endl;
		for(int z = 1; z < N; z++){
			//for(int i = N; i >= 0; i--) printf("%lld ", final[i]); cout << endl;
			//size of the degree.
			//arr will be i+1 size
			memset(tmp, 0, sizeof(tmp));
			for(int i = 0; i < cSz; i++){
				for(int j = 0; j < 2; j++){
					//printf("%d: %lld and %d: %lld\n", i, final[i], j, zeroes[z][j]);
					tmp[i+j] += final[i]*zeroes[z][j];
					//cout << tmp[i+j] << endl;
				}
			}
			cSz++;
			for(int i =0; i < cSz; i++) final[i] = tmp[i];
			
			//for(int i = N; i >= 0; i--) printf("%lld ", final[i]); cout << endl;
		}
		ii coeff = calc(cSz);
		for(int i = N; i >= 0; i--) {
			if(i != N) printf(" ");
			printf("%lld", (coeff.first/coeff.second)*(final[i]/coeff.second));
		}
		cout << endl;
	}

	return 0;
}