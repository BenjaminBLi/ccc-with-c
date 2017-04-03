#include <bits/stdc++.h>
using namespace std;

long long Q, N, F, D, id;

int main(){
	scanf("%lld", &Q);
	
	for(;Q--;){
		scanf("%lld %lld", &id, &N);
		//cout << "ID STUFF" << endl;
		if(id == 1){
			scanf("%lld", &F);

			//double tmp = ceil(pow(N, 1.0/F)-1-1e-9);
			long long ans = (long long) (ceil(pow((double)N, 1.0/F)-1e-9) - 1);
			printf("%lld\n", ans);
		}else{
			scanf("%lld\n", &D);
			F = 0;
			long long ans = 1;
			while(ans < N){
				F++;
				ans *= (D+1);
			}
			printf("%lld\n", F); 
		}
	}

	return 0;
}