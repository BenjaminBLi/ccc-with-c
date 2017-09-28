#include <bits/stdc++.h>
using namespace std;

int N, weights[4], cStu[4];

int main(){
	freopen("DATA11.txt", "r", stdin);

	int T = 10;
	for(;T--;){
		for(int i =0;i < 4; i++){
			scanf("%d", weights+i);
		}
		scanf("%d", &N);
		int cnt =0 ;
		for(;N--;){
			for(int i =0;i < 4; i++) scanf("%d", cStu+i);
			double total =0;
			for(int i =0;i < 4; i++) total += 1.0*cStu[i]*weights[i]/100;
			total += 1e-3;
			if(total >= 50) cnt++;
		}
		printf("%d\n", cnt);
	}

	return 0;
}