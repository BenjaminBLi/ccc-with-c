#include <bits/stdc++.h>
using namespace std;

int max = 100*100;
int N, weights[4], cStu[4];

int main(){
	int T = 10;
	for(;T--;){
		//cout << T << endl;
		scanf("%d %d %d %d", &weights[0], &weights[1], &weights[2], &weights[3]);
		scanf("%d", &N);

		int cnt = 0;
		for(;N--;){
			scanf("%d %d %d %d", &cStu[0], &cStu[1], &cStu[2], &cStu[3]);
			double curr = 0;
			for(int i =0;i < 4; i++){
				curr += cStu[i]*weights[i]*1.0/100;
			}
			if(curr+1e-9 >= 50.0) cnt++;
		}
		printf("%d\n", cnt);
	}
	return 0;
}